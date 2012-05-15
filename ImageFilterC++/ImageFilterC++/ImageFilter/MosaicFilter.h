/* 
 * HaoRan ImageFilter Classes v0.1
 * Copyright (C) 2012 Zhenjun Dai
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation; either version 2.1 of the License, or (at your
 * option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation.
 */


#if !defined(MosaicFilter_H)
#define MosaicFilter_H

#include "IImageFilter.h"

namespace HaoRan_ImageFilter{

class MosaicFilter : public IImageFilter{
public:
	
	int MosiacSize;

	MosaicFilter() : MosiacSize(4){};

	virtual Image process(Image imageIn)
	{
		int width = imageIn.getWidth();
    	int height = imageIn.getHeight();
        int r = 0, g = 0, b = 0;
        for (int y = 0; y < height; y++) {
        	for (int x = 0; x < width; x++) {	
    	         if ((y % MosiacSize) == 0) { 	        	 
    	       		 if ((x % MosiacSize) == 0){//整数倍时，取像素赋值                      	 
	       			     r = imageIn.getRComponent(x, y);
	    	             g = imageIn.getGComponent(x, y);
		                 b = imageIn.getBComponent(x, y);
		         	 }
    	       		 imageIn.setPixelColor(x, y, r, g, b, true);
    	       	 }
    	       	 else{ //复制上一行      		 
    	             imageIn.setPixelColor(x, y, imageIn.getPixelColor(x, y -1), true);
    	         }
    	    }
   	   }
#ifndef WIN32 //only for apple ios
		clone.copyPixelsFromBuffer();
#endif
       return imageIn;

	}
};

}// namespace HaoRan
#endif