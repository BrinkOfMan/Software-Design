#include<iostream>
using namespace std;

class Veggie {
  char *name;
  int calories;
public:
  Veggie() : calories(0) {name = 0;}
  Veggie(int c) : calories(c) {name = 0;}
  Veggie(const char *n, int c) : calories(c) {
    int len = 0;
    while (n[len++]) { }
    name = new char[len + 1];
    for (int i = 0; i < len + 1; ++i)
      name[i] = n[i];
  }

  Veggie &operator=(const Veggie &v) { // Copy constructor
    calories = v.calories;
    delete [] name;
    int len = 0;
    while (v.name[len++] != 0) {}
    name = new char[len];
    for (int i = 0; i < len; ++i) name[i] = v.name[i];
    return *this;
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
  Veggie w; 
  w = a;
  Veggie* d[4];
  d[0] = &a;
  d[1] = &b;
  d[2] = &c;
  d[3] = &w;
  Veggie **e = d;
  cout<< "Printing the asparagus Veggie\n";
  e[0]->print();  // first line of output;  where are the others?
  cout << "\nTesting the copy of asparagus\n";
  e[3]->print();
}
