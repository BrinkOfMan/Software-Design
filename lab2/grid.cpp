#include"../react.h"

const int size = 5;
const int counter_index = 59;
const int text_index = 10;
const int num_colors = 6;

void assign_color( int offset, int index, int r, int g, int b){

    unsigned char &red = uchar_at(offset+index);
    unsigned char &green = uchar_at(offset+index+1);
    unsigned char &blue = uchar_at(offset+index+2);
    red = r;
    green = g;
    blue = b;

}

void build_random_board(int offset, int gridSize, int num_colors, unsigned char a[]){
    
    for (int i = 0; i < gridSize * gridSize * 3; i+= 3){
        int randNum = random_number() * num_colors;    
        int r = a[randNum] + 30;
        int g = a[randNum] - 20;
        int b = a[randNum] + 10;
        assign_color(offset, i, r, g, b);
    }

}

void update_board(int offset, int num_moves, unsigned char a[], int button){
    int index = num_moves % (size * size) * 3;
    int r = a[button] + 30;
    int g = a[button] - 20;
    int b = a[button] + 10;
    assign_color(offset, index, r, g, b);
}

void handle_button(int button, int num_moves, int offset, int gridS, unsigned char a[]){
    
    update_board(offset, num_moves, a, button);
    if (num_moves == 0) print_at(text_index, "{val} move.", {{"val", num_moves + 1}});
    else print_at(text_index, "{val} moves.", {{"val", num_moves + 1}});
}

void make_button(int i, unsigned char color[]) {
    int red,green,blue,red1,green1,blue1;
    for(int j = 0; j < i; ++j){
        red = color[j] + 30;
        green = color[j] - 20;
        blue = color[j] + 10;
        red1 = color[j] + 60;
        green1 = color[j] - 10;
        blue1 = color[j] + 40;
        add_yaml("button.yaml", {{"id", j}, {"r", red}, {"g", green}, {"b", blue}, {"r2", red1}, {"g2", green1}, {"b2", blue1}});
    }
}



int main(){

    init();
    
    const int magnification = 30;
    const int offset = 100;


    int buttons = 6;


    unsigned char button_colors[] = {40, 70, 100, 130, 160, 190};

    int &counter = int_at(counter_index);

    if (just_starting()) {
        counter = 0;
        unsigned char &start_text = uchar_at(10);
        start_text = 0;
        build_random_board(offset, size, num_colors, button_colors);
    }
    else if (received_event()) {
        for(int j = 0; j < buttons; ++j){
            if(event_id_is("button_",j)){
                handle_button(j, counter, offset, size, button_colors);
            }
        }
        ++counter;
    }

    add_yaml("flood_fill.yaml", {{"magnification", magnification}, {"top_index", text_index}, {"total_width", size * magnification + 4}, {"total_height", size * magnification + 4}, {"grid_size", size}, {"offset", offset}});

    make_button(buttons, button_colors);

  quit();
}
