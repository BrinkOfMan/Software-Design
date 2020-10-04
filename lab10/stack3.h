#ifndef _STACK3_H_
#define _STACK3_H_
#include <iostream>
using namespace std;

class Stack{

private:
    int *stack;
    int maxSize;
    int index;
    static int counter;
public:
    Stack();
    Stack(const Stack &s);
    ~Stack();

    void push(int x);
    void pop();
    int top() const;
    bool empty() const;
    int size() const;
    void printCounter();

    int operator[](int ind) const;
    Stack &operator=(const Stack &s);
};

#endif  // _STACK3_H_