#include <iostream>
using namespace std;

short global_1 = 3, global_2 = 4;

short &get_first() { return global_1; }

short &get_one(int i){ 
    if(i == 0) {return global_1;}
    else {return global_2;}
}

void current(){ cout << "global_1 is " << global_1 << " global_2 is " << global_2 << endl;}

int main() {
    cout << "Before any changes:\n";
    current();

    cout << "\nget_first() = 5; // Should make global_1 equal to 5\n";
    get_first() = 5;
    current();

    cout << "\nget_one(0) = 10; // Should make global_1 equal to 10\n";
    get_one(0) = 10;
    current();

    cout << "\nget_one(1) = 20; // Should make global_2 equal to 20\n";
    get_one(1) = 20;
    current();
}
