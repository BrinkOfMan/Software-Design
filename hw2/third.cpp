#include"../show_mem.h"  // change the include
//It was so obviously there, but I didn't think to use it

int main() {

    init();

    unsigned short &z1 = unsigned_short_at(0);
    z1 = 3;
    unsigned short &z2 = unsigned_short_at(2);
    z2 = 4;
    long &k = long_at(4);
    k = 5;
    char &y =  char_at(12);
    y = 65;

    quit();

}
