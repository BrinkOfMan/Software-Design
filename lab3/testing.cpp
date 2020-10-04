#include "../react.h"

struct pixel{

    unsigned char red;
    unsigned char green;
    unsigned char blue;

};

int main(){
    init();

    pixel p1;
    p1.red = p1.green = p1.blue = 17;
    int n = p1.red;
    print_int(n);
    print("\n");

    quit();
}
