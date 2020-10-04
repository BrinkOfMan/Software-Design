#include"../react.h"

void handle_buttons(int button, int t){
    print("Button {num} was pressed.\n", {{"num", button}});
    print_at(10, "A button has been pressed {val} times.\n", {{"val", counter}});
}


int main() {

    init();
    
    int &counter = int_at(111);

    if (just_starting()) {
        counter = 0;
    }
    else if (received_event()) {
        ++counter;
        for(int j = 0; j < 3; ++j){
            if(event_id_is("b",j))
                handle_buttons(j, counter);
        }
    }

    for(int i = 0; i <  3; ++i){
      add_yaml("button.yaml", {{"id", i}});
    }
    add_yaml("one_text.yaml", {{"index_1", 10}});

    quit();
}
