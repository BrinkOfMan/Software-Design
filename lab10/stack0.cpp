#include <iostream>
#include "stack0.h"
using namespace std;


Stack::Stack(){
    index = -1;
}

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

int Stack::top(){
    if(index != -1){ return stack[index]; }
    else{
        cerr << "Stack is empty, returning 0.\n";
        return 0;
    }    
}

bool Stack::empty(){
    if (index == -1){ return true; }
    else{ return false; }
}

int Stack::size(){ return index + 1; }
