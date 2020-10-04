#include<iostream>
using namespace std;
class Base1 {
  double val;
public:
  Base1() : val(1.0) {}
  double get() { return val; }
};

class Base2 {
  double val;
public:
  Base2() : val(2.0) {}
  virtual double get() { return val; } 
};

class Derived1 : public Base1 {
public:
  double get() { return 10; }
};

class Derived2 : public Base2 {
public:
  double get() { return 20; }
};

int main() {
  Derived1 d1;
  Derived2 d2;
  Base1 *b1p;
  Base2 *b2p;
  b1p = &d1;
  b2p = &d2;
  cout << "d1.get " << d1.get();
  cout << " d1 size " << sizeof(d1) << endl;
  cout << "d2.get " << d2.get();
  cout << " d2 size " << sizeof(d2) << endl;
  cout << "b1p->get " << b1p->get();
  cout << " b1p size " << sizeof(b1p) << endl;
  cout << "b2p->get " << b2p->get();
  cout << " b2p size " << sizeof(b2p) << endl;
}
