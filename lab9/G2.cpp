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
    while (getline(f,t)) { // reads every line into the vector
        v.push_back(t);
    }
    cout << "This should print how many lines there are:\n";
    cout << v.size() << endl;

    double totalWords = 0;
    double totalSpace = 0;
    int newLines = 0;
    for (auto x: v){ // Each line
        newLines++;
        for(auto y: x){ // Each character in that line
            if (y == ' ') {totalWords++;}
            totalSpace++;
        }  
    }

    cout << "This should print how many words this is:\n";
    cout << totalWords + newLines << endl;

    cout << "This should print how much space this takes up:\n";
    cout << totalSpace + newLines << endl;

    /* I'm not sure why, but when comparing my code without a newlines
    counter to easywordcount.com, I saw that I was 10,000 off for both characters and words.
    Not sure how to get this to work as Olaf intended, but my methods seems to work*/

    return 0;
}