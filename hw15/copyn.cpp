#include <iostream>
using namespace std;

void copyn(char *&cp, const char strc[], int n){
    
    int len = 0;
    while(strc[len++] != 0) {}

    char * cp2 = new char[len];

    int i;
    for(i = 0; i < len - 1 && i < n; ++i){
        cp2[i] = strc[i];      
    }
    cp2[i] = 0;

    cp = cp2;
}

int main() {                                                                                                                        
  char *buff;                                                                                                                             
  copyn(buff, "St. Olaf", 5);                                                                                                             
  cout << buff << "\n";
  delete [] buff;                                                                                                                   
}
