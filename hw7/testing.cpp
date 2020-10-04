#include"../print.h"

int change_one(double k[]) {
  k[1] = 7;
  return 3;
}

int main() {
  double j[] = {2.2, 3.3, 4.4};
  int n = change_one(j);
  print_double(j[1]);  // prints 7-- why?
}
