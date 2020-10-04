#include<iostream>
using namespace std;

void f(char *s) {
  s[0] = '>';
  s[1] = ' ';
  cout << s << endl;
  delete [] s;
}

int main() {
  char *t = new char[4];
  t[0] = '_';
  t[1] = '_';
  t[2] = ':';
  t[3] = 0;

  cout << t << endl;
  f(t);
  delete [] t;
}
