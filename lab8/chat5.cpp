#include "../react.h"
#include <iostream>
#include <fstream>
using namespace std;


void display_messages(int num_messages){ 
  for(int index = 1; index <= num_messages; ++index){
    add_yaml("bubble.yaml",{{"time_index",index*100},{"author_index",index*100+9},{"msg_index",index*100+20},{"indent",50}});
  }
}

void write_message(int index, const char *auth, const char *msg){
  print_at(index, true, time_of_day(current_time()));
  print_at(index+9, true, auth);
  print_at(index+20, true, msg);
}

// main
int main(int argc, char **argv){

  init();
  get_shared_data();
  add_yaml("scrollable.yaml");

  if (just_starting()) { global_shared_mem[10] = 0; }

  else if (received_event()){
    char *message = global_shared_mem + get_event_index();
    
            
    if(message[0] != 0) {
      global_shared_mem[10]++;
      write_message(100*global_shared_mem[10], get_user_name(), message);
    }
    for(int i = 0; i < 10000; ++i) { global_mem[i] = global_shared_mem[i];}
  }

  display_messages(global_mem[10]);

  const int text_input_index = 20;
  print_at(text_input_index, true, "");

  add_yaml("end_input.yaml",{{"index",text_input_index}});     
  quit ();
}