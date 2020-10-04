#include"../print.h"
#include"../show_mem.h"

int main() {
  init();

  read_image("small.ppm");

  int width, height;
  get_image_dimensions(width, height);

  unsigned char &r = uchar_at(3*width*height - 3);
  unsigned char &g = uchar_at(3*width*height - 2);
  unsigned char &b = uchar_at(3*width*height - 1);
  r = b = 0;
  g = 255;

  write_image("output.ppm");

  quit();
}
