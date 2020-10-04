#include"../print.h"

struct Town {
  double total_pizza;
  int num_inhabitants;
  int num_protesters;
};

void reset(double &r)
{
  r *= 0.5;
}

int main()
{
  Town northfield {500000, 20007, 700};
  Town faribault {400000, 23750, 10};
  Town *t0 = &northfield;
  Town *t1 = &faribault;
  t0->num_protesters += 10;
  t1->num_inhabitants -= 10;
  reset(t0->total_pizza);
  print_double(northfield.total_pizza);
  print("\n");
}
