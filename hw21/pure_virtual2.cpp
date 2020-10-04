//Removing the DerivedTWO class, as it's redundant for const testing
#include <iostream>
using namespace std;

//The values in this class take up 4 bytes of memory
class Base{
protected:
    int aNum;
    float aFloat;
public:
    Base(int n, float f): aNum(n), aFloat(f) {;}
    void showNums() const {cout << "\nint " << aNum << " float " << aFloat << endl;}
    
    virtual void virtualCout(){cout << "I am a method of the Base class\n";}
    virtual void pureVirtual() const = 0;
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
    void pureVirtual() const {cout << "Wow, I have been called with a pure virtual function\n";}
    void showNums() const {cout << "double " << aDouble << " long " << aLong << endl;}
    void showAll() const {showNums(); Base::showNums();}
    void virtualCout(){cout << "I am a method of the Derived class\n";}

    //New methods with returns
    double getDouble() const {return aDouble;}
    long getLong() const {return aLong;}
    
    //Testing method which won't work for const instances of the object
    void changeThings() {aDouble *= 2; aLong += 8675303;}
};


int main(){

    Derived derived(8, 6);
    const Derived constDerived(8, 6);
    

    cout << "\nCalling constDerived.getDouble():\n" << constDerived.getDouble() << endl;
    cout << "\nCalling constDerived.getLong():\n" << constDerived.getLong() << endl;
    cout << "\nCan't call the changeThings() function with constDerived as it will... change things:\n";
    cout << "constDerived.changeThings();\nerror: passing ‘const Derived’ as ‘this’ argument of ‘void Derived::changeThings()’ discards qualifiers [-fpermissive]\n";
    
    cout << "\nBut you can call changeThings() with the non-const instance of a Derived object:\n";
    derived.showNums();
    cout << "Changing things!\n";derived.changeThings();
    derived.showNums();
    
    return 0;
}