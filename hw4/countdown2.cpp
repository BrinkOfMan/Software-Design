#include"../print.h"

int main() {
  print("Countdown:\n10\n");
  for (int i = 9; i > 0; --i) {
    if (i == 3) {
      continue;
    }
    print_int(i);
    print("\n");
  }
  print("Blastoff!!!\n");
}

