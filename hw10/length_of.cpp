#include"../print.h"

int length_of(const char *array){

    int counter = 0;

    while(array[counter] != 0){
        counter++;
    }

    return counter;
}

int main(){

    char a[] = "hello";
    print("\n");
    print_int(length_of(a));
    print("\n");

    return 0;
}