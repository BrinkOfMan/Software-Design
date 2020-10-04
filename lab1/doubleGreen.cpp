#include"../print.h"
#include"../show_mem.h"

int main() {
  init();

  read_image("small.ppm");

  int width, height;
  get_image_dimensions(width, height);
  for (int i = 3; i < 3*width*height+3; i+=3){
    unsigned char &g = uchar_at(i - 2);
    g = uchar_at(i - 2) * 2;
    //ignoring the fact that the green value can go over 255
  }
  write_image("output.ppm");

  quit();
}
