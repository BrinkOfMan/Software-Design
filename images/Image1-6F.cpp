#include <iostream>
#include <fstream>
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

    Image1(const char * filename){
        ifstream f(filename);
        char name[3];
        f >> name;
        f >> width >> height;

        image = new Pixel *[height];
        //This will allocate (height) Pixel * s of memory to use

        for (int i = 0; i < height; ++i)
            image[i] = new Pixel[width];
            //This will allocate (width) Pixels of memory for each Pixel *

        f >> depth;

        f.get();
        for(int h = 0; h < height; ++h){f.read(reinterpret_cast<char *>(image[h]), width*3);}
        f.close();  
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

    void zeroRed(){
        for(int i = 0; i < height; ++i){
            for(int j = 0; j < width; ++j)
                image[i][j].red = 0;
        }
    }

    void grayScale(){
        int meanColor;
        for(int i = 0; i < height; ++i){
            for(int j = 0; j < width; ++j){
                meanColor = (image[i][j].red + image[i][j].green + image[i][j].blue) / 3;
                image[i][j].red = meanColor;
                image[i][j].green = meanColor;
                image[i][j].blue = meanColor;
            }
        }
    }

    void horizSqueeze(){

        Pixel **img;

        img = new Pixel *[height];
        //This will allocate (height) Pixel * s of memory to use

        for (int i = 0; i < height; ++i){
            img[i] = new Pixel[width / 2];
            //This will allocate (width / 2) Pixels of memory for each Pixel *
        }
        
        //grab every other pixel from the original scanlines
        for(int h = 0; h < height; ++h){
            for(int w = 0; w < width / 2; ++w){
                img[h][w].red = image[h][w*2].red;
                img[h][w].green = image[h][w*2].green;
                img[h][w].blue = image[h][w*2].blue;
            }
        }

        //Release the scanlines from the old image
        for(int h = 0; h < height; ++h){delete [] image [h];}

        //Change width to half its original size
        width /= 2;
        //Create a new sequence of scanlines with half their original width
        for (int i = 0; i < height; ++i){image[i] = new Pixel[width];}

        for(int h = 0; h < height; ++h){
            for(int w = 0; w < width; ++w){
                image[h][w].red = img[h][w].red;
                image[h][w].green = img[h][w].green;
                image[h][w].blue = img[h][w].blue;
            }
        }

        //Release all of img
        for(int h = 0; h < height; ++h){
            delete [] img [h];
        }

        delete [] img;
                
    }

    void addBorder(){
        for(int h = 0; h < height; ++h){

            if(h == 0 || h+1 == height){
                for(int w = 0; w < width; ++w){
                    image[h][w].red = 85;
                    image[h][w].green = 52;
                    image[h][w].blue = 43;
                }
            }

            else{
                image[h][0].red = 85; image[h][width-1].red = 85;
                image[h][0].green = 52; image[h][width-1].green = 52;
                image[h][0].blue = 43; image[h][width-1].blue = 43;
            }
            
        }
    }

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


    Image1 testPPM("small.ppm");
    testPPM.addBorder();

    testPPM.print();
    
    return 0;

}

