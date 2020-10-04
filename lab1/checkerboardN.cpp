#include"../print.h"
#include"../show_mem.h"

int main() {
  init();

  read_image("big.ppm");

  int width, height;
  int N = 8;
  get_image_dimensions(width, height);
  for(int row = 0; row < height; row +=height/N){
    //Will cycle through the rows rectangle height by rectangle height (found by taking height / "N"umber of rectangles)

    for (int column = 0; column < width; column+= width/N*2){
      //Start printing at every other rectangle width

      if (row % 2 == 1  && column == 0) column += width/N;
        //If it's an odd row and ONLY the first time printing in this row, move the first print over by one rectangle width

      for (int i = 3 + 3*column + row*width*3; i < 3 + 3*column + row*width*3 + (3*width/N); i+=3){
        //For each pixel up until the width of a rectangle (3*width/N)

        unsigned char &r = uchar_at(i - 3);
        unsigned char &g = uchar_at(i - 2);
        unsigned char &b = uchar_at(i - 1);
        r = b = 255;
        g = 0;
        //Getting and setting pixel colors to pink

        for (int j = i + 3*width; j < ((height/N)*width*3 + 3 + 3*column + row*width*3); j+=3*width){
          //Will cycle through each row up until the height of a rectangle ((height/N)*width*3
        
            if(j <= height*width*3){
              //Guard for if we are at the image height or not
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

  //This isn't perfect, but it's taken 3 hours of work and I think it works pretty well.
}
