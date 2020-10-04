#include"../show_mem.h"

int main() {
  init();

  read_image("small.ppm");

  unsigned char &r = uchar_at(0);
  unsigned char &g = uchar_at(1);
  unsigned char &b = uchar_at(2);
  r = b = 200;
  g = 0;

  write_image("output.ppm");
  quit();
}
