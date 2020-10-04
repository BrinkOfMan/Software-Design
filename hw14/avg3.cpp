#include <iostream>
using namespace std;

int main() {
    int entries;
    int *arrp = new int[entries];
    int input;
    int runningTotal = 0;
    cin >> entries;
    for(int i = 0; i < entries; ++i){
        cin >> input;
        runningTotal += input;
        arrp[i] = input;
    }
    cout << "Average for all " << entries << " entries is: " << runningTotal / entries << endl;
}