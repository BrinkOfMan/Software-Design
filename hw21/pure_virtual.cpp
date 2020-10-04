/*Note: I created my ownclasses to better understand the relationship between base and derived classes
I apologize if this is more difficult to read, but the classess allow for testing and verifying what 
was asked of me in the homework*/
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
    virtual void virtualCout(){cout << "I am a method of the Base class\n";}
    virtual void pureVirtual() = 0;
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
    void pureVirtual() {cout << "Wow, I have been called with a pure virtual function\n";}
    void showNums(){cout << "double " << aDouble << " long " << aLong << endl;}
    void showAll(){showNums(); Base::showNums();}
    void virtualCout(){cout << "I am a method of the Derived class\n";}
};

//Will not contain a virtualCout() function for testing
class DerivedTWO : public Base{    
protected:
    char aCharacter;
public:
    DerivedTWO(char c) : aCharacter(c), Base(0,0){;}
    DerivedTWO(char c, int i, float f) : aCharacter(c), Base(i,f){;}
    void onlyDerived() {cout << "Hello, I am only a method for the derived class\n";}
    void pureVirtual() {cout << "Wow, I have been called with a pure virtual function\n";}
    void showNums(){cout << "char " << aCharacter << endl;}
    void showAll(){showNums() ; Base::showNums();}
};

int main(){

    //Base base(7, 5); error
    Derived derived(8, 6);
    Derived both(8, 6, 7, 5);
    DerivedTWO bothTWO('c', 7, 5);

    Base *bothPointer = &both;

    Base *bothPointerTWO = &bothTWO;


    cout << "Testing virtual cout from an object that has a virtualCout method:\n";
    bothPointer -> virtualCout();

    cout << "\nNow testing virtual cout from an object that does not have a virtualCout method:\n";
    bothPointerTWO -> virtualCout();

    cout << "\nTesting a function that only exists in the derived:\n";
    cout << "bothPointer -> onlyDerived(); error: 'class Base' has no member named 'onlyDerived'\n";

    cout << "\nUsing a pure virtual function to make it work\n";
    bothPointer -> pureVirtual();

    return 0;
}