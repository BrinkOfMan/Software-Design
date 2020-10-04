#include"../show_mem.h"  // change the include

int main() {
  init();  // get ready to visualize memory

  short &s = short_at(0);  // create variable at a specified index
  s = 6502;                //   then assign its value
  char &c1 = char_at(2);   // similarly here
  c1 = 106;
  char &c2 = char_at(3);
  c2 = 111;
  unsigned int &n = unsigned_int_at(4);
  n = 1000000;
  long &m = long_at(8);
  m = 1000000000000L;      // the L means the number is long
  double &d = double_at(16);
  d = 3.1415926532389;
  float &f = float_at(24);
  f = 5.2;

  quit();  // send memory to the browser for display
}
