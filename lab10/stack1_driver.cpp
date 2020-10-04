#include "stack1.h"
#include <iostream>
using namespace std;

int main(){     
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6); // Should be an error

    cout << "Size is " << s.size() << endl;
    cout << "Top value is " << s.top() << endl;
    cout << "Is the stack empty? " << s.empty() << endl;

    s.pop(); // goodbye 5
    s.pop(); // 4
    s.pop(); // 3
    s.pop(); // 2
    s.pop(); // 1
    s.pop(); // Should be an error; no more

    cout << "Size is " << s.size() << endl;
    cout << "Top value is " << s.top() << endl;
    cout << "Is the stack empty? " << s.empty() << endl;

    // Test copy, =, and []
    for(int i = 1; i <= 5; ++i){ s.push(i); }
    cout << "What is the third element of our stack? "  << s[2] << endl;

    Stack s1 = s;
    cout << "What is the third element of our operator= stack? "  << s1[2] << endl;

    Stack s2(s1);
    cout << "What is the third element of our copied stack? "  << s1[2] << endl;

    
}