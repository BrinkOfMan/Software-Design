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

void client(bool first, char fname[]){
  
  if(!first) cout << global_mem << endl;
  cin.getline(fname, 20);
}

void server(bool first, char fname[]){
  
  if(first) cout << "What file would you like?" << endl;
  else {
    ifstream f(fname);
    read_stream(f, global_mem, mem_size);
    f.close();
  }
}

int main() {
  global_mem = new char[mem_size];

  for(int i = 0; i < mem_size - 1; ++i) {global_mem[i] = '~';}
  global_mem[mem_size - 1] = 0;

  bool first_time = true;
  char fname[20];

  while(1) {
    server(first_time, fname);
    client(first_time, fname);
    first_time = false;
  }

  /*char fname[20];
  char content[1000];

  bool first_time = true;
  while(1) {
    if (first_time) {
      cout << "What file would you like? ";
    }
    if (!first_time) {
      cout << content << endl;
    }
    cin.getline(fname, 20);
    read_file(fname, content, 20);
    first_time = false;
    
  }*/

  delete [] global_mem;
}
