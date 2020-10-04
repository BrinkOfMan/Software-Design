#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(){

    vector<string> v;
    string fname = "expenses.10000";
    ifstream f(fname.c_str()); // c_str() converts a c++ string into a c-style string (array character))
    
    string t;
    while (getline(f,t)) { // reads the first part of input (term) into t
        v.push_back(t);
    }
    cout << "This should print how many lines there are:\n";
    cout << v.size() << endl;



    return 0;
}