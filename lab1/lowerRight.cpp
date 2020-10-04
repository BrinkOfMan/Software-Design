#include"../print.h"
#include"../show_mem.h"

int main() {
  init();

  read_image("small.ppm");

  int width, height;
  get_image_dimensions(width, height);
  print("width is"); print_int(width); print("\n");

  unsigned char &r = uchar_at(3*width*height - 3);
  unsigned char &g = uchar_at(3*width*height - 2);
  unsigned char &b = uchar_at(3*width*height - 1);
  r = b = 255;
  g = 0;

  write_image("output.ppm");

  quit();
}
