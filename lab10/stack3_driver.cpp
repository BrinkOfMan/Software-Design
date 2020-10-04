#include "stack3.h"
#include <iostream>
using namespace std;

int main(){     
    Stack s;

    // Test increasing stack length
    for(int i = 1; i <= 100; ++i){ s.push(i);}
    cout << "Size is " << s.size() << endl;
    cout << "Top value is " << s.top() << endl << endl;
    s.printCounter();

    for(int i = 101; i <= 1000; ++i){ s.push(i);}
    cout << "Size is " << s.size() << endl;
    cout << "Top value is " << s.top() << endl << endl; 
    s.printCounter();

    for(int i = 1001; i <= 10000; ++i){ s.push(i);}
    cout << "Size is " << s.size() << endl;
    cout << "Top value is " << s.top() << endl << endl; 
    
    s.printCounter();
}