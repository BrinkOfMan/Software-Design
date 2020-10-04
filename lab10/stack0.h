#ifndef _STACK0_H_
#define _STACK0_H_
#include <iostream>
using namespace std;

class Stack{
private:
    int stack[5];
    int index;
public:
    Stack();
    void push(int x);
    void pop();
    int top();
    bool empty();
    int size ();
};


#endif  // _STACK0_H_