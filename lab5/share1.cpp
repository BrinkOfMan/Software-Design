#include <iostream>
#include <fstream>
using namespace std;

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

int main() {
  char fname[20];
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
    
  }
}
