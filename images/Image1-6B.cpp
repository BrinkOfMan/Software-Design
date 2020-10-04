#include <iostream>
#include"../react.h"
using namespace std;

struct Pixel{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

class Image1{
    int width;
    int height;
    int depth = 255;;
    Pixel ** image;

public:

    Image1(int w, int h){ 
        width = w; height = h;
        image = new Pixel *[height];
    //This will allocate (height) Pixel * s of memory to use

    for (int i = 0; i < height; ++i)
        image[i] = new Pixel[width];
        //This will allocate (width) Pixels of memory for each Pixel *
    }

    ~Image1(){
        for (int i = 0; i < height; ++i) 
        delete [] image[i];
        //Deleting every scanline Pixel *

        delete [] image;
        //Deleting the Pixel **
    }

    int getWidth(){return width;}

    int getHeight(){return height;}

    void print(){
        cout << "P6\n";
        cout << width << " " << height << endl;
        cout << depth << endl;
        for(int h = 0; h < height; ++h){
            cout.write(reinterpret_cast<char *>(image[h]), width*3);

        }
    }

};

int main(){

    Image1 picture(3, 2);
    Image1 photograph(240, 170);

    picture.print();
    
    return 0;

}

