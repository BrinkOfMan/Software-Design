#include <iostream>
#include <fstream>
#include <stdio.h>
#include<sys/stat.h>
#include<sys/time.h>
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

void read_file(const char *fname, char *array, int max_size) {
  ifstream f(fname);
  read_stream(f, array, max_size);
  f.close();
}

void print_at(int index, const char *s) {
    int i = 0;
    while(s[i] != 0){
    global_mem[index+i] = s[i];
    ++i;
    }
    global_mem[index+i] = 0;
}

void pause(float p)
{
  timespec t;
  t.tv_sec = (int)p;
  p -= (int)p;
  t.tv_nsec = (long)(1000000000 * (double)p);

  nanosleep(&t, 0);
}

bool file_exists(const char *fname) {
  struct stat sb;   
  return stat(fname, &sb) == 0;
}

#include <stdio.h>
void delete_file(const char *fname) {
  remove(fname);
}


void talk_to_server() {
    ofstream q(".request");
    q.write(global_mem, mem_size - 1);
    q.close();

    while(1) {
        pause(0.25);
        if (!file_exists(".request")) {
        read_file(".response", global_mem, mem_size);
        delete_file(".response");
        return;
        }
    }
}


void talk_to_user(){
  
    if(global_mem[20] != '~') cout << global_mem + 21 << endl;
    cin.getline(global_mem, 20);
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
        talk_to_server();
        talk_to_user();
    }
    quit_global_mem();
}

