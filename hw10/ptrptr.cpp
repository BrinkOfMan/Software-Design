#include"../react.h"

int main(){

    int i;
    int *p;
    int **pp;
    i = 5;
    p = &i;
    pp = &p;

    print("\ni is {i}, *p points to {p}, and *pp points to {pp}\n", {{"i", i}, {"p", *p}, {"pp", *pp}} );

    i = 10;

    print("i is now {i}, and *p should hold the same value: {p}\n", {{"i", i},{"p", *p}});

    *p = 15;

    print("i is now {i}, and *p should hold the same value: {p}\n", {{"i", i},{"p", *p}});

    **pp = 20;

    print("i is now {i}, and *p should hold the same value: {p}\n", {{"i", i},{"p", *p}});



}