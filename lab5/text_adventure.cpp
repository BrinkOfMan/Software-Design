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

  const char *start = "start.  choose 1 or 2. ";
  const char *option[] = {"option1. choose? ", "option2. choose? ", "option11. (restart) ", "option12. (restart) ", "option21. (restart) ", "option22. (restart) "};
  
  if ('~' == global_mem[20] || global_mem[20] > 2) {
    print_at(21, start);
    global_mem[20] = 0;
  }

  else {
    int state = global_mem[20];
    if ('1' == global_mem[0]) {
      print_at(21, option[2*state + 0]);
      global_mem[20] = 2*state + 1;
    } 
    
    else if ('2' == global_mem[0]) {
      print_at(21, option[2*state + 1]);
      global_mem[20] = 2*state + 2;
    } 
    
    else {
      print_at(21, "please choose 1 or 2.\n");
    }
  }

  write_response();
  quit_global_mem();

  //Looks like at the call to read_request(), the input from the user is being put into global_mem[0]
  //The user input is then ran through a cnonditional to check if it's 1, 2, or neither, and the corresponding prompt index in *option is printed out, before changing the value of state and outputting to out.mem0
  //The memory location state is stored at is used for the looping conditional (if state goes above 2 (which it should after the second choice is made)); the first time it goes through, state will be changed to either 1 or 2, the second time through 3, 4, 5, or 6. 
}