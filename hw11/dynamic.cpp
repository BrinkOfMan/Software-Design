#include "../print.h"

int main(){
  
  int n;

  print("Enter an integer. I will assign it to n.\n*User types 5*\nOk cool lemme assign 5 to n real quick.\n");
  
  n = 5;

  short *s = new short[n];

  double *d = new double[n];

  print("I have dynamically allocated an array of 5 shorts and an array of 5 doubles.\n");

  delete [] s;

  delete [] d;

  print("I have released both arrays.\n");

  return 0;

}
