#include <iostream>
#include <fstream>
using namespace std;

char *global_mem;

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
        cerr << "Usage: ./chat2 <username>\n"; 
        return 0;
    }

    else {
        while(1){
            char message[80];
            cout << static_cast<int>(global_mem[10]) << endl;
            cout << argv[1] << "> ";
            cin.getline(message, 80);
            
            read_file(fname, global_mem, 10001);
            
            if(message[0] != 0) { global_mem[10]++; }
            
            ofstream f(fname);
            f.write(global_mem, 10000);
            f.close();
        }
        
    }
}
/*
output:
0
Ethan> hello there
2
Ethan> test 1
3
Ethan> test 2
4
Ethan> test 3
5
Ethan> Abby typed hello before I typed hello there, and world after I typed test 3
7
Ethan>
*/