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

    const int h = 16; //This will be the #scanlines (rows) in the image
    const int w = 16; // This will be the #columns in the image
    
    
    image = new Pixel *[h];
    //This will allocate (height) Pixel * s of memory to use

    for (int i = 0; i < h; ++i)
        image[i] = new Pixel[w];
        //This will allocate (width) Pixels of memory for each Pixel *

    
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            image[i][j].red = (j % 5) * 50;
            image[i][j].green = (i % 5) * 50;
            image[i][j].blue = (i * j) % 256;
        }
    }

    write_image("output.ppm", reinterpret_cast<char **>(image), w, h);
    //Produce an image of width and height

    for (int i = 0; i < h; ++i) 
        delete [] image[i];
        //Deleting every scanline Pixel *

    delete [] image;
    //Deleting the Pixel **

    quit();
}
