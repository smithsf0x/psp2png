// smithsf0x

#include "draw.h"
#include "lodepng.h"

typedef struct {
  unsigned char* picture;
  unsigned w, h;
}pngImage;

uint32_t r, g, b, a;
uint32_t x, y;

static void pngDraw(char* image, int x_offset, int y_offset);
