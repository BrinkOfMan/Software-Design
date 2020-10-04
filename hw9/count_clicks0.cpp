#include"../react.h"

void handle_button0(){
    print("Button 0 was pressed\n");
}

void handle_button1(){
    print("Button 1 was pressed\n");
}

void handle_button2(){
    print("Button 2 was pressed\n");
}

int main() {

    init();

    if (received_event()) {
        if (event_id_is("b0")) { 
            handle_button0();
        }
        else if (event_id_is("b1")) { 
            handle_button1();
        }
        else if (event_id_is("b2")) { 
            handle_button2();
        }
    }

    for(int i = 0; i <  3; ++i){
      add_yaml("button.yaml", {{"id", i}});
    }

    quit();
}
