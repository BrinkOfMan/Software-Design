#include "../react.h"

/*
Tim Roback couldn't think of any serious suggestions to change the program,
but did think of a joke change where I draw a picture for each result, scan it and send it to the computer,
then have it display alongside the prompt.

I'm not going to do that
*/

const int res_ind = 10;
const int prmpt_ind = 160;
const int c1_ind = 310;
const int c2_ind = 360;

void pressed_button(int id){
    if(id == 0){
        add_yaml("C10.yaml");
        print_at(res_ind, "Wow. Look at Old Main. It sure looks old and holds the title of former main area for students to learn.");
        print_at(prmpt_ind, "Do you want to look at the Steensland library?");
        print_at(c1_ind, "Yes");
        print_at(c2_ind, "Yes but let's break in and actually see the interior");
    }
    else if(id == 1){
        add_yaml("C11.yaml");
        print_at(res_ind, "This is Buntrock Commons. Dean Buntrock's family paid $26 million to have this place named Buntrock Commons.");
        print_at(prmpt_ind, "Want to go inside and order something from the cage?");
        print_at(c1_ind, "No thanks");
        print_at(c2_ind, "Yes I would like some food");
    }
    else if(id == 2){
        add_yaml("Cend.yaml");
        print_at(res_ind, "This certainly is a library that is no longer a library as it has been under rennovation since before I came here.");
        print_at(prmpt_ind, "Do you want to start the tour over again?");
        print_at(c1_ind, "Yes");
        print_at(c2_ind, "Yes but I might change what I said before");
    }
    else if(id == 3){
        add_yaml("Cend.yaml");
        print_at(res_ind, "The police are here.");
        print_at(prmpt_ind, "Oh no");
        print_at(c1_ind, "Run away until you can start a new tour");
        print_at(c2_ind, "Pretend you are a tour guide and give the police a tour");
    }
    else if(id == 4){
        add_yaml("Cend.yaml");
        print_at(res_ind, "Well, I was going to go regardless of whether you wanted to.");
        print_at(prmpt_ind, "After I'm done in there, want to start the tour over?");
        print_at(c1_ind, "Sure");
        print_at(c2_ind, "I have no coice but to restart");
    }
    else if(id == 5){
        add_yaml("Cend.yaml");
        print_at(res_ind, "Good, because I was going to go regardless of whether you wanted to.");
        print_at(prmpt_ind, "That was some delicious food. I forgot where we were, so let's start over.");
        print_at(c1_ind, "You've literally only showed me Buntrock Commons");
        print_at(c2_ind, "That's fine, I guess");
    }
    else if(id == 6){
        add_yaml("home.yaml");
        print_at(res_ind, "Hello. I will be your tour Guide for St. Olaf College today.");
        print_at(prmpt_ind, "We could start by looking at Old Main, or by looking at Buntrock Commons. Which would you like to see?");
        print_at(c1_ind, "Old Main");
        print_at(c2_ind, "Buntrock Commons");
    }

}

int main(){
    init();

    if(just_starting()){
        add_yaml("home.yaml");
        print_at(res_ind, "Hello. I will be your tour Guide for St. Olaf College today.");
        print_at(prmpt_ind, "We could start by looking at Old Main, or by looking at Buntrock Commons. Which would you like to see?");
        print_at(c1_ind, "Old Main");
        print_at(c2_ind, "Buntrock Commons");
    }
    
    else if(received_event()){
        for(char i = 0; i < 7; ++i){
            if(event_id_is("b",i)) {
                pressed_button(i);
            }
        }
    }

    quit();
}