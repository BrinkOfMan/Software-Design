#include"../react.h"

void power_table(int index){

    char &c0 =char_at(index + 0);
    if ((c0 == 'q') | (c0 == 'Q')){
        print("Goodbye!");
        print_at(index,"");
    }

    else if (as_integer(index) > 1 && as_integer(index) < 10){
      int n = as_integer(index);
      for(int i = 1; i <= 10; i++){
          unsigned int res = 1;
        for(int j = 0; j < i; j++){
            res *= n;
        }
        // print("{n}^{i} = {res}\n",{{"n",n},{"i",i},{"res",res}});
      }
      print_at(index, "");
    }

    else{
      print("I don't understand. Enter an int 2 - 9, enter 'q' to exit");
      print_at(index, "");
    }
    
    
}

int main() {
  init();

  const int index_1 = 10;

  if (just_starting()) {
    print("What number would you like me to compute the table for?");
    print_at(index_1, "(enter 2-9 or q to exit)");
  }
  
  if(received_event()){
    power_table(index_1);
  }


  add_yaml("input.yaml", {{"index", index_1}});

  quit();
}