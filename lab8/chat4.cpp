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
  print_at(index, time_of_day(current_time()));
  int i = 0;
  while(auth[i] != 0) {
    global_mem[index+i+9] = auth[i];
    ++i;
  }
  global_mem[index+i+9] = 0;

  i = 0;
  while(msg[i] != 0) {
    global_mem[index+i+20] = msg[i];
    ++i;   
  }
  global_mem[index+i+20] = 0;
}

// main
int main(int argc, char **argv){

  init();
  add_yaml("scrollable.yaml");

  if (just_starting()) { global_mem[10] = 0; }

  else if (received_event()){
    char *message = global_mem + get_event_index();
    
            
    if(message[0] != 0) {
      global_mem[10]++;
      write_message(100*global_mem[10], get_user_name(), message);
    }

  }

  display_messages(global_mem[10]);

  const int text_input_index = 20;
  print_at(text_input_index, "");

  add_yaml("end_input.yaml",{{"index",text_input_index}});     
  quit ();
}