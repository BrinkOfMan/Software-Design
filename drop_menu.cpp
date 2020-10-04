#include"../react.h"

int main() {
  init();
  add_yaml("drop_menu.yaml");
  if (just_starting()) {  // initial setup
    print_at(10, "option A");
    print_at(20, "option B");
    print_at(30, "option C");
    print_at(40, "0");
    print_at(50, "hello");
  } else if (received_event()) { // check if the user picked something
    int i = get_event_item_index();
    print_at(50, "item_index {val}", {{"val", i}});
  }
  quit();
}
