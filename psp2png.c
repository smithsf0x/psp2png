//smithsf0x

#include "psp2png.h"

uint32_t r, g, b, a;
uint32_t x, y;

static void pngDraw(char* image, int x_offset, int y_offset){

  for (y = 0; y < h; y++){
    for (x = 0; x < w; x++){
        r = image[4 * y * w + 4 * x + 0];
        g = image[4 * y * w + 4 * x + 1];
        b = image[4 * y * w + 4 * x + 2];
        a = image[4 * y * w + 4 * x + 3];
        draw_pixel(x+x_offset, y+y_offset, RGBA8(r, g, b, a));
    }
  }
}
