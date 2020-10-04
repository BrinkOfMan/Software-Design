#include <iostream>
#include <fstream>
using namespace std;

char *global_mem;

int main(){

    char fname[] = "/usr/local/cs/cs251/chat/data/ethan.txt";

    global_mem = new char[10000];
    for(int i = 0 ; i < 10000; ++i){
        if((i - 99) % 100 == 0) { global_mem[i] = '\n'; }
        else { global_mem[i] = '~'; }
    }
    global_mem[10] = 0;

    ofstream f(fname);
    f.write(global_mem, 10000);
    f.close();
    

}