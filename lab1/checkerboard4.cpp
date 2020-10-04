#include"../print.h"
#include"../show_mem.h"

int main() {
  init();

  read_image("small.ppm");

  int width, height;
  get_image_dimensions(width, height);
  for(int row = 0; row < height; row +=3){
    for (int column = 0; column < width; column+=8){
      if (row % 2 == 1 && column == 0) column += 4;
      for (int i = 3 + 3*column + row*width*3; i < (3*width/4) + 3 + 3*column + row*width*3; i+=3){
        unsigned char &r = uchar_at(i - 3);
        unsigned char &g = uchar_at(i - 2);
        unsigned char &b = uchar_at(i - 1);
        r = b = 255;
        g = 0;

        for (int j = i + 3*width; j < (9*width + 3 + 3*column + row*width*3); j+=3*width){
            if(j <= height*width*3){
              unsigned char &r1 = uchar_at(j - 3);
              unsigned char &g1 = uchar_at(j - 2);
              unsigned char &b1 = uchar_at(j - 1);
              r1 = r;
              g1 = g;
              b1 = b;
            }
        }
      }
    }
  }

  write_image("output.ppm");

  quit();
}
