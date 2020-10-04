#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream f("in.txt");

    f << "14 44" << endl;
    f.close();

    ifstream read("in.txt");

    int i, j;
    read >> i >> j;
    read.close();

    cout << "i is " << i << " and j is " << j << endl;
}