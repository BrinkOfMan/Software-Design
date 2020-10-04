#include"../react.h"

void append(char *c0, char *c1){

    int start = length_of(c0);
    print_int(start);
    print("\n");
    int i;
    for(i = 0; i < length_of(c1); i++){
        c0[start+i] = c1[i];
    }
    c0[i+start] = 0;
}

int main(){

    char a[15];
    a[0] = 'W';
    a[1] = 0;

    int i;

    char b[] = "bye";

    append(a, b);

    for(i = 0; i < length_of(a); i++){
        print_char(a[i]);
    }
    print("\n");
    
    append(a, b);
    for(i = 0; i < length_of(a); i++){
        print_char(a[i]);
    }
    print("\n");

}
