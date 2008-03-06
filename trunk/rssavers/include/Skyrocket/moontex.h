/*
 * Copyright (C) 1999-2005  Terence M. Welsh
 *
 * This file is part of Skyrocket.
 *
 * Skyrocket is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 *
 * Skyrocket is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef MOONTEX_H
#define MOONTEX_H



#define MOONTEXSIZE 64



unsigned char moonmap[MOONTEXSIZE][MOONTEXSIZE][2] = {
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,6,0,20,0,45,0,84,0,137,0,184,0,220,0,242,0,255,0,255,0,255,
0,255,0,255,0,255,0,255,0,242,0,218,0,183,0,135,0,83,0,44,0,19,0,6,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,1,0,13,0,42,0,97,0,165,0,228,0,255,1,255,1,255,0,255,0,255,1,255,0,255,1,255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,0,255,
0,255,0,227,0,163,0,96,0,40,0,13,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,13,0,51,0,126,0,215,0,255,1,255,5,255,
9,255,15,255,19,255,5,255,13,255,15,255,13,255,13,255,10,255,3,255,6,255,5,255,0,255,0,255,1,255,0,255,0,255,0,255,0,255,0,255,0,213,0,125,0,50,0,12,
0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,44,0,120,1,217,4,255,9,255,22,255,35,255,42,255,42,255,45,255,59,255,37,255,42,255,53,255,66,255,38,255,
40,255,51,255,38,255,30,255,13,255,6,255,6,255,1,255,1,255,0,255,0,255,0,255,0,255,0,255,0,216,0,120,0,43,0,8,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,24,0,91,
1,198,6,255,15,255,31,255,53,255,64,255,99,255,76,255,71,255,76,255,92,255,96,255,69,255,71,255,84,255,74,255,66,255,77,255,79,255,50,255,40,255,28,255,23,255,17,255,
1,255,0,255,1,255,1,255,2,255,0,255,0,255,0,255,0,196,0,90,0,22,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,46,1,141,13,244,47,255,71,255,77,255,80,255,110,255,137,255,138,255,119,255,
92,255,136,255,138,255,150,255,158,255,158,255,147,255,147,255,112,255,102,255,98,255,87,255,73,255,59,255,46,255,40,255,27,255,15,255,13,255,12,255,14,255,9,255,0,255,0,255,
0,255,0,243,0,138,0,45,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,8,5,70,20,189,38,255,106,255,143,255,126,255,132,255,152,255,160,255,161,255,173,255,182,255,177,255,198,255,181,255,153,255,187,255,199,255,193,255,170,255,
152,255,106,255,105,255,116,255,100,255,107,255,54,255,45,255,50,255,48,255,40,255,25,255,11,255,12,255,5,255,0,255,0,255,0,255,0,255,0,185,0,67,0,8,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,7,90,52,213,126,255,157,255,184,255,
173,255,158,255,164,255,166,255,193,255,202,255,211,255,208,255,216,255,201,255,178,255,189,255,201,255,213,255,206,255,160,255,165,255,115,255,112,255,125,255,100,255,84,255,87,255,85,255,
71,255,48,255,40,255,46,255,34,255,22,255,17,255,8,255,2,255,0,255,0,255,0,255,0,209,0,86,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,9,92,86,221,180,255,194,255,193,255,192,255,196,255,189,255,199,255,217,255,225,255,224,255,225,255,224,255,
186,255,151,255,199,255,201,255,177,255,177,255,193,255,175,255,160,255,140,255,149,255,123,255,107,255,108,255,96,255,92,255,104,255,92,255,74,255,67,255,56,255,40,255,33,255,22,255,
11,255,5,255,1,255,0,255,0,255,0,218,0,89,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
2,9,27,90,80,221,166,255,202,255,202,255,208,255,209,255,215,255,208,255,217,255,212,255,218,255,225,255,204,255,163,255,176,255,191,255,211,255,201,255,194,255,167,255,164,255,156,255,
169,255,182,255,169,255,164,255,152,255,138,255,130,255,120,255,115,255,129,255,134,255,121,255,80,255,60,255,47,255,32,255,35,255,30,255,10,255,2,255,0,255,0,255,0,218,0,86,
0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,43,71,182,213,208,255,203,255,216,255,217,255,213,255,224,255,
226,255,215,255,211,255,198,255,211,255,224,255,196,255,171,255,198,255,216,255,212,255,206,255,217,255,229,255,213,255,186,255,189,255,203,255,199,255,199,255,191,255,147,255,147,255,139,255,
116,255,102,255,125,255,139,255,127,255,95,255,66,255,54,255,50,255,35,255,28,255,10,255,2,255,0,255,0,255,0,210,0,67,0,5,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,1,44,48,161,191,227,255,230,255,212,255,203,255,217,255,233,255,230,255,224,255,206,255,203,255,199,255,203,255,216,255,215,255,202,255,
199,255,209,255,222,255,220,255,227,255,229,255,224,255,217,255,198,255,184,255,201,255,213,255,207,255,197,255,163,255,158,255,154,255,131,255,143,255,142,255,137,255,130,255,93,255,75,255,
81,255,65,255,40,255,19,255,8,255,2,255,0,255,0,255,0,186,0,45,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,34,25,211,144,
244,255,218,255,231,255,231,255,218,255,230,255,239,255,222,255,216,255,201,255,203,255,199,255,201,255,217,255,224,255,208,255,194,255,197,255,226,255,242,255,235,255,226,255,220,255,208,255,
203,255,186,255,206,255,216,255,212,255,206,255,194,255,176,255,199,255,199,255,158,255,143,255,149,255,147,255,126,255,111,255,103,255,102,255,72,255,58,255,35,255,16,255,3,255,0,255,
0,255,0,139,0,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,9,158,94,255,238,235,255,255,255,237,255,239,255,230,255,218,255,215,255,216,255,
204,255,201,255,206,255,194,255,187,255,196,255,209,255,213,255,216,255,216,255,212,255,222,255,229,255,216,255,221,255,199,255,197,255,201,255,204,255,201,255,187,255,192,255,196,255,196,255,
197,255,182,255,163,255,165,255,144,255,138,255,151,255,137,255,108,255,117,255,108,255,79,255,63,255,47,255,22,255,3,255,1,255,0,237,0,90,0,8,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,65,47,251,201,243,255,239,255,247,255,240,255,225,255,213,255,197,255,196,255,218,255,201,255,192,255,199,255,207,255,222,255,207,255,206,255,215,255,
226,255,235,255,238,255,226,255,220,255,207,255,211,255,212,255,208,255,197,255,176,255,181,255,182,255,194,255,191,255,197,255,198,255,176,255,170,255,164,255,151,255,135,255,157,255,161,255,
122,255,108,255,128,255,122,255,83,255,68,255,54,255,23,255,5,255,0,255,0,197,0,43,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,15,215,124,255,255,244,255,
254,255,246,255,235,255,209,255,196,255,202,255,213,255,217,255,206,255,198,255,209,255,216,255,238,255,231,255,217,255,213,255,217,255,233,255,244,255,238,255,227,255,208,255,202,255,212,255,
218,255,207,255,184,255,183,255,172,255,188,255,184,255,193,255,204,255,201,255,182,255,167,255,152,255,154,255,167,255,169,255,134,255,130,255,159,255,159,255,130,255,90,255,73,255,48,255,
18,255,1,255,0,255,0,119,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,2,98,55,255,219,248,255,252,255,255,255,246,255,218,255,202,255,197,255,203,255,208,255,215,255,
216,255,209,255,225,255,218,255,204,255,206,255,203,255,211,255,192,255,201,255,231,255,239,255,207,255,207,255,220,255,221,255,225,255,225,255,213,255,204,255,178,255,188,255,204,255,203,255,
211,255,213,255,204,255,192,255,175,255,157,255,136,255,145,255,139,255,154,255,161,255,160,255,156,255,117,255,103,255,66,255,43,255,19,255,0,255,0,216,0,50,0,2,0,0,0,0,
0,0,0,0,0,0,17,15,220,131,255,255,250,255,252,255,255,255,247,255,221,255,186,255,183,255,212,255,198,255,209,255,221,255,215,255,220,255,222,255,206,255,180,255,193,255,196,255,
175,255,175,255,212,255,239,255,206,255,212,255,218,255,227,255,225,255,237,255,216,255,221,255,202,255,201,255,206,255,206,255,204,255,206,255,221,255,238,255,220,255,178,255,134,255,125,255,
146,255,173,255,165,255,153,255,158,255,130,255,122,255,84,255,64,255,46,255,5,255,0,255,0,124,0,13,0,0,0,0,0,0,0,0,0,1,79,45,255,219,252,255,252,255,254,255,
254,255,244,255,222,255,211,255,212,255,224,255,226,255,218,255,211,255,216,255,216,255,201,255,198,255,186,255,175,255,184,255,180,255,175,255,196,255,216,255,233,255,230,255,215,255,213,255,
230,255,224,255,206,255,225,255,237,255,216,255,201,255,202,255,213,255,225,255,233,255,247,255,237,255,207,255,175,255,147,255,156,255,181,255,169,255,140,255,135,255,137,255,118,255,108,255,
91,255,65,255,24,255,2,255,0,213,0,40,0,1,0,0,0,0,0,0,12,8,202,100,255,255,248,255,252,255,250,255,251,255,240,255,237,255,239,255,213,255,212,255,242,255,229,255,
220,255,221,255,220,255,172,255,160,255,183,255,189,255,211,255,206,255,181,255,199,255,213,255,230,255,234,255,220,255,212,255,213,255,221,255,227,255,225,255,239,255,234,255,209,255,203,255,
231,255,239,255,238,255,230,255,221,255,194,255,182,255,183,255,188,255,181,255,167,255,143,255,134,255,138,255,129,255,116,255,116,255,78,255,56,255,18,255,1,254,0,95,0,6,0,0,
0,0,0,0,85,22,255,168,255,255,254,255,250,255,243,255,246,255,237,255,237,255,227,255,186,255,213,255,246,255,233,255,226,255,237,255,202,255,145,255,137,255,167,255,206,255,230,255,
222,255,199,255,193,255,180,255,187,255,194,255,192,255,218,255,209,255,230,255,243,255,238,255,235,255,244,255,233,255,221,255,233,255,242,255,240,255,230,255,208,255,202,255,188,255,187,255,
189,255,182,255,182,255,163,255,171,255,156,255,132,255,123,255,127,255,92,255,68,255,63,255,12,255,0,162,0,20,0,0,0,0,1,2,165,49,255,232,252,255,252,255,244,255,244,255,
250,255,250,255,244,255,225,255,213,255,240,255,251,255,242,255,246,255,243,255,188,255,128,255,129,255,186,255,227,255,233,255,221,255,157,255,125,255,114,255,165,255,171,255,182,255,212,255,
213,255,233,255,250,255,242,255,246,255,248,255,242,255,237,255,244,255,238,255,218,255,218,255,225,255,206,255,197,255,194,255,187,255,188,255,181,255,151,255,153,255,159,255,134,255,143,255,
129,255,107,255,92,255,88,255,41,255,0,228,0,45,0,0,0,0,1,6,215,88,255,255,251,255,250,255,250,255,242,255,244,255,255,255,255,255,243,255,240,255,255,255,246,255,240,255,
255,255,218,255,167,255,134,255,134,255,167,255,196,255,207,255,218,255,146,255,104,255,100,255,126,255,157,255,209,255,202,255,217,255,239,255,246,255,243,255,247,255,240,255,234,255,239,255,
243,255,225,255,215,255,217,255,231,255,215,255,208,255,206,255,192,255,199,255,178,255,143,255,149,255,147,255,129,255,144,255,143,255,139,255,118,255,88,255,86,255,22,254,0,82,0,0,
0,0,40,12,250,140,255,255,248,255,246,255,255,255,248,255,237,255,244,255,255,255,250,255,240,255,229,255,234,255,235,255,225,255,211,255,161,255,117,255,140,255,197,255,192,255,186,255,
170,255,135,255,117,255,102,255,110,255,164,255,193,255,224,255,192,255,212,255,242,255,227,255,240,255,240,255,247,255,248,255,239,255,239,255,224,255,209,255,216,255,222,255,215,255,202,255,
192,255,166,255,144,255,150,255,158,255,166,255,164,255,164,255,146,255,170,255,135,255,129,255,96,255,48,255,0,135,0,0,0,0,103,24,255,187,251,255,247,255,244,255,248,255,255,255,
246,255,250,255,255,255,254,255,246,255,237,255,243,255,235,255,213,255,176,255,128,255,117,255,158,255,191,255,194,255,194,255,157,255,123,255,116,255,108,255,114,255,151,255,176,255,196,255,
154,255,191,255,230,255,234,255,244,255,244,255,248,255,247,255,235,255,239,255,237,255,217,255,222,255,230,255,221,255,221,255,188,255,136,255,131,255,163,255,166,255,170,255,165,255,171,255,
166,255,175,255,143,255,134,255,118,255,71,255,0,183,0,0,0,0,156,41,255,222,250,255,254,255,252,255,252,255,254,255,250,255,254,255,255,255,255,255,254,255,252,255,254,255,221,255,
170,255,140,255,121,255,147,255,187,255,160,255,176,255,217,255,202,255,159,255,154,255,159,255,151,255,138,255,158,255,149,255,165,255,211,255,230,255,234,255,244,255,251,255,243,255,238,255,
240,255,235,255,230,255,230,255,242,255,224,255,206,255,218,255,184,255,144,255,156,255,161,255,146,255,144,255,140,255,156,255,150,255,147,255,153,255,147,255,137,255,118,255,14,219,0,0,
0,0,183,59,255,244,255,255,255,255,255,255,254,255,254,255,248,255,244,255,255,255,255,255,254,255,251,255,255,255,207,255,138,255,150,255,135,255,144,255,204,255,192,255,199,255,233,255,
229,255,187,255,161,255,129,255,151,255,171,255,166,255,143,255,144,255,208,255,240,255,239,255,240,255,251,255,252,255,252,255,240,255,225,255,227,255,216,255,220,255,222,255,208,255,212,255,
215,255,197,255,177,255,159,255,149,255,142,255,126,255,140,255,164,255,184,255,181,255,146,255,117,255,166,255,51,242,0,0,0,0,197,75,235,254,255,255,255,255,252,255,252,255,255,255,
251,255,248,255,255,255,255,255,255,255,251,255,247,255,235,255,212,255,202,255,194,255,177,255,204,255,230,255,238,255,238,255,237,255,213,255,171,255,142,255,143,255,172,255,184,255,159,255,
186,255,224,255,240,255,235,255,227,255,242,255,240,255,255,255,243,255,224,255,224,255,211,255,215,255,218,255,216,255,237,255,237,255,193,255,160,255,160,255,165,255,160,255,137,255,140,255,
167,255,176,255,199,255,167,255,146,255,191,255,55,254,0,0,0,0,222,89,240,255,248,255,248,255,254,255,251,255,242,255,251,255,252,255,254,255,255,255,255,255,255,255,251,255,242,255,
244,255,217,255,192,255,220,255,225,255,225,255,247,255,254,255,250,255,234,255,201,255,180,255,186,255,176,255,173,255,204,255,240,255,238,255,244,255,247,255,239,255,231,255,225,255,244,255,
238,255,209,255,203,255,207,255,218,255,235,255,240,255,233,255,226,255,180,255,146,255,177,255,189,255,170,255,160,255,177,255,181,255,177,255,191,255,186,255,171,255,194,255,118,255,0,0,
0,0,247,98,251,255,251,255,254,255,254,255,247,255,244,255,252,255,255,255,254,255,254,255,255,255,255,255,250,255,237,255,235,255,211,255,177,255,226,255,254,255,242,255,247,255,254,255,
246,255,242,255,212,255,187,255,216,255,212,255,225,255,221,255,240,255,243,255,240,255,248,255,251,255,235,255,239,255,240,255,242,255,231,255,230,255,233,255,222,255,233,255,255,255,244,255,
226,255,192,255,182,255,188,255,193,255,165,255,175,255,188,255,177,255,177,255,176,255,170,255,176,255,204,255,196,255,0,0,0,0,255,100,248,255,247,255,255,255,254,255,243,255,246,255,
248,255,255,255,255,255,252,255,254,255,252,255,248,255,238,255,211,255,176,255,211,255,252,255,251,255,244,255,250,255,255,255,225,255,217,255,224,255,209,255,227,255,221,255,221,255,212,255,
231,255,231,255,239,255,239,255,218,255,229,255,231,255,237,255,247,255,247,255,247,255,244,255,247,255,254,255,254,255,247,255,235,255,209,255,201,255,199,255,177,255,161,255,188,255,187,255,
157,255,130,255,180,255,169,255,188,255,215,255,221,255,0,0,0,0,255,98,250,255,248,255,246,255,254,255,242,255,250,255,251,255,251,255,251,255,243,255,246,255,247,255,244,255,244,255,
212,255,215,255,243,255,240,255,239,255,237,255,242,255,243,255,247,255,233,255,207,255,220,255,242,255,242,255,238,255,225,255,235,255,230,255,231,255,225,255,230,255,217,255,221,255,243,255,
254,255,238,255,224,255,226,255,235,255,239,255,220,255,216,255,234,255,234,255,226,255,201,255,165,255,172,255,198,255,196,255,159,255,138,255,181,255,222,255,196,255,196,255,218,255,0,0,
0,0,255,90,252,255,251,255,251,255,250,255,244,255,248,255,255,255,254,255,250,255,255,255,252,255,250,255,248,255,251,255,254,255,248,255,233,255,229,255,242,255,243,255,239,255,222,255,
218,255,215,255,217,255,218,255,217,255,222,255,233,255,213,255,221,255,239,255,237,255,231,255,234,255,230,255,238,255,238,255,242,255,243,255,227,255,225,255,221,255,211,255,215,255,220,255,
239,255,243,255,234,255,192,255,171,255,187,255,197,255,213,255,199,255,186,255,178,255,216,255,186,255,209,255,242,255,0,0,0,0,251,76,255,255,248,255,238,255,242,255,231,255,242,255,
255,255,252,255,244,255,250,255,244,255,237,255,218,255,229,255,254,255,255,255,243,255,239,255,237,255,215,255,220,255,247,255,217,255,181,255,209,255,217,255,204,255,218,255,235,255,230,255,
230,255,248,255,234,255,226,255,222,255,239,255,234,255,230,255,225,255,233,255,237,255,233,255,226,255,218,255,216,255,218,255,233,255,240,255,235,255,226,255,218,255,196,255,183,255,188,255,
197,255,159,255,140,255,215,255,235,255,230,255,250,254,0,0,0,0,193,59,255,245,242,255,225,255,251,255,246,255,244,255,246,255,251,255,246,255,244,255,231,255,221,255,220,255,231,255,
242,255,244,255,251,255,235,255,203,255,188,255,180,255,238,255,230,255,187,255,225,255,226,255,220,255,234,255,230,255,226,255,231,255,239,255,239,255,229,255,221,255,231,255,246,255,234,255,
231,255,235,255,224,255,225,255,213,255,212,255,216,255,215,255,226,255,240,255,242,255,221,255,224,255,213,255,184,255,163,255,154,255,152,255,146,255,215,255,246,255,255,255,211,242,0,0,
0,0,170,42,255,223,247,255,255,255,254,255,247,255,237,255,231,255,254,255,254,255,238,255,197,255,189,255,189,255,161,255,172,255,206,255,208,255,225,255,233,255,182,255,153,255,206,255,
231,255,231,255,229,255,209,255,220,255,211,255,204,255,226,255,244,255,225,255,237,255,237,255,226,255,217,255,215,255,217,255,218,255,226,255,221,255,222,255,225,255,234,255,227,255,221,255,
227,255,238,255,242,255,239,255,238,255,224,255,216,255,199,255,181,255,147,255,183,255,251,255,254,255,255,255,120,219,0,0,0,0,131,24,255,188,224,255,240,255,247,255,251,255,239,255,
227,255,244,255,252,255,227,255,207,255,169,255,128,255,114,255,129,255,193,255,229,255,244,255,202,255,152,255,157,255,176,255,208,255,237,255,207,255,199,255,226,255,215,255,204,255,217,255,
230,255,229,255,234,255,235,255,227,255,211,255,196,255,203,255,218,255,218,255,221,255,221,255,222,255,231,255,231,255,231,255,231,255,238,255,234,255,240,255,226,255,206,255,233,255,226,255,
204,255,208,255,238,255,252,255,252,255,255,255,88,184,0,0,0,0,90,12,255,142,227,255,240,255,247,255,255,255,251,255,235,255,237,255,248,255,237,255,222,255,147,255,107,255,117,255,
146,255,212,255,255,255,246,255,222,255,149,255,157,255,198,255,206,255,194,255,184,255,212,255,221,255,212,255,220,255,221,255,220,255,240,255,238,255,229,255,224,255,212,255,207,255,215,255,
221,255,215,255,221,255,238,255,251,255,248,255,250,255,246,255,243,255,239,255,235,255,235,255,212,255,211,255,238,255,242,255,208,255,215,255,235,255,247,255,254,255,247,255,17,137,0,0,
0,0,28,6,247,90,250,255,242,255,254,255,254,255,254,255,252,255,255,255,247,255,215,255,183,255,142,255,118,255,116,255,123,255,164,255,230,255,238,255,240,255,217,255,170,255,170,255,
197,255,175,255,172,255,224,255,225,255,203,255,218,255,237,255,238,255,240,255,233,255,234,255,224,255,227,255,220,255,216,255,209,255,221,255,222,255,227,255,250,255,250,255,250,255,252,255,
251,255,239,255,237,255,233,255,222,255,217,255,225,255,239,255,220,255,206,255,244,255,251,255,255,255,209,255,3,84,0,0,0,0,1,2,194,51,255,233,250,255,239,255,251,255,254,255,
252,255,254,255,255,255,229,255,169,255,142,255,123,255,114,255,107,255,107,255,153,255,224,255,222,255,198,255,220,255,231,255,188,255,134,255,163,255,202,255,234,255,217,255,211,255,230,255,
247,255,242,255,239,255,242,255,231,255,233,255,217,255,216,255,231,255,233,255,231,255,224,255,240,255,254,255,251,255,255,255,248,255,242,255,242,255,238,255,230,255,233,255,234,255,244,255,
244,255,247,255,255,255,254,255,255,255,158,231,1,45,0,0,0,0,0,0,112,23,255,168,246,255,235,255,255,255,254,255,255,255,254,255,250,255,224,255,169,255,152,255,142,255,125,255,
122,255,116,255,120,255,193,255,208,255,177,255,221,255,251,255,233,255,188,255,183,255,187,255,226,255,222,255,206,255,229,255,240,255,242,255,240,255,235,255,215,255,209,255,208,255,221,255,
234,255,238,255,231,255,235,255,247,255,252,255,244,255,248,255,252,255,248,255,242,255,234,255,230,255,237,255,237,255,248,255,252,255,251,255,254,255,255,255,255,255,86,164,0,19,0,0,
0,0,0,0,26,8,243,102,255,255,251,255,254,255,254,255,255,255,250,255,238,255,226,255,184,255,161,255,143,255,134,255,140,255,130,255,125,255,186,255,226,255,240,255,243,255,240,255,
218,255,192,255,189,255,188,255,187,255,181,255,206,255,251,255,255,255,246,255,230,255,222,255,209,255,193,255,198,255,224,255,221,255,225,255,239,255,252,255,254,255,252,255,240,255,244,255,
254,255,247,255,243,255,229,255,229,255,238,255,242,255,248,255,250,255,243,255,252,255,255,255,234,254,15,96,0,6,0,0,0,0,0,0,0,2,154,46,255,220,255,255,250,255,252,255,
255,255,250,255,238,255,240,255,203,255,163,255,150,255,130,255,132,255,138,255,138,255,181,255,240,255,251,255,246,255,239,255,201,255,170,255,176,255,160,255,159,255,150,255,189,255,255,255,
255,255,255,255,239,255,225,255,220,255,201,255,203,255,229,255,234,255,238,255,247,255,252,255,255,255,254,255,251,255,255,255,255,255,243,255,247,255,239,255,230,255,234,255,237,255,246,255,
250,255,247,255,254,255,255,255,119,215,0,41,0,0,0,0,0,0,0,0,0,0,48,15,255,132,255,255,251,255,252,255,255,255,252,255,251,255,248,255,222,255,171,255,158,255,144,255,
130,255,139,255,125,255,154,255,230,255,242,255,247,255,254,255,170,255,131,255,163,255,152,255,158,255,146,255,160,255,231,255,255,255,250,255,211,255,217,255,242,255,222,255,222,255,242,255,
252,255,254,255,247,255,251,255,254,255,254,255,255,255,255,255,255,255,254,255,251,255,242,255,234,255,238,255,233,255,239,255,243,255,252,255,255,255,238,255,22,126,0,14,0,0,0,0,
0,0,0,0,0,0,6,2,197,57,255,222,251,255,254,255,255,255,254,255,252,255,243,255,227,255,187,255,161,255,156,255,145,255,144,255,134,255,171,255,229,255,235,255,242,255,255,255,
175,255,102,255,111,255,144,255,161,255,166,255,153,255,186,255,230,255,222,255,188,255,196,255,212,255,213,255,208,255,247,255,255,255,248,255,243,255,250,255,255,255,255,255,255,255,255,255,
255,255,255,255,250,255,240,255,238,255,248,255,243,255,242,255,244,255,252,255,255,255,143,218,1,51,0,3,0,0,0,0,0,0,0,0,0,0,1,0,73,16,255,126,244,255,255,255,
255,255,255,255,251,255,239,255,234,255,222,255,201,255,198,255,182,255,166,255,192,255,235,255,252,255,251,255,255,255,234,255,150,255,96,255,109,255,135,255,152,255,166,255,164,255,173,255,
196,255,193,255,184,255,178,255,172,255,184,255,199,255,237,255,243,255,239,255,243,255,248,255,254,255,255,255,255,255,255,255,255,255,255,255,254,255,248,255,250,255,252,255,248,255,248,255,
252,255,255,255,240,255,37,121,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,1,186,48,240,205,229,255,252,255,255,255,254,255,243,255,243,255,251,255,251,255,244,255,
226,255,220,255,244,255,255,255,255,255,255,255,240,255,166,255,104,255,99,255,117,255,125,255,131,255,149,255,158,255,167,255,184,255,188,255,186,255,176,255,173,255,186,255,202,255,198,255,
208,255,234,255,246,255,251,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,255,254,255,255,255,255,255,95,200,0,44,0,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,43,9,244,96,212,240,234,255,255,255,255,255,248,255,234,255,243,255,255,255,255,255,252,255,255,255,255,255,255,255,255,255,242,255,186,255,125,255,
99,255,119,255,126,255,118,255,118,255,131,255,145,255,156,255,167,255,178,255,192,255,203,255,215,255,194,255,184,255,175,255,202,255,230,255,251,255,254,255,255,255,255,255,255,255,255,255,
254,255,251,255,252,255,255,255,255,255,255,255,255,255,255,255,255,255,180,238,5,91,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,140,25,250,147,
222,255,247,255,255,255,252,255,238,255,235,255,252,255,255,255,254,255,252,255,246,255,252,255,237,255,191,255,159,255,142,255,122,255,138,255,129,255,107,255,128,255,123,255,114,255,126,255,
154,255,153,255,177,255,233,255,250,255,202,255,175,255,188,255,231,255,239,255,251,255,254,255,254,255,255,255,252,255,254,255,251,255,247,255,250,255,254,255,255,255,255,255,255,255,255,255,
242,255,43,142,0,23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,27,0,207,49,247,194,243,255,255,255,255,255,252,255,248,255,255,255,252,255,
244,255,244,255,247,255,233,255,192,255,171,255,198,255,183,255,152,255,144,255,132,255,128,255,145,255,136,255,130,255,132,255,150,255,160,255,194,255,242,255,250,255,207,255,198,255,212,255,
231,255,250,255,248,255,252,255,254,255,251,255,251,255,252,255,252,255,251,255,252,255,252,255,255,255,255,255,255,255,255,255,128,189,2,45,0,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,50,6,201,73,248,215,251,255,255,255,252,255,231,255,218,255,226,255,242,255,254,255,201,255,173,255,198,255,191,255,216,255,203,255,
157,255,131,255,144,255,165,255,152,255,145,255,147,255,146,255,159,255,170,255,202,255,237,255,230,255,233,255,226,255,213,255,225,255,242,255,252,255,254,255,254,255,251,255,252,255,254,255,
252,255,251,255,254,255,252,255,252,255,255,255,255,255,153,213,17,69,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
80,9,221,93,206,223,216,255,251,255,231,255,188,255,175,255,180,255,209,255,149,255,127,255,206,255,201,255,187,255,193,255,181,255,137,255,142,255,160,255,145,255,145,255,146,255,164,255,
186,255,164,255,203,255,235,255,226,255,216,255,227,255,233,255,246,255,250,255,255,255,254,255,254,255,250,255,251,255,254,255,252,255,252,255,252,255,248,255,251,255,255,255,175,220,21,90,
0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,60,12,166,96,170,224,182,255,243,255,233,255,171,255,
143,255,139,255,119,255,109,255,143,255,159,255,156,255,164,255,187,255,196,255,161,255,144,255,161,255,189,255,163,255,176,255,224,255,218,255,229,255,242,255,248,255,233,255,237,255,222,255,
215,255,230,255,251,255,247,255,252,255,252,255,250,255,248,255,251,255,252,255,243,255,248,255,255,255,166,221,25,92,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,57,12,164,94,175,215,167,255,193,255,201,255,178,255,142,255,115,255,108,255,116,255,121,255,136,255,135,255,
138,255,182,255,206,255,191,255,211,255,208,255,198,255,212,255,248,255,255,255,252,255,251,255,250,255,242,255,207,255,216,255,234,255,238,255,250,255,250,255,251,255,251,255,250,255,244,255,
248,255,251,255,255,255,255,255,175,212,26,90,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,2,0,37,10,143,74,176,192,136,255,154,255,158,255,129,255,111,255,105,255,108,255,108,255,129,255,145,255,119,255,149,255,224,255,238,255,233,255,227,255,233,255,250,255,
251,255,246,255,209,255,225,255,212,255,186,255,172,255,222,255,255,255,248,255,254,255,254,255,252,255,247,255,246,255,242,255,244,255,255,255,248,255,119,189,18,71,0,9,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,31,6,134,49,177,146,150,246,
132,255,127,255,131,255,115,255,100,255,102,255,110,255,134,255,152,255,209,255,250,255,250,255,240,255,242,255,254,255,255,255,243,255,197,255,177,255,182,255,186,255,178,255,184,255,225,255,
248,255,248,255,254,255,255,255,254,255,251,255,247,255,246,255,255,255,255,245,120,143,7,48,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,1,83,25,166,97,153,202,123,255,117,255,122,255,116,255,112,255,114,255,118,255,
157,255,203,255,235,255,251,255,247,255,244,255,255,255,254,255,218,255,194,255,203,255,183,255,184,255,194,255,233,255,247,255,250,255,251,255,255,255,254,255,250,255,250,255,255,255,255,255,
233,199,72,95,6,25,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,3,0,27,10,107,48,181,126,142,221,104,255,107,255,109,255,109,255,114,255,128,255,134,255,152,255,158,255,204,255,235,255,226,255,225,255,
221,255,243,255,244,255,227,255,227,255,242,255,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,218,137,124,31,46,2,9,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
6,1,48,15,145,56,184,131,145,219,112,255,116,255,120,255,122,255,129,255,140,255,166,255,182,255,194,255,183,255,218,255,243,255,251,255,255,255,254,255,254,255,255,255,255,255,255,255,
254,255,252,255,255,255,255,255,251,217,136,130,42,56,7,15,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,5,2,38,15,107,46,173,102,209,169,186,233,
164,255,160,255,160,255,230,255,250,255,234,255,234,255,250,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,231,246,168,120,100,20,44,3,16,0,3,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,12,8,99,23,167,50,218,89,255,142,255,187,255,222,255,244,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,243,255,221,254,187,215,140,158,89,89,49,17,23,2,8,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,3,6,60,13,105,25,163,42,183,59,189,75,208,90,237,98,248,101,201,98,172,89,177,75,128,59,95,40,31,25,1,12,
1,6,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};



#endif
