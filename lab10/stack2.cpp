#include <iostream>
#include "stack2.h"
using namespace std;

int Stack::counter = 0;

Stack::Stack(){
    index = -1;
    stack = new int[5];
    maxSize = 5;
}

Stack::Stack(const Stack &s){
    index = s.index;
    maxSize = s.maxSize;
    stack = new int[s.size()];

    for(int i = 0; i < s.size(); ++i){
        counter++;
        stack[i] = s[i];
    }
}

Stack::~Stack(){ delete [] stack; }

void Stack::printCounter(){
    cout << counter << endl;
}

void Stack::push(int x){
    if(index == maxSize - 1)
    {
        int *temp = new int[maxSize];

        for(int i = 0; i < maxSize; ++i){
            counter++;
            temp[i] = stack[i];
        }

        delete [] stack;
        stack = new int[maxSize + 5];
         
        for(int i = 0; i < maxSize; ++i){
            counter++;
            stack[i] = temp[i];
        }

        maxSize += 5;
        index++;
        stack[index] = x;
        delete [] temp;
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
    maxSize = s.maxSize;
    stack = new int[s.size()];

    for(int i = 0; i < s.size(); ++i){
        counter++;
        stack[i] = s[i];
    }
    return *this;
}
