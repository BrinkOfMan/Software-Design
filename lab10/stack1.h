#ifndef _STACK1_H_
#define _STACK1_H_
#include <iostream>
using namespace std;

class Stack{

private:
    int *stack;
    int index;
public:
    Stack();
    Stack(const Stack &s);
    ~Stack();

    void push(int x);
    void pop();
    int top() const;
    bool empty() const;
    int size() const;

    int operator[](int ind) const;
    Stack &operator=(const Stack &s);
};


#endif  // _STACK1_H_