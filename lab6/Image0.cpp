#include <iostream>
using namespace std;

class Image0{
    int width;
    int height;

public:

    Image0(int w, int h){ width = w; height = h;}

    int getWidth(){return width;}

    int getHeight(){return height;}

};


int main(){

    Image0 picture(160, 90);
    Image0 photograph(240, 170);

    cout << picture.getWidth() << endl;
    cout << photograph.getHeight() << endl;
    return 0;
}