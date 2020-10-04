#include"../react.h"

int main(){
    init();

    if(just_starting()){
        add_yaml("home.yaml");
    }

    if (received_event()) {
        if(event_id_is("B0")){
            add_yaml("home.yaml");
        }
        else if(event_id_is("B1")){
            add_yaml("screen1.yaml");
        }
        else{
            add_yaml("home.yaml");
        }
        
    }

    quit();
}