/*
 * Copyright (C) 2001-2006  Terence M. Welsh
 *
 * This file is part of Implicit.
 *
 * Implicit is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Implicit is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#include <Implicit/impCubeVolume.h>
#include <rsMath/rsMath.h>
#include <iostream>



impCubeVolume::impCubeVolume(){
	int i, j;
	impCubeTables cubeTables;
	for(i=0; i<256; ++i){
		for(j=0; j<17; ++j)
			triStripPatterns[i][j] = cubeTables.triStripPatterns[i][j];
		for(j=0; j<6; ++j)
			crawlDirections[i][j] = cubeTables.crawlDirections[i][j];
	}

	surface = new impSurface;
	init(4, 4, 4, 0.2f);
	surfacevalue = 0.5f;

	fastnormals = true;
	crawlfromsides = false;
}


impCubeVolume::~impCubeVolume(){
	cubes.clear();
	cubeIndices.clear();
	sortableCubes.clear();
}


void impCubeVolume::init(unsigned int width, unsigned int height, unsigned int length, float cw){
	unsigned int i, j, k;
    
	cubes.clear();

	// frequently used values
	w = width;
	w_1 = width + 1;
	h = height;
	h_1 = height + 1;
	l = length;
	l_1 = length + 1;
	w_1xh_1 = w_1 * h_1;
	w_1xh_1xl_1 = w_1 * h_1 * l_1;

	// calculate position of left-bottom-front corner
	cubewidth = cw;
	lbf[0] = -float(w) * cubewidth * 0.5f;
	lbf[1] = -float(h) * cubewidth * 0.5f;
	lbf[2] = -float(l) * cubewidth * 0.5f;

	// allocate cubedata memory and set cube positions
	cubes.resize(w_1xh_1xl_1);
	for(i=0; i<w_1; ++i){
		for(j=0; j<h_1; ++j){
			for(k=0; k<l_1; ++k){
				const unsigned int index(cubeindex(i,j,k));
				cubes[index].x = lbf[0] + (cubewidth * float(i));
				cubes[index].y = lbf[1] + (cubewidth * float(j));
				cubes[index].z = lbf[2] + (cubewidth * float(k));
#ifdef __SSE__
				cubes[index].w = 1.0f;
#endif
				cubes[index].cube_frame = 0;
				cubes[index].corner_frame = 0;
				cubes[index].x_vertex_frame = 0;
				cubes[index].y_vertex_frame = 0;
				cubes[index].z_vertex_frame = 0;
			}
		}
	}
}


void impCubeVolume::makeSurface(){
	unsigned int i, j, k;

	frame ++;

	surface->reset();
	
	// find gradient value at every corner
	for(i=0; i<=w; ++i){
		for(j=0; j<=h; ++j){
			for(k=0; k<=l; ++k){
				const unsigned int ci(cubeindex(i,j,k));
				cubes[ci].value = function(&(cubes[ci].x));
			}
		}
	}

	// polygonize surface
	currentVertexIndex = 0;
	for(i=0; i<w; ++i){
		for(j=0; j<h; ++j){
			for(k=0; k<l; ++k){
				const unsigned int ci(cubeindex(i,j,k));
				cubes[ci].mask = calculateCornerMask(i, j, k);
				polygonize(ci);
			}
		}
	}
}


void impCubeVolume::makeSurface(float eyex, float eyey, float eyez){
	unsigned int i, j, k;

	frame ++;

	surface->reset();

	// find gradient value at every corner
	for(i=0; i<=w; ++i){
		for(j=0; j<=h; ++j){
			for(k=0; k<=l; ++k){
				const unsigned int ci(cubeindex(i,j,k));
				cubes[ci].value = function(&(cubes[ci].x));
			}
		}
	}

	// erase list from last frame
	sortableCubes.clear();

	// collect list of cubes
	sortableCube* sc;
	unsigned int mask;
	for(i=0; i<w; ++i){
		for(j=0; j<h; ++j){
			for(k=0; k<l; ++k){
				const unsigned int ci(cubeindex(i,j,k));
				mask = calculateCornerMask(i, j, k);
				if(mask != 0 && mask != 255){
					cubes[ci].mask = mask;
					sortableCubes.push_back(sortableCube(ci));
					sc = &(sortableCubes.back());
					const float xdist(cubes[ci].x - eyex);
					const float ydist(cubes[ci].y - eyey);
					const float zdist(cubes[ci].z - eyez);
					sc->depth = xdist * xdist + ydist * ydist + zdist * zdist;
				}
			}
		}
	}

	// sort list of cubes
	sortableCubes.sort();

	// polygonize
	currentVertexIndex = 0;
	for(std::list<sortableCube>::iterator c = sortableCubes.begin(); c != sortableCubes.end(); ++c)
		polygonize(c->index);
}


void impCubeVolume::makeSurface(impCrawlPointVector &cpv){
	unsigned int i, j, k;
	bool crawlpointexit;
	unsigned int mask;

	frame ++;

	surface->reset();

	currentCubeIndex = 0;

	// crawl from every crawl point to create the surface
	for(unsigned int cp=0; cp<cpv.size(); ++cp){
		// find cube corresponding to crawl point
		i = int((cpv[cp].position[0] - lbf[0]) / cubewidth);
		if(i < 0)
			i = 0;
		if(i >= int(w))
			i = int(w) - 1;
		j = int((cpv[cp].position[1] - lbf[1]) / cubewidth);
		if(j < 0)
			j = 0;
		if(j >= int(h))
			j = int(h) - 1;
		k = int((cpv[cp].position[2] - lbf[2]) / cubewidth);
		if(k < 0)
			k = 0;
		if(k >= int(l))
			k = int(l) - 1;

		// escape if starting on a finished cube
		crawlpointexit = 0;
		while(!crawlpointexit){
			const unsigned int ci(cubeindex(i,j,k));
			if(cubes[ci].cube_frame == frame)
				crawlpointexit = 1;  // escape if starting on a finished cube
			else{  // find index for this cube
				findcornervalues(i, j, k);
				mask = calculateCornerMask(i, j, k);
				// save index for uncrawling
				cubes[ci].mask = mask;
				if(mask == 255)  // escape if outside surface
					crawlpointexit = 1;
				else{
					if(mask == 0){  // this cube is inside volume
						cubes[ci].cube_frame = frame;
						++i;  // step to an adjacent cube and start over
						if(i >= w)  // escape if you step outside of volume
							crawlpointexit = 1;
					}
					else{
						crawl_nosort(i, j, k);
						crawlpointexit = 1;
					}
				}
			}
		}
	}

	if(crawlfromsides){
		for(j=0; j<h; ++j){
			for(i=0; i<w; ++i){
				attempt_crawl_nosort(i, j, 0);
				attempt_crawl_nosort(i, j, l-1);
			}
		}
		for(k=1; k<l-1; ++k){
			for(i=0; i<w; ++i){
				attempt_crawl_nosort(i, 0, k);
				attempt_crawl_nosort(i, h-1, k);
			}
		}
		for(k=1; k<l-1; ++k){
			for(j=1; j<h-1; ++j){
				attempt_crawl_nosort(0, j, k);
				attempt_crawl_nosort(w-1, j, k);
			}
		}
	}

	// polygonize
	currentVertexIndex = 0;
	for(unsigned int c=0; c<currentCubeIndex; ++c)
		polygonize(cubeIndices[c]);
}


void impCubeVolume::makeSurface(float eyex, float eyey, float eyez, impCrawlPointVector &cpv){
	int i, j, k;
	bool crawlpointexit;
	unsigned int mask;

	frame ++;

	surface->reset();

	// erase list from last frame
	sortableCubes.clear();

	// crawl from every crawl point to create the surface
	for(unsigned int cp=0; cp<cpv.size(); ++cp){
		// find cube corresponding to crawl point
		i = int((cpv[cp].position[0] - lbf[0]) / cubewidth);
		if(i < 0)
			i = 0;
		if(i >= int(w))
			i = int(w) - 1;
		j = int((cpv[cp].position[1] - lbf[1]) / cubewidth);
		if(j < 0)
			j = 0;
		if(j >= int(h))
			j = int(h) - 1;
		k = int((cpv[cp].position[2] - lbf[2]) / cubewidth);
		if(k < 0)
			k = 0;
		if(k >= int(l))
			k = int(l) - 1;

		// escape if starting on a finished cube
		crawlpointexit = 0;
		while(!crawlpointexit){
			const unsigned int ci(cubeindex(i,j,k));
			if(cubes[ci].cube_frame == frame)
				crawlpointexit = 1;  // escape if starting on a finished cube
			else{  // find index for this cube
				findcornervalues(i, j, k);
				mask = calculateCornerMask(i, j, k);
				// save index for uncrawling
				cubes[ci].mask = mask;
				if(mask == 255)  // escape if outside surface
					crawlpointexit = 1;
				else{
					if(mask == 0){  // this cube is inside volume
						cubes[ci].cube_frame = frame;
						--i;  // step to an adjacent cube and start over
						if(i < 0)  // escape if you step outside of volume
							crawlpointexit = 1;
					}
					else{
						crawl_sort(i, j, k);
						crawlpointexit = 1;
					}
				}
			}
		}
	}

	if(crawlfromsides){
		for(j=0; j<h; ++j){
			for(i=0; i<w; ++i){
				attempt_crawl_sort(i, j, 0);
				attempt_crawl_sort(i, j, l-1);
			}
		}
		for(k=1; k<l-1; ++k){
			for(i=0; i<w; ++i){
				attempt_crawl_sort(i, 0, k);
				attempt_crawl_sort(i, h-1, k);
			}
		}
		for(k=1; k<l-1; ++k){
			for(j=1; j<h-1; ++j){
				attempt_crawl_sort(0, j, k);
				attempt_crawl_sort(w-1, j, k);
			}
		}
	}

	// find depths of cubes for sorting
	for(std::list<sortableCube>::iterator c = sortableCubes.begin(); c != sortableCubes.end(); ++c){
		const unsigned int ci(c->index);
		const float xdist(cubes[ci].x - eyex);
		const float ydist(cubes[ci].y - eyey);
		const float zdist(cubes[ci].z - eyez);
		c->depth = xdist * xdist + ydist * ydist + zdist * zdist;
	}

	// sort list of cubes
	sortableCubes.sort();

	// polygonize
	currentVertexIndex = 0;
	for(std::list<sortableCube>::iterator c = sortableCubes.begin(); c != sortableCubes.end(); ++c)
		polygonize(c->index);
}


// calculate index into cubetable
const unsigned int impCubeVolume::calculateCornerMask(const unsigned int& x, const unsigned int& y, const unsigned int& z){
	const unsigned int index(cubeindex(x,y,z));
	return ((cubes[index].value < surfacevalue) ? LBF : 0)
		+ ((cubes[index+1].value < surfacevalue) ? RBF : 0)
		+ ((cubes[index+w_1].value < surfacevalue) ? LTF : 0)
		+ ((cubes[index+1+w_1].value < surfacevalue) ? RTF : 0)
		+ ((cubes[index+w_1xh_1].value < surfacevalue) ? LBN : 0)
		+ ((cubes[index+1+w_1xh_1].value < surfacevalue) ? RBN : 0)
		+ ((cubes[index+w_1+w_1xh_1].value < surfacevalue) ? LTN : 0)
		+ ((cubes[index+1+w_1+w_1xh_1].value < surfacevalue) ? RTN : 0);
}


void impCubeVolume::attempt_crawl_nosort(unsigned int x, unsigned int y, unsigned int z){
	const unsigned int ci(cubeindex(x, y, z));
	if(cubes[ci].cube_frame == frame)
		return;

	findcornervalues(x, y, z);
	unsigned int mask(calculateCornerMask(x, y, z));

	if(mask == 255)  // escape if outside surface
		return;
	if(mask == 0)
		return;

	crawl_nosort(x, y, z);
}


void impCubeVolume::crawl_nosort(unsigned int x, unsigned int y, unsigned int z){
	findcornervalues(x, y, z);
	const unsigned int mask(calculateCornerMask(x, y, z));

	// quit if this cube has been done or does not intersect surface
	const unsigned int ci(cubeindex(x,y,z));
	cubedata& cube(cubes[ci]);
	if(cube.cube_frame == frame)
		return;

	// add this cube to list of crawled cubes, resizing vector if necessary
	const size_t tslsize(cubeIndices.size());
	if(currentCubeIndex == tslsize)
		cubeIndices.resize(tslsize + 1000);
	cubeIndices[currentCubeIndex++] = ci;

	// save index for polygonizing and uncrawling
	cube.mask = mask;

	// mark this cube as completed
	cube.cube_frame = frame;

	// crawl to adjacent cubes
	if(crawlDirections[mask][0] && x > 0)
		crawl_nosort(x-1, y, z);
	if(crawlDirections[mask][1] && x < w-1)
		crawl_nosort(x+1, y, z);
	if(crawlDirections[mask][2] && y > 0)
		crawl_nosort(x, y-1, z);
	if(crawlDirections[mask][3] && y < h-1)
		crawl_nosort(x, y+1, z);
	if(crawlDirections[mask][4] && z > 0)
		crawl_nosort(x, y, z-1);
	if(crawlDirections[mask][5] && z < l-1)
		crawl_nosort(x, y, z+1);
}


void impCubeVolume::attempt_crawl_sort(unsigned int x, unsigned int y, unsigned int z){
	const unsigned int ci(cubeindex(x, y, z));
	if(cubes[ci].cube_frame == frame)
		return;

	findcornervalues(x, y, z);
	const unsigned int mask(calculateCornerMask(x, y, z));

	if(mask == 255)  // escape if outside surface
		return;
	if(mask == 0)
		return;

	crawl_sort(x, y, z);
}


void impCubeVolume::crawl_sort(unsigned int x, unsigned int y, unsigned int z){
	findcornervalues(x, y, z);
	const int mask(calculateCornerMask(x, y, z));

	// quit if this cube has been done or does not intersect surface
	const unsigned int ci(cubeindex(x,y,z));
	cubedata& cube(cubes[ci]);
	if(cube.cube_frame == frame)
		return;

	// add cube to list
	sortableCubes.push_back(sortableCube(ci));

	// save index for uncrawling
	cube.mask = mask;

	// mark this cube as completed
	cube.cube_frame = frame;

	// crawl to adjacent cubes
	if(crawlDirections[mask][0] && x > 0)
		crawl_sort(x-1, y, z);
	if(crawlDirections[mask][1] && x < w-1)
		crawl_sort(x+1, y, z);
	if(crawlDirections[mask][2] && y > 0)
		crawl_sort(x, y-1, z);
	if(crawlDirections[mask][3] && y < h-1)
		crawl_sort(x, y+1, z);
	if(crawlDirections[mask][4] && z > 0)
		crawl_sort(x, y, z-1);
	if(crawlDirections[mask][5] && z < l-1)
		crawl_sort(x, y, z+1);
}


// polygonize an individual cube
void impCubeVolume::polygonize(unsigned int index){
	// find index into cubetable
	const unsigned int mask(cubes[index].mask);

	unsigned int counter = 0;
	unsigned int nedges = triStripPatterns[mask][counter];
	while(nedges != 0){
		surface->addTriStripLength(nedges);
		for(unsigned int i=0; i<nedges; ++i){
			// generate vertex position and normal data
			switch(triStripPatterns[mask][i+counter+1]){
			case 0:
				addVertexToSurface(2, index);
				break;
			case 1:
				addVertexToSurface(1, index);
				break;
			case 2:
				addVertexToSurface(1, index + w_1xh_1);
				break;
			case 3:
				addVertexToSurface(2, index + w_1);
				break;
			case 4:
				addVertexToSurface(0, index);
				break;
			case 5:
				addVertexToSurface(0, index + w_1xh_1);
				break;
			case 6:
				addVertexToSurface(0, index + w_1);
				break;
			case 7:
				addVertexToSurface(0, index + w_1 + w_1xh_1);
				break;
			case 8:
				addVertexToSurface(2, index + 1);
				break;
			case 9:
				addVertexToSurface(1, index + 1);
				break;
			case 10:
				addVertexToSurface(1, index + 1 + w_1xh_1);
				break;
			case 11:
				addVertexToSurface(2, index + 1 + w_1);
				break;
			}
		}
		counter += (nedges + 1);
		nedges = triStripPatterns[mask][counter];
	}
}


// find value at all corners of this cube
void impCubeVolume::findcornervalues(unsigned int x, unsigned int y, unsigned int z){
	{
		cubedata& cube(cubes[cubeindex(x,y,z)]);
		if(cube.corner_frame != frame){
			cube.corner_frame = frame;
			cube.value = function(&(cube.x));
		}
	}
	{
		cubedata& cube(cubes[cubeindex(x+1,y,z)]);
		if(cube.corner_frame != frame){
			cube.corner_frame = frame;
			cube.value = function(&(cube.x));
		}
	}
	{
		cubedata& cube(cubes[cubeindex(x,y+1,z)]);
		if(cube.corner_frame != frame){
			cube.corner_frame = frame;
			cube.value = function(&(cube.x));
		}
	}
	{
		cubedata& cube(cubes[cubeindex(x+1,y+1,z)]);
		if(cube.corner_frame != frame){
			cube.corner_frame = frame;
			cube.value = function(&(cube.x));
		}
	}
	{
		cubedata& cube(cubes[cubeindex(x,y,z+1)]);
		if(cube.corner_frame != frame){
			cube.corner_frame = frame;
			cube.value = function(&(cube.x));
		}
	}
	{
		cubedata& cube(cubes[cubeindex(x+1,y,z+1)]);
		if(cube.corner_frame != frame){
			cube.corner_frame = frame;
			cube.value = function(&(cube.x));
		}
	}
	{
		cubedata& cube(cubes[cubeindex(x,y+1,z+1)]);
		if(cube.corner_frame != frame){
			cube.corner_frame = frame;
			cube.value = function(&(cube.x));
		}
	}
	{
		cubedata& cube(cubes[cubeindex(x+1,y+1,z+1)]);
		if(cube.corner_frame != frame){
			cube.corner_frame = frame;
			cube.value = function(&(cube.x));
		}
	}
}


float impCubeVolume::getXPlus1Value(unsigned int index){
	const unsigned int indexPlus1(index + 1);

	// compute new value if index is at the edge of the volume
	if((indexPlus1 % w_1) == 0){
		float* pos = &(cubes[index].x);
		pos[0] += cubewidth;
		const float value(function(pos));
		pos[0] -= cubewidth;
		return value;
	}

	// return already computed value
	if(cubes[indexPlus1].corner_frame == frame)
		return cubes[indexPlus1].value;

	// compute new value
	cubes[indexPlus1].corner_frame = frame;
	return function(&(cubes[indexPlus1].x));
}


float impCubeVolume::getYPlus1Value(unsigned int index){
	const unsigned int indexPlus1(index + w_1);

	// compute new value if index is at the edge of the volume
	if(((indexPlus1 / w_1) % h_1) == 0){
		float* pos = &(cubes[index].x);
		pos[1] += cubewidth;
		const float value(function(pos));
		pos[1] -= cubewidth;
		return value;
	}

	// return already computed value
	if(cubes[indexPlus1].corner_frame == frame)
		return cubes[indexPlus1].value;

	// compute new value
	cubes[indexPlus1].corner_frame = frame;
	return function(&(cubes[indexPlus1].x));
}


float impCubeVolume::getZPlus1Value(unsigned int index){
	const unsigned int indexPlus1(index + w_1xh_1);

	// compute new value if index is at the edge of the volume
	if(indexPlus1 >= w_1xh_1 * l){
		float* pos = &(cubes[index].x);
		pos[2] += cubewidth;
		const float value(function(pos));
		pos[2] -= cubewidth;
		return value;
	}

	// return already computed value
	if(cubes[indexPlus1].corner_frame == frame)
		return cubes[indexPlus1].value;

	// compute new value
	cubes[indexPlus1].corner_frame = frame;
	return function(&(cubes[indexPlus1].x));
}


/*float impCubeVolume::getXPlus1Value(unsigned int index){
	const unsigned int indexPlus1(index + 1);

	// return already computed value
	if(cubes[indexPlus1].corner_done)
		return cubes[indexPlus1].value;

	// compute new value
	return function(&(cubes[indexPlus1].x));
}


float impCubeVolume::getYPlus1Value(unsigned int index){
	const unsigned int indexPlus1(index + w_1);

	// return already computed value
	if(cubes[indexPlus1].corner_done)
		return cubes[indexPlus1].value;

	// compute new value
	return function(&(cubes[indexPlus1].x));
}


float impCubeVolume::getZPlus1Value(unsigned int index){
	const unsigned int indexPlus1(index + w_1xh_1);

	// return already computed value
	if(cubes[indexPlus1].corner_done)
		return cubes[indexPlus1].value;

	// compute new value
	return function(&(cubes[indexPlus1].x));
}


float impCubeVolume::getXMinus1Value(unsigned int index){
	const unsigned int indexMinus1(index - 1);

	// return already computed value
	if(cubes[indexMinus1].corner_done)
		return cubes[indexMinus1].value;

	// compute new value
	return function(&(cubes[indexMinus1].x));
}


float impCubeVolume::getYMinus1Value(unsigned int index){
	const unsigned int indexMinus1(index - w_1);

	// return already computed value
	if(cubes[indexMinus1].corner_done)
		return cubes[indexMinus1].value;

	// compute new value
	return function(&(cubes[indexMinus1].x));
}


float impCubeVolume::getZMinus1Value(unsigned int index){
	const unsigned int indexMinus1(index - w_1xh_1);

	// return already computed value
	if(cubes[indexMinus1].corner_done)
		return cubes[indexMinus1].value;

	// compute new value
	return function(&(cubes[indexMinus1].x));
}*/


void impCubeVolume::addVertexToSurface(const unsigned int& axis, const unsigned int& index){
	float data[6];

	// find position of vertex along this edge
	switch(axis){
		case 0:{  // x-axis
			if(cubes[index].x_vertex_frame == frame){
				// Position and normal have already been computed for this edge.
				surface->addIndex(cubes[index].x_vertex_index);
				return;
			}
			cubes[index].x_vertex_frame = frame;
			surface->addIndex(currentVertexIndex);
			cubes[index].x_vertex_index = currentVertexIndex;
			currentVertexIndex ++;
			const float t((surfacevalue - cubes[index].value) / (cubes[index+1].value - cubes[index].value));
			data[3] = cubes[index].x + (cubewidth * t);
			data[4] = cubes[index].y;
			data[5] = cubes[index].z;
			if(fastnormals){
				// compute normal
				const float one_minus_t(1.0f - t);
				data[0] = one_minus_t * (cubes[index].value - cubes[index+1].value) + t * (cubes[index+1].value - getXPlus1Value(index+1));
				data[1] = one_minus_t * (cubes[index].value - getYPlus1Value(index)) + t * (cubes[index+1].value - getYPlus1Value(index+1));
				data[2] = one_minus_t * (cubes[index].value - getZPlus1Value(index)) + t * (cubes[index+1].value - getZPlus1Value(index+1));
				/*if(t < 0.5f){
					if(index % w_1){
						const float tt(t + 0.5f);
						data[0] = tt * (cubes[index].value - cubes[index+1].value) + (1.0f - tt) * (getXMinus1Value(index) - cubes[index].value);
					}
					else
						data[0] = cubes[index].value - cubes[index+1].value;
				}
				else{
					if((index + 2) % w_1){
						const float tt(t - 0.5f);
						data[0] = (1.0f - tt) * (cubes[index].value - cubes[index+1].value) + tt * (cubes[index+1].value - getXPlus1Value(index+1));
					}
					else
						data[0] = cubes[index].value - cubes[index+1].value;
				}
				if((index / w_1) % h_1 == 0)
					data[1] = one_minus_t * (cubes[index].value - getYPlus1Value(index)) + t * (cubes[index+1].value - getYPlus1Value(index+1));
				else if(((index + w_1 + w_1) / w_1) % h_1 == 0)
					data[1] = one_minus_t * (getYMinus1Value(index) - cubes[index].value) + t * (getYMinus1Value(index) - cubes[index+1].value);
				else
					data[1] = (one_minus_t * (getYMinus1Value(index) - getYPlus1Value(index)) + t * (getYMinus1Value(index+1) - getYPlus1Value(index+1))) * 0.5f;
				if(index < w_1xh_1)
					data[2] = one_minus_t * (cubes[index].value - getZPlus1Value(index)) + t * (cubes[index+1].value - getZPlus1Value(index+1));
				else if(index >= (w_1xh_1 * (l - 1)))
					data[2] = one_minus_t * (getZMinus1Value(index) - cubes[index].value) + t * (getZMinus1Value(index+1) - cubes[index+1].value);
				else
					data[2] = (one_minus_t * (getZMinus1Value(index) - getZPlus1Value(index)) + t * (getZMinus1Value(index+1) - getZPlus1Value(index+1))) * 0.5f;*/
				// For speed, do not normalize; use GL_NORMALIZE instead
				// Add this vertex to surface
				surface->addVertex(data);
				return;
			}
			break;
		}
		case 1:{  // y-axis
			if(cubes[index].y_vertex_frame == frame){
				// Position and normal have already been computed for this edge.
				surface->addIndex(cubes[index].y_vertex_index);
				return;
			}
			cubes[index].y_vertex_frame = frame;
			surface->addIndex(currentVertexIndex);
			cubes[index].y_vertex_index = currentVertexIndex;
			currentVertexIndex ++;
			const float t((surfacevalue - cubes[index].value) / (cubes[index+w_1].value - cubes[index].value));
			data[3] = cubes[index].x;
			data[4] = cubes[index].y + (cubewidth * t);
			data[5] = cubes[index].z;
			if(fastnormals){
				// compute normal
				const float one_minus_t(1.0f - t);
				data[0] = one_minus_t * (cubes[index].value - getXPlus1Value(index)) + t * (cubes[index+w_1].value - getXPlus1Value(index+w_1));
				data[1] = one_minus_t * (cubes[index].value - cubes[index+w_1].value) + t * (cubes[index+w_1].value - getYPlus1Value(index+w_1));
				data[2] = one_minus_t * (cubes[index].value - getZPlus1Value(index)) + t * (cubes[index+w_1].value - getZPlus1Value(index+w_1));
				// For speed, do not normalize; use GL_NORMALIZE instead
				// Add this vertex to surface
				surface->addVertex(data);
				return;
			}
			break;
		}
		case 2:{  // z-axis
			if(cubes[index].z_vertex_frame == frame){
				// Position and normal have already been computed for this edge.
				surface->addIndex(cubes[index].z_vertex_index);
				return;
			}
			cubes[index].z_vertex_frame = frame;
			surface->addIndex(currentVertexIndex);
			cubes[index].z_vertex_index = currentVertexIndex;
			currentVertexIndex ++;
			const float t((surfacevalue - cubes[index].value) / (cubes[index+w_1xh_1].value - cubes[index].value));
			data[3] = cubes[index].x;
			data[4] = cubes[index].y;
			data[5] = cubes[index].z + (cubewidth * t);
			if(fastnormals){
				// compute normal
				const float one_minus_t(1.0f - t);
				data[0] = one_minus_t * (cubes[index].value - getXPlus1Value(index)) + t * (cubes[index+w_1xh_1].value - getXPlus1Value(index+w_1xh_1));
				data[1] = one_minus_t * (cubes[index].value - getYPlus1Value(index)) + t * (cubes[index+w_1xh_1].value - getYPlus1Value(index+w_1xh_1));
				data[2] = one_minus_t * (cubes[index].value - cubes[index+w_1xh_1].value) + t * (cubes[index+w_1xh_1].value - getZPlus1Value(index+w_1xh_1));
				// For speed, do not normalize; use GL_NORMALIZE instead
				// Add this vertex to surface
				surface->addVertex(data);
				return;
			}
			break;
		}
	}

	// Find normal vector at vertex along this edge
	// First find normal vector origin value
	float* pos = &(data[3]);
	const float offset(cubewidth * 0.01f);
	const float val(function(pos));
	// then find values at slight displacements and subtract
	pos[0] -= offset;
	data[0] = function(pos) - val;
	pos[0] += offset;
	pos[1] -= offset;
	data[1] = function(pos) - val;
	pos[1] += offset;
	pos[2] -= offset;
	data[2] = function(pos) - val;
	pos[2] += offset;
	// For speed, do not normalize; use GL_NORMALIZE instead

	// Add this vertex to surface
	surface->addVertex(data);
}
