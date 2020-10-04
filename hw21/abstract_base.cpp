#include <iostream>
using namespace std;

//The values in this class take up 4 bytes of memory
class Base{
protected:
    int aNum;
    float aFloat;
public:
    Base(int n, float f): aNum(n), aFloat(f) {;}
    void show(){cout << " int " << aNum << " float " << aFloat << endl;}
    virtual void virtualCout(){cout << "I am a method of the Base class\n";}
    virtual void pureVirtual1() = 0;
    virtual void pureVirtual2() = 0;
};


//The values in this class take up 8 bytes of memory
class Derived : public Base{    
protected:
    double aDouble;
    long aLong;
public:
    Derived(double d, long l) : aDouble(d), aLong (l), Base(0,0){;}
    Derived(double d, long l, int i, float f) : aDouble(d), aLong (l), Base(i,f){;}
    
    void onlyDerived() {cout << "Hello, I am only a method for the derived class\n";}
    void pureVirtual1() {cout << "I am the first pure virtual function.\nI only produce a cout.\n";}
    void pureVirtual2() {
        cout << "I am changing the value for the Derived object's double variable\n";
        aDouble *= 2;
    }
    void show(){cout << "double " << aDouble << " long " << aLong;}
    void showAll(){show(); Base::show();}
    void virtualCout(){cout << "I am a method of the Derived class\n";}
};

//Will not contain a virtualCout() function
class DerivedTWO : public Base{    
protected:
    char aCharacter;
public:
    DerivedTWO(char c) : aCharacter(c), Base(0,0){;}
    DerivedTWO(char c, int i, float f) : aCharacter(c), Base(i,f){;}
    
    void onlyDerived() {cout << "Hello, I am only a method for the derived class\n";}
    void pureVirtual1() {cout << "I am the first pure virtual function.\nI only produce a cout.\n";}
    void pureVirtual2() {
        cout << "I am changing the value for the DerivedTWO object's character variable\n";
        aCharacter += 1;
    }
    void show(){cout << "char " << aCharacter;}
    void showAll(){show() ; Base::show();}
};

int main(){

    Derived derived(8, 6);
    Derived both(8, 6, 7, 5);
    DerivedTWO bothTWO('c', 7, 5);

    Base *bothPointer = &both;

    Base *bothPointerTWO = &bothTWO;

    both.showAll();
    bothTWO.showAll();

    cout << "\nUsing the first pure virtual function on both and bothTWO:\n";
    bothPointer -> pureVirtual1();
    bothPointerTWO -> pureVirtual1();

    cout << "\nUsing the second pure virtual function on both and bothTWO:\n";
    bothPointer -> pureVirtual2();
    bothPointerTWO -> pureVirtual2();

    cout << "\nShowing that it did something:\n";
    both.showAll();
    bothTWO.showAll();

    return 0;
}