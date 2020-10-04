#include <iostream>
using namespace std;

class Point {
    float x, y, z;

public:
    Point(float a, float b, float c): x(a), y(b), z(c) {}
    void display() const { cout << x << ' ' << y << ' ' << z << '\n'; }

    // in the Point class definition:
    float &operator[] (int index) {
        if (0 == index) return x;
        else if (1 == index) return y;
        else if (2 == index) return z;
        cerr << "Error, bad index." << endl;
        return x;
  }

};


int main(){

    Point p(1, 2, 3);
    cout << "p's x, y, and z coordinates using display():\n";
    p.display();   // outputs 1 2 3

    cout << "p's x, y, and z coordinates with brackets, and changing their values:\n";
    cout << (p[0] = 3)  << " " << (p[1] = 2) << " " << (p[2] = 1) << endl;

}