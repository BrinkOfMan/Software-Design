#include"../react.h"

int main() {
  int aardvark = 4;
  float bonobo = 5;

  print("aarvark is {a} and bonobo is {b}\n",
          {{"a", aardvark}, {"b", bonobo}});
}
