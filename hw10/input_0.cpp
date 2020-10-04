#include"../react.h"

void handle_input(int index){
    print_at(index, "");
}

int main() {
  init();

  const int index_1 = 10;
  if (just_starting()) {
    print_at(index_1, "Type stuff. Hit enter to reset");
  }

  if(received_event()){
      handle_input(index_1);
  }

  add_yaml("input_1.yaml", {{"index", index_1}});

  quit();
}
