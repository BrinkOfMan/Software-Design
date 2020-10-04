#include"../react.h"

int main() {
  init();
  char &state = char_at(2);
  print_at(5, "hello");
  if (just_starting()) {
    state = 'H';
  } else if (received_event()) {
    if (event_id_is("to_screen_two")) {
      state = 'T';
    } else if (event_id_is("button_1")) {
      print("ok!");
    } else if (event_id_is("to_home_screen")) {
      state = 'H';
    }
  }
  if (state == 'H') add_yaml("home.yaml");
  else add_yaml("screen1.yaml");
  quit();
}
