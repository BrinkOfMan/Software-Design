#include <iostream>
using namespace std;

class IntArray{
protected:
    static int DEFAULT_SIZE;
    int *elt;
    int size;
public:
    // Constructors and destructor
    IntArray();
    IntArray(int sz);
    IntArray(const IntArray &array);
    ~IntArray() {delete [] elt;}

    // Methods
    IntArray &operator= (const IntArray &array);
    int &operator[](int i);
    int getSize() {return size;}
    void display();
    
};

int IntArray::DEFAULT_SIZE = 1;

// Default constructor
IntArray::IntArray(){
    size = DEFAULT_SIZE;
    elt = new int[size];
    for(int i = 0; i < size; ++i) {elt[i] = 0;}
}

// Constructor
IntArray::IntArray(int sz){
    size = sz;
    elt = new int[size];
    for(int i = 0; i < size; ++i) {elt[i] = 0;}
}

// Copy constructor
IntArray::IntArray(const IntArray &array){
    size = array.size;
    elt = new int[size];
    for(int i = 0; i < size; ++i) {elt[i] = array.elt[i];}
}

// Assignment operator
IntArray &IntArray::operator=(const IntArray &array){
    delete [] elt;
    size = array.size;
    elt = new int[size];
    for(int i = 0; i < size; ++i) {elt[i] = array.elt[i];}
    return *this;
}

// [] operator
int &IntArray::operator[](int i){
    if (i >= 0 && i < size) {return elt[i];}
    else if (i < 0){
        cerr << "Index out of range, returning 0th element.\n";
        return elt[0];
    }
    else{
        cerr << "Index out of range, returning final element.\n";
        return elt[size-1];
    }
}

// Diplay
void IntArray::display(){
    for(int i = 0; i < size; ++i){
        cout << i << ":" << "\t" << elt[i] <<endl;
    }
    cout << endl;
}

int main()
{
  IntArray arr1, arr2(3);
  cout << "arr1 has size " << arr1.getSize() << endl;
  arr2.display(); cout << endl;
 
  arr2[1] = 24;
  cout << "arr2\n";
  arr2.display(); cout << endl;
  arr2[389]; // should display an error, but not crash
 
  IntArray arr3(arr2);
  cout << "arr3\n";
  arr3.display();
  arr1 = arr3;
  cout << "a copied arr1 from arr3\n";
  arr1.display();
  arr2[2] = 63;
  (arr1 = arr2)[0] = -99;
  cout << "a copied arr1 from arr2, with the 0th element being set to -99\n";
  arr1.display();
}
