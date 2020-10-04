#include <iostream>
#include <fstream>
using namespace std;

char * global_mem;
const int mem_size = 1000;

void print_at(int index, const char *s) {
    int i = 0;
    while(s[i] != 0){
    global_mem[index+i] = s[i];
    ++i;
    }
    global_mem[index+i] = 0;
}

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

void write_response(){
    cout.write(global_mem, mem_size - 1);

    ofstream f("out.mem0");  // create file stream object
    f.write(global_mem, mem_size - 1);  
    f.close();
}

void read_request(){
    read_stream(cin, global_mem, mem_size);

    ofstream f("cached_input0");  // create file stream object
    f.write(global_mem, mem_size - 1);  
    f.close();
}

void init_global_mem(){
    global_mem = new char[mem_size];

    for(int i = 0; i < mem_size - 1; ++i) {global_mem[i] = '~';}
    global_mem[mem_size - 1] = 0;
    }

void quit_global_mem(){delete [] global_mem;}

int main(){
  
    init_global_mem();
    read_request();

    if(global_mem[20] == '~') {
        print_at(21, "What file would you like? ");
        global_mem[20] = 'X';
    }
    else {
        ifstream f(global_mem);
        read_stream(f, global_mem + 21, mem_size - 21);
        f.close();
    }

    write_response();
    quit_global_mem();
}