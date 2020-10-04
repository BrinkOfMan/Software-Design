#include"../print.h"
int prod_many(int x1, int x2, int x3 = 1, int x4 = 1) {
  int result = x1 * x2 * x3 * x4;
  return result;
}

int main()
{
  int num = 2;
  int num1 = 3;
  int num2 = 6;
  print("Printing the product of 2, 3, and 6: ");
  print_int(prod_many(num, num1, num2));  print("\n");
}
