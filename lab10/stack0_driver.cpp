#include "stack0.h"
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
}