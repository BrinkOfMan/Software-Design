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

    cout << "Showing just base:";
    base.showNums();

    cout << "\nShowing just derived:\n";
    derived.showNums();

    cout << "\nDerived doesn't contain non-zero values from the base class:\n";
    derived.showAll();

    cout << "\nBut both contains non-zero values from derived and base class:\n";
    both.showAll();

    cout << "\nTrying to call showAll from the base class doesn't work\n";
    cout << "base.showAll(); error: 'Class Base' has no member named 'showAll'\n";



    return 0;
}