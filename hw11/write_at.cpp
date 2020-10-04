#include "../react.h"

void write_at(char *c, int index, char *c2){
  
  for(int i = 0; i <= length_of(c2); i++){
    c[i+index] = c2[i];
  }
  //having i <= length_of(c2) will make it so a null byte is added at the end
  //as length_of only counts characters up to a null byte
}

int main(){

  char a[] = "hello";
  char b[] = "bye";  
  write_at(a, 1, b); 

  
  char y[100] = "greetings";
  write_at(y, 3, b);
  

  return 0;

}
