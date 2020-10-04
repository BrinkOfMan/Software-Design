#include"../react.h"

int main(){

    short s = 0;
    int i = 0;
    double d = 0;

    print("\nsize of s is {s} bytes, size of i is {i} bytes, size of d is {d} bytes\n", {{"s",sizeof(s)}, {"i",sizeof(i)}, {"d",sizeof(d)}});

    short *ps = &s;
    int *pi = &i;
    double *pd = &d;

    print("\nsize of ps is {s} bytes, size of pi is {i} bytes, size of pd is {d} bytes\n", {{"s",sizeof(ps)}, {"i",sizeof(pi)}, {"d",sizeof(pd)}});


    return 0;
}