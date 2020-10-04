#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){

    string s = "hi hi";
    cout << s[1] << endl;  
    cout << "size " << s.size() << endl;

    cout << s << endl;

    s += " I am a test ";
    cout << s << endl;

    //s *= 2; // Does not double the message
    s += s; // But this does
    cout << s << endl;

    s = s + " ok";
    cout << s << endl; 
    string s2 = "ji ji";
    cout << (s < s2) << endl;

    
    return 0;
}