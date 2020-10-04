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
  Food(bool t, long long time) : takeout(t), order_time(time) {}
  void print_takeout() { cout << " takeout " << takeout << " order time " << order_time << endl; }
};

class Nachos : public Food {
public:
  Nachos(bool t) : Food(t, 700LL) { }
  void print_order() { cout << "Nachos: "; print_takeout(); }
};

class Quesadilla : public Food {
protected:
  bool is_half, just_cheese;

public:
  Quesadilla(bool t, bool h, bool c) : Food(t), is_half(h), just_cheese(c) { }
  void print_order() { cout << "Quesadilla:  is_half " << is_half << " just_cheese " << just_cheese; print_takeout(); }
};

class Chicken_Quesadilla : public Quesadilla {
public:
  Chicken_Quesadilla(bool t, bool h) : Quesadilla(t, h, false) {}
  void exist(){ cout << "Yes, I, a chicken quesadilla, do exist.\n";}
};

class Ice_Cream : public Food {
  char kind;  // 'C' chocolate, 'V' vanilla, 'T' twist

public:
  Ice_Cream(bool t, char k) : Food(t), kind(k) { }
  void print_order() { cout << "Ice Cream:  kind " << kind; print_takeout(); }
};

int main() {
  Nachos n1(false);
  Chicken_Quesadilla cq(false, true);
  Ice_Cream i1(true, 'V'), i2(false, 'T');

  n1.print_order();
  cq.exist();
  cq.print_order();
  i2.print_order();
}
