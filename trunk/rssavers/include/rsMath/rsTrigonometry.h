/*
 * Copyright (C) 1999-2005  Terence M. Welsh
 *
 * This file is part of rsMath.
 *
 * rsMath is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * rsMath is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef RSTRIGONOMETRY_H
#define RSTRIGONOMETRY_H



static float rs_cosine_table[256] = {
	1.0f, 0.999699f, 0.998795f, 0.99729f, 0.995185f, 0.99248f, 0.989177f, 0.985278f, 
	0.980785f, 0.975702f, 0.970031f, 0.963776f, 0.95694f, 0.949528f, 0.941544f, 0.932993f, 
	0.92388f, 0.91421f, 0.903989f, 0.893224f, 0.881921f, 0.870087f, 0.857729f, 0.844854f, 
	0.83147f, 0.817585f, 0.803208f, 0.788346f, 0.77301f, 0.757209f, 0.740951f, 0.724247f, 
	0.707107f, 0.689541f, 0.671559f, 0.653173f, 0.634393f, 0.615232f, 0.595699f, 0.575808f, 
	0.55557f, 0.534998f, 0.514103f, 0.492898f, 0.471397f, 0.449611f, 0.427555f, 0.405241f, 
	0.382683f, 0.359895f, 0.33689f, 0.313682f, 0.290285f, 0.266713f, 0.24298f, 0.219101f, 
	0.19509f, 0.170962f, 0.14673f, 0.122411f, 0.0980171f, 0.0735645f, 0.0490676f, 0.0245412f, 
	0.0f, -0.0245413f, -0.0490677f, -0.0735646f, -0.0980172f, -0.122411f, -0.146731f, -0.170962f, 
	-0.19509f, -0.219101f, -0.24298f, -0.266713f, -0.290285f, -0.313682f, -0.33689f, -0.359895f, 
	-0.382683f, -0.405241f, -0.427555f, -0.449611f, -0.471397f, -0.492898f, -0.514103f, -0.534998f, 
	-0.55557f, -0.575808f, -0.595699f, -0.615232f, -0.634393f, -0.653173f, -0.671559f, -0.689541f, 
	-0.707107f, -0.724247f, -0.740951f, -0.757209f, -0.77301f, -0.788346f, -0.803208f, -0.817585f, 
	-0.83147f, -0.844854f, -0.857729f, -0.870087f, -0.881921f, -0.893224f, -0.903989f, -0.91421f, 
	-0.92388f, -0.932993f, -0.941544f, -0.949528f, -0.95694f, -0.963776f, -0.970031f, -0.975702f, 
	-0.980785f, -0.985278f, -0.989177f, -0.99248f, -0.995185f, -0.99729f, -0.998795f, -0.999699f, 
	-1.0f, -0.999699f, -0.998795f, -0.99729f, -0.995185f, -0.99248f, -0.989177f, -0.985278f, 
	-0.980785f, -0.975702f, -0.970031f, -0.963776f, -0.95694f, -0.949528f, -0.941544f, -0.932993f, 
	-0.92388f, -0.91421f, -0.903989f, -0.893224f, -0.881921f, -0.870087f, -0.857729f, -0.844854f, 
	-0.83147f, -0.817585f, -0.803207f, -0.788346f, -0.77301f, -0.757209f, -0.740951f, -0.724247f, 
	-0.707107f, -0.68954f, -0.671559f, -0.653173f, -0.634393f, -0.615232f, -0.595699f, -0.575808f, 
	-0.55557f, -0.534998f, -0.514103f, -0.492898f, -0.471397f, -0.449611f, -0.427555f, -0.405241f, 
	-0.382683f, -0.359895f, -0.33689f, -0.313682f, -0.290285f, -0.266713f, -0.24298f, -0.219101f, 
	-0.19509f, -0.170962f, -0.14673f, -0.122411f, -0.098017f, -0.0735644f, -0.0490675f, -0.0245411f, 
	0.0f, 0.0245414f, 0.0490678f, 0.0735647f, 0.0980173f, 0.122411f, 0.146731f, 0.170962f, 
	0.19509f, 0.219101f, 0.24298f, 0.266713f, 0.290285f, 0.313682f, 0.33689f, 0.359895f, 
	0.382684f, 0.405241f, 0.427555f, 0.449611f, 0.471397f, 0.492898f, 0.514103f, 0.534998f, 
	0.55557f, 0.575808f, 0.595699f, 0.615232f, 0.634393f, 0.653173f, 0.671559f, 0.689541f, 
	0.707107f, 0.724247f, 0.740951f, 0.757209f, 0.773011f, 0.788347f, 0.803208f, 0.817585f, 
	0.83147f, 0.844854f, 0.857729f, 0.870087f, 0.881921f, 0.893224f, 0.903989f, 0.91421f, 
	0.92388f, 0.932993f, 0.941544f, 0.949528f, 0.95694f, 0.963776f, 0.970031f, 0.975702f, 
	0.980785f, 0.985278f, 0.989177f, 0.99248f, 0.995185f, 0.99729f, 0.998795f, 0.999699f
};


static float rs_cosine_fraction_table[256] = {
	-0.000301181f, -0.000903363f, -0.001505f, -0.00210573f, -0.00270519f, -0.00330302f, -0.00389887f, -0.00449236f, 
	-0.00508315f, -0.00567088f, -0.00625519f, -0.00683573f, -0.00741216f, -0.00798412f, -0.00855127f, -0.00911327f, 
	-0.00966978f, -0.0102205f, -0.010765f, -0.011303f, -0.0118343f, -0.0123584f, -0.012875f, -0.013384f, 
	-0.0138848f, -0.0143773f, -0.0148611f, -0.015336f, -0.0158016f, -0.0162577f, -0.016704f, -0.0171403f, 
	-0.0175662f, -0.0179816f, -0.0183861f, -0.0187796f, -0.0191617f, -0.0195323f, -0.0198911f, -0.020238f, 
	-0.0205726f, -0.0208949f, -0.0212046f, -0.0215015f, -0.0217854f, -0.0220562f, -0.0223138f, -0.0225579f, 
	-0.0227884f, -0.0230052f, -0.0232081f, -0.0233971f, -0.0235719f, -0.0237326f, -0.0238789f, -0.0240109f, 
	-0.0241284f, -0.0242314f, -0.0243198f, -0.0243935f, -0.0244526f, -0.0244969f, -0.0245264f, -0.0245412f, 
	-0.0245412f, -0.0245264f, -0.0244969f, -0.0244526f, -0.0243935f, -0.0243198f, -0.0242314f, -0.0241284f, 
	-0.0240109f, -0.0238789f, -0.0237326f, -0.0235719f, -0.0233971f, -0.0232081f, -0.0230052f, -0.0227884f, 
	-0.0225579f, -0.0223138f, -0.0220562f, -0.0217854f, -0.0215015f, -0.0212046f, -0.0208949f, -0.0205726f, 
	-0.020238f, -0.0198911f, -0.0195323f, -0.0191617f, -0.0187796f, -0.0183861f, -0.0179816f, -0.0175662f, 
	-0.0171403f, -0.016704f, -0.0162577f, -0.0158016f, -0.015336f, -0.0148611f, -0.0143773f, -0.0138848f, 
	-0.013384f, -0.012875f, -0.0123584f, -0.0118343f, -0.011303f, -0.010765f, -0.0102205f, -0.00966978f, 
	-0.00911327f, -0.00855127f, -0.00798411f, -0.00741215f, -0.00683573f, -0.00625519f, -0.00567087f, -0.00508315f, 
	-0.00449236f, -0.00389887f, -0.00330302f, -0.00270519f, -0.00210573f, -0.001505f, -0.00090336f, -0.000301179f, 
	0.000301183f, 0.000903365f, 0.001505f, 0.00210573f, 0.00270519f, 0.00330303f, 0.00389887f, 0.00449236f, 
	0.00508315f, 0.00567088f, 0.00625519f, 0.00683573f, 0.00741216f, 0.00798412f, 0.00855127f, 0.00911327f, 
	0.00966978f, 0.0102205f, 0.010765f, 0.011303f, 0.0118343f, 0.0123584f, 0.012875f, 0.013384f, 
	0.0138848f, 0.0143773f, 0.0148611f, 0.015336f, 0.0158016f, 0.0162577f, 0.016704f, 0.0171403f, 
	0.0175662f, 0.0179816f, 0.0183861f, 0.0187796f, 0.0191617f, 0.0195323f, 0.0198911f, 0.020238f, 
	0.0205726f, 0.0208949f, 0.0212046f, 0.0215015f, 0.0217854f, 0.0220562f, 0.0223138f, 0.0225579f, 
	0.0227884f, 0.0230052f, 0.0232081f, 0.0233971f, 0.0235719f, 0.0237326f, 0.0238789f, 0.0240109f, 
	0.0241284f, 0.0242314f, 0.0243198f, 0.0243935f, 0.0244526f, 0.0244969f, 0.0245264f, 0.0245412f, 
	0.0245412f, 0.0245264f, 0.0244969f, 0.0244526f, 0.0243935f, 0.0243198f, 0.0242314f, 0.0241284f, 
	0.0240109f, 0.0238789f, 0.0237326f, 0.0235719f, 0.0233971f, 0.0232081f, 0.0230052f, 0.0227884f, 
	0.0225579f, 0.0223138f, 0.0220562f, 0.0217854f, 0.0215015f, 0.0212046f, 0.0208949f, 0.0205726f, 
	0.020238f, 0.0198911f, 0.0195323f, 0.0191617f, 0.0187796f, 0.0183861f, 0.0179816f, 0.0175662f, 
	0.0171403f, 0.016704f, 0.0162577f, 0.0158016f, 0.015336f, 0.0148611f, 0.0143773f, 0.0138848f, 
	0.013384f, 0.012875f, 0.0123584f, 0.0118343f, 0.011303f, 0.010765f, 0.0102205f, 0.00966977f, 
	0.00911326f, 0.00855126f, 0.00798411f, 0.00741215f, 0.00683573f, 0.00625518f, 0.00567087f, 0.00508315f, 
	0.00449236f, 0.00389886f, 0.00330302f, 0.00270519f, 0.00210573f, 0.001505f, 0.000903358f, 0.000301177f
};


static float rs_sine_table[256] = {
	0.0f, 0.0245412f, 0.0490677f, 0.0735646f, 0.0980171f, 0.122411f, 0.14673f, 0.170962f, 
	0.19509f, 0.219101f, 0.24298f, 0.266713f, 0.290285f, 0.313682f, 0.33689f, 0.359895f, 
	0.382683f, 0.405241f, 0.427555f, 0.449611f, 0.471397f, 0.492898f, 0.514103f, 0.534998f, 
	0.55557f, 0.575808f, 0.595699f, 0.615232f, 0.634393f, 0.653173f, 0.671559f, 0.689541f, 
	0.707107f, 0.724247f, 0.740951f, 0.757209f, 0.77301f, 0.788346f, 0.803208f, 0.817585f, 
	0.83147f, 0.844854f, 0.857729f, 0.870087f, 0.881921f, 0.893224f, 0.903989f, 0.91421f, 
	0.92388f, 0.932993f, 0.941544f, 0.949528f, 0.95694f, 0.963776f, 0.970031f, 0.975702f, 
	0.980785f, 0.985278f, 0.989177f, 0.99248f, 0.995185f, 0.99729f, 0.998795f, 0.999699f, 
	1.0f, 0.999699f, 0.998795f, 0.99729f, 0.995185f, 0.99248f, 0.989177f, 0.985278f, 
	0.980785f, 0.975702f, 0.970031f, 0.963776f, 0.95694f, 0.949528f, 0.941544f, 0.932993f, 
	0.92388f, 0.91421f, 0.903989f, 0.893224f, 0.881921f, 0.870087f, 0.857729f, 0.844854f, 
	0.83147f, 0.817585f, 0.803208f, 0.788346f, 0.77301f, 0.757209f, 0.740951f, 0.724247f, 
	0.707107f, 0.689541f, 0.671559f, 0.653173f, 0.634393f, 0.615232f, 0.595699f, 0.575808f, 
	0.55557f, 0.534998f, 0.514103f, 0.492898f, 0.471397f, 0.449611f, 0.427555f, 0.405241f, 
	0.382683f, 0.359895f, 0.33689f, 0.313682f, 0.290285f, 0.266713f, 0.24298f, 0.219101f, 
	0.19509f, 0.170962f, 0.14673f, 0.122411f, 0.0980171f, 0.0735645f, 0.0490676f, 0.0245411f, 
	-0.0f, -0.0245413f, -0.0490678f, -0.0735647f, -0.0980172f, -0.122411f, -0.146731f, -0.170962f, 
	-0.19509f, -0.219101f, -0.24298f, -0.266713f, -0.290285f, -0.313682f, -0.33689f, -0.359895f, 
	-0.382684f, -0.405241f, -0.427555f, -0.449611f, -0.471397f, -0.492898f, -0.514103f, -0.534998f, 
	-0.55557f, -0.575808f, -0.595699f, -0.615232f, -0.634393f, -0.653173f, -0.671559f, -0.689541f, 
	-0.707107f, -0.724247f, -0.740951f, -0.757209f, -0.773011f, -0.788346f, -0.803208f, -0.817585f, 
	-0.83147f, -0.844854f, -0.857729f, -0.870087f, -0.881921f, -0.893224f, -0.903989f, -0.91421f, 
	-0.92388f, -0.932993f, -0.941544f, -0.949528f, -0.95694f, -0.963776f, -0.970031f, -0.975702f, 
	-0.980785f, -0.985278f, -0.989177f, -0.99248f, -0.995185f, -0.99729f, -0.998795f, -0.999699f, 
	-1.0f, -0.999699f, -0.998795f, -0.99729f, -0.995185f, -0.99248f, -0.989177f, -0.985278f, 
	-0.980785f, -0.975702f, -0.970031f, -0.963776f, -0.95694f, -0.949528f, -0.941544f, -0.932993f, 
	-0.92388f, -0.91421f, -0.903989f, -0.893224f, -0.881921f, -0.870087f, -0.857729f, -0.844853f, 
	-0.83147f, -0.817585f, -0.803207f, -0.788346f, -0.77301f, -0.757209f, -0.740951f, -0.724247f, 
	-0.707107f, -0.68954f, -0.671559f, -0.653173f, -0.634393f, -0.615231f, -0.595699f, -0.575808f, 
	-0.55557f, -0.534997f, -0.514103f, -0.492898f, -0.471397f, -0.449611f, -0.427555f, -0.405241f, 
	-0.382683f, -0.359895f, -0.33689f, -0.313682f, -0.290285f, -0.266713f, -0.24298f, -0.219101f, 
	-0.19509f, -0.170962f, -0.14673f, -0.122411f, -0.098017f, -0.0735644f, -0.0490675f, -0.0245411f
};


static float rs_sine_fraction_table[256] = {
	0.0245412f, 0.0245264f, 0.0244969f, 0.0244526f, 0.0243935f, 0.0243198f, 0.0242314f, 0.0241284f, 
	0.0240109f, 0.0238789f, 0.0237326f, 0.0235719f, 0.0233971f, 0.0232081f, 0.0230052f, 0.0227884f, 
	0.0225579f, 0.0223138f, 0.0220562f, 0.0217854f, 0.0215015f, 0.0212046f, 0.0208949f, 0.0205726f, 
	0.020238f, 0.0198911f, 0.0195323f, 0.0191617f, 0.0187796f, 0.0183861f, 0.0179816f, 0.0175662f, 
	0.0171403f, 0.016704f, 0.0162577f, 0.0158016f, 0.015336f, 0.0148611f, 0.0143773f, 0.0138848f, 
	0.013384f, 0.012875f, 0.0123584f, 0.0118343f, 0.011303f, 0.010765f, 0.0102205f, 0.00966978f, 
	0.00911327f, 0.00855127f, 0.00798411f, 0.00741215f, 0.00683573f, 0.00625519f, 0.00567088f, 0.00508315f, 
	0.00449236f, 0.00389887f, 0.00330302f, 0.00270519f, 0.00210573f, 0.001505f, 0.000903361f, 0.00030118f, 
	-0.000301182f, -0.000903364f, -0.001505f, -0.00210573f, -0.00270519f, -0.00330303f, -0.00389887f, -0.00449236f, 
	-0.00508315f, -0.00567088f, -0.00625519f, -0.00683573f, -0.00741216f, -0.00798412f, -0.00855127f, -0.00911327f, 
	-0.00966978f, -0.0102205f, -0.010765f, -0.011303f, -0.0118343f, -0.0123584f, -0.012875f, -0.013384f, 
	-0.0138848f, -0.0143773f, -0.0148611f, -0.015336f, -0.0158016f, -0.0162577f, -0.016704f, -0.0171403f, 
	-0.0175662f, -0.0179816f, -0.0183861f, -0.0187796f, -0.0191617f, -0.0195323f, -0.0198911f, -0.020238f, 
	-0.0205726f, -0.0208949f, -0.0212046f, -0.0215015f, -0.0217854f, -0.0220562f, -0.0223138f, -0.0225579f, 
	-0.0227884f, -0.0230052f, -0.0232081f, -0.0233971f, -0.0235719f, -0.0237326f, -0.0238789f, -0.0240109f, 
	-0.0241284f, -0.0242314f, -0.0243198f, -0.0243935f, -0.0244526f, -0.0244969f, -0.0245264f, -0.0245412f, 
	-0.0245412f, -0.0245264f, -0.0244969f, -0.0244526f, -0.0243935f, -0.0243198f, -0.0242314f, -0.0241284f, 
	-0.0240109f, -0.0238789f, -0.0237326f, -0.0235719f, -0.0233971f, -0.0232081f, -0.0230052f, -0.0227884f, 
	-0.0225579f, -0.0223138f, -0.0220562f, -0.0217854f, -0.0215015f, -0.0212046f, -0.0208949f, -0.0205726f, 
	-0.020238f, -0.0198911f, -0.0195323f, -0.0191617f, -0.0187796f, -0.0183861f, -0.0179816f, -0.0175662f, 
	-0.0171403f, -0.016704f, -0.0162577f, -0.0158016f, -0.015336f, -0.0148611f, -0.0143773f, -0.0138848f, 
	-0.013384f, -0.012875f, -0.0123584f, -0.0118343f, -0.011303f, -0.010765f, -0.0102205f, -0.00966977f, 
	-0.00911326f, -0.00855126f, -0.00798411f, -0.00741215f, -0.00683573f, -0.00625518f, -0.00567087f, -0.00508315f, 
	-0.00449236f, -0.00389886f, -0.00330302f, -0.00270519f, -0.00210573f, -0.001505f, -0.000903359f, -0.000301178f, 
	0.000301185f, 0.000903366f, 0.001505f, 0.00210573f, 0.0027052f, 0.00330303f, 0.00389887f, 0.00449237f, 
	0.00508315f, 0.00567088f, 0.00625519f, 0.00683573f, 0.00741216f, 0.00798412f, 0.00855127f, 0.00911327f, 
	0.00966978f, 0.0102205f, 0.010765f, 0.011303f, 0.0118343f, 0.0123584f, 0.012875f, 0.013384f, 
	0.0138848f, 0.0143773f, 0.0148611f, 0.015336f, 0.0158016f, 0.0162577f, 0.016704f, 0.0171403f, 
	0.0175662f, 0.0179816f, 0.0183861f, 0.0187796f, 0.0191617f, 0.0195323f, 0.0198911f, 0.020238f, 
	0.0205726f, 0.0208949f, 0.0212046f, 0.0215015f, 0.0217854f, 0.0220562f, 0.0223138f, 0.0225579f, 
	0.0227884f, 0.0230052f, 0.0232081f, 0.0233971f, 0.0235719f, 0.0237326f, 0.0238789f, 0.0240109f, 
	0.0241284f, 0.0242314f, 0.0243198f, 0.0243935f, 0.0244526f, 0.0244969f, 0.0245264f, 0.0245412f
};


// union to help with fast typecasting from int to float
typedef union{
	unsigned char c[4];
	float f;
} bytes_or_float;


// Fast trig functions
// They're not as precise as cosf and sinf, but they're stupid fast.
inline float rsCosf(float value){
	bytes_or_float bof;
	// Remap value from {0,2pi} to {0,65536} and add fast typecast bias
	bof.f = value * (65536.0f / 6.28318530718f) + 12582912.0f;
	// Use low-order byte for fractional multiplier
	const float fraction(float(bof.c[0]) * 0.00390625f);
	// Use high-order byte for table lookup
	const unsigned char i(bof.c[1]);
	// Do it
	return rs_cosine_table[i] + fraction * rs_cosine_fraction_table[i];
}


inline float rsSinf(float value){
	bytes_or_float bof;
	// Remap value from {0,2pi} to {0,65536} and add fast typecast bias
	bof.f = value * (65536.0f / 6.28318530718f) + 12582912.0f;
	// Use low-order byte for fractional multiplier
	const float fraction(float(bof.c[0]) * 0.00390625f);
	// Use high-order byte for table lookup
	const unsigned char i(bof.c[1]);
	// Do it
	return rs_sine_table[i] + fraction * rs_sine_fraction_table[i];
}


	/*outfile.open("outfile");
	outfile << "float rs_cosine_table[256] = {" << std::endl;
	for(int i=0; i<256; i++){
		if(!(i % 8))
			outfile << std::endl << "\t";
		outfile << cosf(RS_PIx2 * float(i) / 256.0f) << "f, ";
	}
	outfile << std::endl << "};" << std::endl;
	outfile << "float rs_cosine_fraction_table[256] = {" << std::endl;
	for(int i=0; i<256; i++){
		if(!(i % 8))
			outfile << std::endl << "\t";
		outfile << cosf(RS_PIx2 * float(i+1) / 256.0f) - cosf(RS_PIx2 * float(i) / 256.0f) << "f, ";
	}
	outfile << std::endl << "};" << std::endl;
	outfile << "float rs_sine_table[256] = {" << std::endl;
	for(int i=0; i<256; i++){
		if(!(i % 8))
			outfile << std::endl << "\t";
		outfile << sinf(RS_PIx2 * float(i) / 256.0f) << "f, ";
	}
	outfile << std::endl << "};" << std::endl;
	outfile << "float rs_sine_fraction_table[256] = {" << std::endl;
	for(int i=0; i<256; i++){
		if(!(i % 8))
			outfile << std::endl << "\t";
		outfile << sinf(RS_PIx2 * float(i+1) / 256.0f) - sinf(RS_PIx2 * float(i) / 256.0f) << "f, ";
	}
	outfile << std::endl << "};" << std::endl;*/



#endif