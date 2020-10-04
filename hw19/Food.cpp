#include<iostream>
using namespace std;
#include<chrono>  // used for get_current_time()
#include<sys/stat.h>  // used for get_current_time()

long long get_current_time() 
{
  using namespace std::chrono;
  long long ms = duration_cast< milliseconds >(
    system_clock::now().time_since_epoch()
  ).count();
  return ms;
}

class Food {
protected:
  bool takeout;
  long long order_time;

public:
  Food(bool t) : takeout(t) { order_time = get_current_time(); }
  void print_takeout() { cout << " takeout " << takeout << endl; }
};

class Nachos : public Food {
public:
  Nachos(bool t) : Food(t) { }
  void print_order() { cout << "Nachos: "; print_takeout(); }
};

class Quesadilla : public Food {
  bool is_half, just_cheese;

public:
  Quesadilla(bool t, bool h, bool c) : Food(t), is_half(h), just_cheese(c) { }
  void print_order() { cout << "Quesadilla:  is_half " << is_half << " just_cheese " << just_cheese; print_takeout(); }
};

class Ice_Cream : public Food {
  char kind;  // 'C' chocolate, 'V' vanilla, 'T' twist

public:
  Ice_Cream(bool t, char k) : Food(t), kind(k) { }
  void print_order() { cout << "Ice Cream:  kind " << kind; print_takeout(); }
};

int main() {
  Nachos n1(false);
  Ice_Cream i1(true, 'V'), i2(false, 'T');

  i2.print_order();
}
