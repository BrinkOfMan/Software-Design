#include <iostream>
#include <fstream>
using namespace std;

char * global_mem;
const int mem_size = 10000;

void read_stream(istream &f, char *array, int max_size) {
  int num_bytes;
  if (f.good()) {
    f.read(array, max_size);
    if (f) {
      cerr << "Warning in read_stream:  did not reach end of stream after " << max_size << " characters.";
      num_bytes = max_size - 1;
    } else {
      num_bytes = f.gcount();
      if (num_bytes >= max_size) num_bytes = max_size - 1;
    }
  } else {
    cerr << "Warning in read_stream: unable to read anything\n";
    num_bytes = 0;
  }
  array[num_bytes] = 0;  // assign null at end
}

void print_at(int index, const char *s) {
    int i = 0;
    while(s[i] != 0){
    global_mem[index+i] = s[i];
    ++i;
    }
    global_mem[index+i] = 0;
}

void client(){
  
  if(global_mem[20] != '~') cout << global_mem + 21 << endl;
  cin.getline(global_mem, 20);
}

void server(){
  
  if(global_mem[20] == '~') {
    print_at(21, "What file would you like? ");
    global_mem[20] = 'X';
  }
  else {
    ifstream f(global_mem);
    read_stream(f, global_mem + 21, mem_size - 21);
    f.close();
  }
}

void init_global_mem(){
  global_mem = new char[mem_size];

  for(int i = 0; i < mem_size - 1; ++i) {global_mem[i] = '~';}
  global_mem[mem_size - 1] = 0;
}

void quit_global_mem(){delete [] global_mem;}

int main() {
  init_global_mem();
  while(1) {
    server();
    client();
  }
  quit_global_mem();
}

