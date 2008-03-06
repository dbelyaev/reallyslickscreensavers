/*
 * Copyright (C) 2001-2005  Terence M. Welsh
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


#include <Implicit/impEllipsoid.h>



float impEllipsoid::value(float* position){
	const float x(position[0]);
	const float y(position[1]);
	const float z(position[2]);

	const float tx(x * invmat[0] + y * invmat[4] + z * invmat[8] + invmat[12]);
	const float ty(x * invmat[1] + y * invmat[5] + z * invmat[9] + invmat[13]);
	const float tz(x * invmat[2] + y * invmat[6] + z * invmat[10] + invmat[14]);

	return(thicknessSquared / (tx*tx + ty*ty + tz*tz));
}
