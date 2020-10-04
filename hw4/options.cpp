#include"../print.h"

int main() {
  print("Please enter a small integer: ");
  int n = input_int();  // get input from the user
  if (n % 3 == 0) {
    print("This integer is divisible by three!\n");
  } else if (n % 3 == 1) {
    print("This integer has a remainder of one, when divided by three.\n");
  } else {
    print("This integer has a remainder of two, when divided by three.\n");
  }
}
