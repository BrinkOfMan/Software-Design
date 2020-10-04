#include <iostream>
#include "stack1.h"
using namespace std;


Stack::Stack(){
    index = -1;
    stack = new int[5];
}

Stack::Stack(const Stack &s){
    index = s.index;
    stack = new int[s.size()];

    for(int i = 0; i < s.size(); ++i){
        stack[i] = s[i];
    }
}

Stack::~Stack(){ delete [] stack; }

void Stack::push(int x){
    if(index == 4)
    {
        cout << "Stack Overflow trying to push " << x << endl;
        return;
    }
    else
    {
        index++;
        stack[index] = x;
    }
}

void Stack::pop(){
    if (index != -1){ index--; }
    else{ cerr << "Stack Underflow trying to pop" << endl; }
}

int Stack::top() const{
    if(index != -1){ return stack[index]; }
    else{
        cerr << "Stack is empty, returning 0.\n";
        return 0;
    }    
}

bool Stack::empty() const{
    if (index == -1){ return true; }
    else{ return false; }
}

int Stack::size()const{ return index + 1; }

int Stack::operator[](int ind) const{
    
    // Check to see if anything is in the stack at all
    if(index == -1){
        cerr << "Nothing in stack, returning 0\n";
        return 0;
    }

    if(ind >= 0 && ind < size()){
        return stack[ind];
    }

    else if(ind < 0){
        cerr << "Index out of range, returning 0th element.\n";
        return stack[0];
    }

    else{
        cerr << "Index out of range, returning final element\n";
        return stack[index];
    }
}

Stack &Stack::operator=(const Stack &s){
    delete [] stack;

    index = s.index;
    stack = new int[s.size()];

    for(int i = 0; i < s.size(); ++i){
        stack[i] = s[i];
    }
    return *this;
}
