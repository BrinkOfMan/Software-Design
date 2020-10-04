#include"../react.h"

const int counter_index = 59;
const int text_index = 10;

void handle_buttons(int button, int t){
    print("Button {num} was pressed.", {{"num", button}});
    print_at(text_index, "A button has been pressed {val} times.", {{"val", t}});
}


int main() {

    init();
    
    int &counter = int_at(counter_index);

    if (just_starting()) {
        counter = 0;
        unsigned char &start_text = uchar_at(10);
        start_text = 0;
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
    add_yaml("one_text.yaml", {{"index_1", text_index}});

    quit();
}
