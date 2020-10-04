#include<iostream>
using namespace std;

class Animal {
    char *name;
    float weight;
    void init(const char *n, float w) {
        int len = 0;
        while( n[len] ) ++len;
        name = new char[len+1];
        for ( int i = 0; i < len+1; ++i )
        name[i] = n[i];
        weight = w;
  }

public:
    Animal(const char *n, float w) { init(n,w); }
    Animal(const Animal &a) { init(a.name, a.weight); }
    ~Animal() { if ( name ) delete [] name;  name = 0; }

    Animal &operator=(const Animal &a) { // Copy constructor
        init (a.name, a.weight);
        return *this;
    }

    float current() const { return weight; }
    float growFast(float s) { weight *= s; return weight; }
    virtual void message(){cout << "Hello, I am an animal.\n";}
};

class HouseCat : public Animal {
    double whisker_len;
public:
    HouseCat(double wl) : Animal("cat", 8) { whisker_len = wl; }
    HouseCat(const HouseCat &hc) : Animal(hc) { whisker_len = hc.whisker_len; }
    ~HouseCat() {}  // this is really not necessary!

    int getLen() { return whisker_len; }
    void trim() { whisker_len /= 2; }
    void message(){cout << "Hello, I am an animal. But specifically, I say \"Meow.\"\n";}
};

int main()
{
    HouseCat sox(12), waldo(18);
    cout << "Before assigning sox to waldo, waldo's whisker length is " << waldo.getLen() << " and sox's is " << sox.getLen() << endl;
    waldo = sox;

    waldo.trim();
    waldo.trim();
    waldo.trim();
    cout << "\nAfter assigning sox to waldo and trimming walso three times, waldo's whisker length is now " << waldo.getLen() << " and sox's is " << sox.getLen() << endl;  // note return type!

    Animal Giraffe("Giraffe", 370);
    Animal *GiraffePointer = &Giraffe;
    cout << "\nShowing the call to the virtual function with just an animal pointer:\n";
    GiraffePointer -> message();

    Animal *soxPointer = &sox;
    cout << "\nShowing the call to the virtual function with an animal pointer that's also a cat:\n";
    soxPointer -> message();

    return 0;
}
