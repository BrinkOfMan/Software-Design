#include"../print.h"
#include"../show_mem.h"

int main() {
  init();

  read_image("small.ppm");

  int width, height;
  get_image_dimensions(width, height);
  for (int i = 3; i < (3*width/4) + 3; i+=3){
    unsigned char &r = uchar_at(i - 3);
    unsigned char &g = uchar_at(i - 2);
    unsigned char &b = uchar_at(i - 1);
    r = b = 255;
    g = 0;

  }
  write_image("output.ppm");

  quit();
}
