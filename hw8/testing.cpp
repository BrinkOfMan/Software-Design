#include"../print.h"
 
const unsigned SIZE = 9;
 
bool alt(long int val, unsigned short c[])
{
  int val1 = val/1000000000;
  int val2 = val%1000000000;
  for ( int i=2; i<SIZE; i += 3 )
    c[i] -= val1;
  for ( int i=1; i<SIZE; i += 4 )
    c[i] += val2;
  return c[2] > 10;
}
 
void fill(unsigned short a[], char y)
{
  for ( int i=0; i<SIZE; ++i )
    a[i] = y+i;
}
 
int main()
{
  signed char x = 2;
  unsigned short b[SIZE];
  fill(b, x);
  long z;
  bool r = alt(5000000007L, b);
  for ( int i=0; i<SIZE; ++i ) {
    print_unsigned_short(b[i]);
    print(" ");
  }
  print("result: ");
  print_bool(r);
  print("\n");
}
