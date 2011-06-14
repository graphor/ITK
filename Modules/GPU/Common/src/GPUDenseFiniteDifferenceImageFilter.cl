/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

//
// Apply Update : out = out + dt*buf
//
// the element is a vector in DeformationField

// interpolating functions

#ifdef DIM_1
__kernel void ApplyUpdate(__global const BUFPIXELTYPE *buf,
                          __global OUTPIXELTYPE *out,
						              float dt, int width)
{
  int gix = get_global_id(0);
  float sum = 0;
  int   num = 0;
  if(gix < width)
  {
	out[gix] = (OUTPIXELTYPE)( (float)out[gix] + dt*(float)(buf[gix]) );
  }
}
#endif

#ifdef DIM_2
__kernel void ApplyUpdate(__global const BUFPIXELTYPE *buf,
                          __global OUTPIXELTYPE *out,
                          float dt, int width, int height)
{
  int gix = get_global_id(0);
  int giy = get_global_id(1);
  unsigned int gidx = width*giy + gix;
  if(gix < width && giy < height)
  {
    gidx *= 2;
    out[gidx] = (OUTPIXELTYPE)( (float)out[gidx] + dt*(float)(buf[gidx]) );
    gidx ++;
    out[gidx] = (OUTPIXELTYPE)( (float)out[gidx] + dt*(float)(buf[gidx]) );
  }
}
#endif

#ifdef DIM_3
__kernel void ApplyUpdate(__global const BUFPIXELTYPE *buf,
                          __global OUTPIXELTYPE *out,
                          float dt,
                          int width, int height, int depth)
{
  int gix = get_global_id(0);
  int giy = get_global_id(1);
  int giz = get_global_id(2);
  unsigned int gidx = width*(giz*height + giy) + gix;
  if(gix < width && giy < height && giz < depth)
  {
    gidx *= 3;
    out[gidx] = (OUTPIXELTYPE)( (float)out[gidx] + dt*(float)(buf[gidx]) );
    gidx ++;
    out[gidx] = (OUTPIXELTYPE)( (float)out[gidx] + dt*(float)(buf[gidx]) );
    gidx ++;
    out[gidx] = (OUTPIXELTYPE)( (float)out[gidx] + dt*(float)(buf[gidx]) );
  }
}
#endif
