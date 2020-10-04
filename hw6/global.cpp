#include"../print.h"

int earth_globe = 0;

void third(int d){
    earth_globe++;
    d++;
    print("local a is now "); print_int(d);

}

void second(int c){
    earth_globe++;
    third(c+1);
}

void first(int b){
    earth_globe++;
    second(b+1);
}

int main(){
    int a = 0;
    print("I made a = 0, and will adding 1 three times to the local a and globe_earth.");
    print("They should calculate to be the same thing\n");

    first(a);

    print("\nglobal earth_globe is now "); print_int(earth_globe); print("\n");
}