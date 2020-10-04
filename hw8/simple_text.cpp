#include"../react.h"

int main() {
  init();

  double z = 8675309.55057;

  print_at(5, "Hello, world!");

  char_at(18) = 0;

  print_at(19, "Cheerio!");

  char_at(27) = 0;

  print_at(28, "The value of double z is: {num}", {{"num", z}});

  add_yaml("simple_text.yaml");



  quit();
}
