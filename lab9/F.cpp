#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(){

    map<string, int> num;
    map<string, string> dict;
    string fname = "data.txt";
    ifstream f(fname.c_str()); // c_str() converts a c++ string into a c-style string (array character))
    string t;
    while (f >> t) { // reads the first part of input (term) into t
        int n;
        f >> n; // reads the next part of input (num) into n
        string d;
        getline(f, d); // reads the rest of that line's input (definition) into d
        num[t] = n;
        dict[t] = d;
        for (auto p : num){
            cout << p.first << ' ' << p.second;
            cout << dict[p.first] << endl; 
        }
        cout << endl;
    }



    return 0;
}