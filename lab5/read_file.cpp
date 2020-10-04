#include<iostream>
#include<fstream>
using namespace std;

int length_of(const char *s) {
  int len = 0;
  while(0 != s[len]) ++len;
  return len;
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

int main() {
  char room[50];
  read_file("a.txt", room, 50);
  cout << length_of(room) << " bytes.\n";
}
