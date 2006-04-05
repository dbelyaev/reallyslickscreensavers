/*
 * Copyright (C) 2001-2006  Terence M. Welsh
 *
 * This file is part of Implicit.
 *
 * Implicit is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation.
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


#ifndef IMPSURFACE_H
#define IMPSURFACE_H


#ifdef WIN32
	#include <windows.h>
#endif
#include <vector>
#include <GL/gl.h>


class impSurface{
public:
	impSurface(){}
	~impSurface();

	// Set data counts to 0
	void reset();

	// Add data to surface
	void addTriStripLength(unsigned char length);
	void addIndex(unsigned int index);
	void addVertex(float* data);  // provide array of 6 floats (normal, position)
	
	// Compute normals from triangle data
	// This is fast, but not quite as fast as the fast normals in
	// impCubeVolume, and it also looks a lot worse.  Therefore, it
	// is not used anymore.
	void calculateNormals();

	void draw();
	void draw_wireframe();

	// convenient vector math functions
	inline void addvec(float* dest, float* a, float* b);
	inline void subvec(float* dest, float* a, float* b);
	inline void cross(float* dest, float* a, float* b);

private:
	unsigned int num_tristrips;
	unsigned int index_offset;
	unsigned int vertex_offset;
	std::vector<unsigned int> triStripLengths;
	std::vector<unsigned int> indices;
	std::vector<float> vertices;
	size_t vertex_data_size;
};



#endif
