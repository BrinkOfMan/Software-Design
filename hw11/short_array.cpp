#include"../react.h"

int main() {
  init();

  short &i = short_at(20);
  short &j = short_at(22);
  short &k = short_at(24);
  i = 1;
  j = 2;
  k = 3;

  short *arr = reinterpret_cast<short *>(global_mem + 20);
  print_short(arr[0]);
  print_short(arr[1]);
  print_short(arr[2]);

  quit();
}
