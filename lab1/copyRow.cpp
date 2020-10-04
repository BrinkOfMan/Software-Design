#include"../print.h"
#include"../show_mem.h"

int main() {
  init();

  read_image("small.ppm");

  int width, height;
  get_image_dimensions(width, height);
  for (int i = 3; i < 3*width + 3; i+=3){
    unsigned char &r = uchar_at(i - 3);
    unsigned char &g = uchar_at(i - 2);
    unsigned char &b = uchar_at(i - 1);
    unsigned char &r1 = uchar_at(i - 3 + width*3);
    unsigned char &g1 = uchar_at(i - 2 + width*3);
    unsigned char &b1 = uchar_at(i - 1 + width*3);
    r1 = r;
    g1 = g;
    b1 = b;
  }
  write_image("output.ppm");

  quit();
}
