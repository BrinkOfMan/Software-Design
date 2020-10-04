#include "../react.h"

const int res_ind = 10;

void pressed_button(int id){
    if(id == 0){
        add_yaml("C10.yaml");
        print_at(res_ind,"0");
    }
    else if(id == 1){
        add_yaml("C11.yaml");
        print_at(res_ind,"1");
    }
    else if(id == 2){
        add_yaml("Cend.yaml");
        print_at(res_ind,"2");
    }
    else if(id == 3){
        add_yaml("Cend.yaml");
        print_at(res_ind,"3");
    }
    else if(id == 4){
        add_yaml("Cend.yaml");
        print_at(res_ind,"4");
    }
    else if(id == 5){
        add_yaml("Cend.yaml");
        print_at(res_ind,"5");
    }
    else if(id == 6){
        add_yaml("home.yaml");
        print_at(res_ind,"Returned home");
    }

}

int main(){
    init();

    if(just_starting()) add_yaml("home.yaml");
    
    else if(received_event()){
        for(char i = 0; i < 7; ++i){
            if(event_id_is("b",i)) {
                pressed_button(i);
            }
        }
    }

    quit();
}