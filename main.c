/*
 * Copyright (c) 2015 Sergi Granell (xerpi)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include <psp2/display.h>
#include <psp2/types.h>
#include <psp2/moduleinfo.h>

#include <psp2/io/fcntl.h>
#include <psp2/io/dirent.h>

#include "defines.h"
#include "draw.h"
#include "lodepng.h"

PSP2_MODULE_INFO(0, 0, "loadepngtest")

int main()
{
	init_video();

  	unsigned char* image;
	unsigned w, h;
  	uint32_t r, g, b, a;
  	uint32_t x, y;

	unsigned error = lodepng_decode32_file(&image, &w, &h, "pss0:/top/Documents/test.png");


	while (1) {
		clear_screen();
  		for (y = 0; y < h; y++){
    		for (x = 0; x < w; x++){
      			r = image[4 * y * w + 4 * x + 0]; /*rot */
      			g = image[4 * y * w + 4 * x + 1]; /*grün */
      			b = image[4 * y * w + 4 * x + 2]; /*blau */
      			a = image[4 * y * w + 4 * x + 3]; /*alpha */
				draw_pixel(x, y, RGBA8(r, g, b, a));
    		}
		}

		if(error) {
			draw_rectangle(200, 200, 40,  40, GREEN);
		}

		swap_buffers();
		sceDisplayWaitVblankStart();
	}
	free(image);
	end_video();
	return 0;
}
