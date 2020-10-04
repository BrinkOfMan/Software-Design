#include <iostream>
using namespace std;

int main() {
    int entries;
    int *arrp = new int[entries];
    int input;
    cin >> entries;
    for(int i = 0; i < entries; ++i){
        cin >> input;
        arrp[i] = input;
    }
}