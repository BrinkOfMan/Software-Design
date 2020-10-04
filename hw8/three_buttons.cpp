#include"../react.h"
  
int main() {
  init();

  if (received_event()) {
    if (event_id_is("go")) {
      print("You can go.\n");
    }
    else if (event_id_is("slow")) {
      print("Slow down.\n");
    }
    else if (event_id_is("stop")) {
      print("Time to stop.\n");
    }
  }
  add_yaml("three_buttons.yaml");

  quit();
}
