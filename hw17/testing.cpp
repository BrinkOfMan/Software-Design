#include<iostream>
using namespace std;
 
class Measurement {
  int shoesize;
  double height;

public:
  Measurement(int s, double h) { shoesize = s; height = h; }
  double get_height() { return height; }
};
 
class Hobbit {
  Measurement m;
  Hobbit *buddy;

public:
  Hobbit(int shoe, double ht) : m(shoe, ht) { }
  Hobbit *get_buddy() { return buddy; }
  void set_buddy(Hobbit *b) { buddy = b; }
  double get_height() { return m.get_height(); }
};
 
int main()
{
  Hobbit pippin{7, 42}, merry{8, 41.5};
  pippin.set_buddy(&merry);
  merry.set_buddy(&pippin);
 
  cout << "Pippin's buddy has height " << pippin.get_buddy()->get_height() << endl;
}
