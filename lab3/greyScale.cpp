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
    
    int meanColor;

    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            meanColor = (image[i][j].red + image[i][j].green + image[i][j].blue) / 3;
            image[i][j].red = meanColor;
            image[i][j].green = meanColor;
            image[i][j].blue = meanColor;
        }
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
