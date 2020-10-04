#include<fstream>
using namespace std;

int length_of(const char *s) {
  int len = 0;
  while(0 != s[len]) ++len;
  return len;
}

int main() {
  char greeting[] = "hello everybody!\n";
  greeting[5] = 0;
  int n = length_of(greeting);
  

  ofstream f("a.txt");  // create file stream object
  f.write(greeting, n);  
  f.close();
}
