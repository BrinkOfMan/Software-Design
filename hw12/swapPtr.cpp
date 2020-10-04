#include <iostream> // #include"../print.h" will cause an error for cin and cout
using namespace std; // apologies if you would like me to use prints


 
int main() {
  int *p0 = new int;
  *p0 = 5;
  
 
  int *p1 = new int[3];
  p1[0] = 11;
  p1[1] = 12;
  p1[2] = 13;
  
  int *temp;
  temp = p0;
  p0 = p1;
  p1 = temp;

  cout << "*p1==" << *p1 << endl;

  cout << "p0[0]==" << p0[0] << endl << "p0[1]==" << p0[1] << endl;
 
  delete p0;
  delete [] p1;
}
