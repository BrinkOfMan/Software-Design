#include<iostream>
using namespace std;

char * global_mem;
const int mem_size = 10000;

void print_at(int index, const char *s) {
    int i = 0;
    while(s[i] != 0){
    global_mem[index+i] = s[i];
    ++i;
    }
    global_mem[index+i] = 0;
}

int main() {
  global_mem = new char[mem_size];
  for (int i = 0; i < mem_size-1; ++i) global_mem[i] = '~';
  global_mem[mem_size-1] = 0; 
    
  print_at(5, "hello\n");
  cout << (global_mem + 3) << endl;  // output should be ~~hello

  delete [] global_mem;
}
