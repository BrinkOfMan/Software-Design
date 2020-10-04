#include <iostream>
#include <fstream>
using namespace std;

char *global_mem;

void display_messages(int num_messages){
  cout << endl;
  
  for(int index = 1; index <= num_messages; ++index){
    // Author
    int i = 0;
    while(global_mem[index*100 + 9 + i] != 0) { cout << global_mem[index*100 + 9 + i]; ++i; }
    cout << ": ";

    // Message
    i = 0;
    while(global_mem[index*100 + 20 + i] != 0) { cout << global_mem[index*100 + 20 + i]; ++i; }
    cout << endl;
  }
}

void write_message(int index, const char *auth, const char *msg){
  int i = 0;
  while(auth[i] != 0) {
    global_mem[index+i+9] = auth[i];
    ++i;
  }
  global_mem[index+i+9] = 0;

  i = 0;
  while(msg[i] != 0) {
    global_mem[index+i+20] = msg[i];
    ++i;   
  }
  global_mem[index+i+20] = 0;
}

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

void read_file(const char *fname, char *array, int max_size) {
  ifstream f(fname);
  read_stream(f, array, max_size);
  f.close();
}

int main(int argc, char **argv){

    char fname[] = "/usr/local/cs/cs251/chat/data/ethan.txt";
    
    global_mem = new char[10000];
    read_file(fname, global_mem, 10001);

    if(argc != 2){
        cerr << "Usage: ./chat3 <username>\n"; 
        return 0;
    }

    else {
        while(1){
          
          char message[80];
          display_messages(global_mem[10]);
          cout << argv[1] << "> ";
          
          cin.getline(message, 80);
          
          read_file(fname, global_mem, 10001);         
          if(message[0] != 0) {
            global_mem[10]++;
            write_message(100*global_mem[10], argv[1], message);
          }

          ofstream f(fname);
          f.write(global_mem, 10000);
          f.close();
        }
        
    }
}

/*
ethan: Hello?
ethan: Anybody there?
NotTim: I am
ethan: I wonder who you could be
NotTim: Definitely not Timothy Roback
ethan: Alright
Abby: hellooo peeps
ethan: thanks for helping
ethan> 
*/