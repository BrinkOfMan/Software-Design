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

    int row = 0;
    for(int r = 0; r < height; r += height/4){
        ++row;
        for(int c = 0; c < width; c += 2*(width/4)){
            if (row % 2 == 1 && c == 0) c += width/4;
            //These next two loops create the rectangle
            for(int i = c; i < width/4 + c; ++i){

                for(int j = r; j < height/4 + r; ++j){
                    
                    if(j < height && i < width){
                        //Guard for if the rectangle will go outside of the screen limits
                        image[j][i].red = image[j][i].blue = 255;
                        image[j][i].green = 0;
                    }
                }
            }
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
