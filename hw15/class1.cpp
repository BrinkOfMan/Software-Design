#include<iostream>
using namespace std;

class Person {
  int height, weight, age;
  char sex;

public:
  void init(int h, int w, int a, char s){
    height = h;
    weight = w;
    age = a;
    sex = s;
  }
  void information(){
    cout << "Person is " << height << " inches tall.\n";
    cout << "Person is " << age << " years old.\n";
  }
};

int main(){
  Person Ethan;
  Ethan.init(72, 150, 20, 'M');
  Ethan.information();

  return 0;
}
