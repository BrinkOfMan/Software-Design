#include <iostream>
#include <typeinfo>
using namespace std;

int main(){
    int z = 3;
    auto w = z;
    cout << w << endl;
    cout << typeid(z).name() << endl;

    auto text = "Okay, I wonder what this does\n";
    cout << "Here is my text test: " << text;
    cout << typeid(text).name() << endl;
    //text + 5; Statement has no effect

    auto &w2 = z;
    w2 = 5;
    cout << w2 << endl << z << endl;

    return 0;
}