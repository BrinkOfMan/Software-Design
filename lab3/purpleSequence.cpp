#include"../react.h"

struct Pixel{

    unsigned char red;
    unsigned char green;
    unsigned char blue;

};

int main()
{
    init();

    Pixel ** image;

    int width, height;
    get_image_dimensions("small.ppm", width, height);

    
    
    image = new Pixel *[height];
    //This will allocate (height) Pixel * s of memory to use

    for (int i = 0; i < height; ++i)
        image[i] = new Pixel[width];
        //This will allocate (width) Pixels of memory for each Pixel *

    read_image("small.ppm", reinterpret_cast<char **>(image), width, height);
    

    for(int i = 0; i < width/4; ++i){
  
        image[0][i].red = image[0][i].blue = 255;
        image[0][i].green = 0;
    }

    write_image("output.ppm", reinterpret_cast<char **>(image), width, height);
    //Produce an image of width and height

    for (int i = 0; i < height; ++i) 
        delete [] image[i];
        //Deleting every scanline Pixel *

    delete [] image;
    //Deleting the Pixel **

    quit();
}
