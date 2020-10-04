#include <iostream>
using namespace std;

void swap(double &a, double &b){
  double tmp = a;
  a = b;
  b = tmp;
}

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void swap(float &a, float &b) {
  float tmp = a;
  a = b;
  b = tmp;
}

int main() {
  double a = 9.4, b = 4.2;
  int i = 7, j = 8;
  float x = 5.2, y = 6.3;
  
  cout << "Before swapping:\n a: " << a << " i: " << i << " x: " << x << endl;

  swap(x, y);
  swap(a, b);
  swap(i, j);

  cout << "After swapping:\n a: " << a << " i: " << i << " x: " << x << endl;
  return 0;
}
