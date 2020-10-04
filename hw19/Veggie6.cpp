#include<iostream>
using namespace std;

class Veggie {
protected:
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
    if (name) cout << name << " calories " << calories;
    else cout << calories << endl;
  }
  ~Veggie() {
    if (name) cout << "deallocating " << name << endl;
    delete [] name;
  }
};

class Information : public Veggie{
  int price;
  int temperature;
public:
  Information(int p, int temp, const char* name, int cal) : price(p), temperature(temp), Veggie(name, cal) {} 
  void showInfo(){
      print(); cout << " price " << price << " keep at a temperature around " << temperature << " degrees celcius" << endl;
  }
};

class Animation : public Veggie{
  int scale;
  int orientation; 
public:
  Animation(int s, int o, const char* name, int cal) : scale(s), orientation(o), Veggie(name, cal) {}
  void showAnimation(){
      print(); cout << " scale " << scale << " show at orientation " << orientation << " degrees" << endl;
  }
};

int main() {
  Veggie a("asparagus", 42);
  Veggie b("broccoli", 33);
  Veggie c(10);
  Veggie w; 
  b = w = a;
  Veggie* d[4];
  d[0] = &a;
  d[1] = &b;
  d[2] = &c;
  d[3] = &w;
  Veggie **e = d;

  cout << "Printing the asparagus Veggie\n";
  e[0]->print();  // first line of output;  where are the others?
  
  cout << "\nTesting the multiple = assignment operators\n";
  e[1]->print();
  cout << "\n";
  e[3]->print();
  cout << "\n";

  Information carrotInfo(2, 5, "carrot", 37);
  carrotInfo.showInfo();

  Animation carrotAnimation(3, 90, "carrot", 37);
  carrotAnimation.showAnimation();
}
