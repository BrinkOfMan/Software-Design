#include <iostream>
using namespace std;

//The values in this class take up 4 bytes of memory
class Base{
protected:
    int aNum;
    float aFloat;
public:
    Base(int n, float f): aNum(n), aFloat(f) {;}
    void showNums(){cout << "\nint " << aNum << " float " << aFloat << endl;}
};


//The values in this class take up 8 bytes of memory
class Derived : public Base{    
protected:
    double aDouble;
    long aLong;
public:
    Derived(double d, long l) : aDouble(d), aLong (l), Base(0,0){;}
    Derived(double d, long l, int i, float f) : aDouble(d), aLong (l), Base(i,f){;}
    void showNums(){cout << "double " << aDouble << " long " << aLong << endl;}
    void showAll(){cout << "double " << aDouble << " long " << aLong; Base::showNums();}
};

int main(){

    Base base(7, 5);
    Derived derived(8, 6);
    Derived both(8, 6, 7, 5);

    Base *basePointer;
    basePointer = &both;
    Base &baseReference = both;

    Derived *bothPointer;
    bothPointer = &both;
    Derived &bothReference = both;

    cout << "Testing if base pointer at derived works:";
    basePointer -> showNums();

    cout << "\nTesting if base reference at derived works:";
    baseReference.showNums();

    cout << "\nCan't call the Derived methods with Base pointers or references:\n";
    cout << "basePointer -> showAll(); error: 'class Base' has no member named 'showAll'\n";
    cout << "baseReference.showAll(); error: 'class Base' has no member named 'showAll'\n";

    cout << "\nBut you can call from pointers and references to Derived:\n";
    bothPointer -> showAll();
    bothReference.showAll();

    return 0;
}