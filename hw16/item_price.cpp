#include<iostream>
using namespace std;

int item_count;
double *item_price;

void print_items() {
    for (int i = 0; i < item_count; ++i) {
        cout << item_price[i] << ' ';
    }
    cout << endl;
}

void change_items() {
    delete [] item_price;
    item_count = 3;
    item_price = new double[item_count];
    item_price[0] = 9;
    item_price[1] = 11;
    item_price[2] = 13;
}

void double_items() {
    double *temp_price = new double[item_count];
    for(int i = 0; i < item_count; ++i) {temp_price[i] = item_price[i];}

    delete [] item_price;
    item_count *= 2;
    item_price = new double[item_count];

    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < item_count / 2; ++j){
            item_price[(i*(item_count/2) + j)] = temp_price[j];
        }
    }
    delete [] temp_price;
}

int main() {
    item_count = 2;
    item_price = new double[item_count];
    item_price[0] = 5;
    item_price[1] = 7;
    print_items();  // output: 5 7
    change_items();
    print_items();  // output: 9 11 13
    double_items();
    print_items();  // output: 9 11 13 9 11 13
    double_items();
    print_items();  // output: 9 11 13 9 11 13 9 11 13
    delete [] item_price;
}
