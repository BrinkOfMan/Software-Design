#include<iostream>
using namespace std;

class Veggie {
  char *name;
  int calories;
public:
  Veggie(int c) : calories(c) {name = 0;}
  Veggie(const char *n, int c) : calories(c) {
    int len = 0;
    while (n[len++]) { }
    name = new char[len + 1];
    for (int i = 0; i < len + 1; ++i)
      name[i] = n[i];
  }
  void print() {
    if (name) cout << name << " calories " << calories << endl;
    else cout << calories << endl;
  }
  ~Veggie() {
    if (name) cout << "deallocating " << name << endl;
    delete [] name;
  }
};

int main() {
  Veggie a("asparagus", 42);
  Veggie b("broccoli", 33);
  Veggie c(10);
  Veggie* d[4];
  d[0] = &a;
  d[1] = &b;
  d[2] = &c;
  Veggie **e = d;
  e[2]->print();  // first line of output;  where are the others?
}
