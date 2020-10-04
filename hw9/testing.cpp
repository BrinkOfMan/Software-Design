#include"../print.h"
 
char y[] = "aeioufigure";
 
void warp() { y[3] -= 7; y[8] -= 11; }
 
char t(short &j) { return y[++j] - 'e'; }
 
int main()
{
  char word[] = "sand";
  print(word); print("\n");
  warp();
  for ( short i=0; i<8; ) {
    long n = t(i);
    word[n] += t(i);
    print(word); print("\n");
  }
}
