#ifndef _DVDARRAYP_H_
#define _DVDARRAYP_H_
#include <iostream>
using namespace std;

class DVD{
protected:
    int id;
    char* title;
    char* director;
public:
    // Constructors
    DVD(int i, const char* t, const char* dir);
    DVD(); 
    DVD(const DVD &d);

    // Destructor
    ~DVD() { delete [] title; delete[] director; }

    // Methods
    int getId() { return id; }
    const char* getTitle() { return title; }
    const char* getDirector() { return director; }

    void display() { cout << "[" << id << ".\t" << title << "/" << director << "]\n"; }
    void setId(int i) { id = i; }
    void setTitle(const char* t);
    void setDirector(const char* d);

    DVD &operator=(const DVD &d);
};

class DVDArrayP{
protected:
    static int DEFAULT_SIZE;
    DVD **elt;
    int size;
public:
    // Constructors
    DVDArrayP(int sz);
    DVDArrayP();
    DVDArrayP(const DVDArrayP &arr);

    // Destructor
    ~DVDArrayP() {
        for(int i = 0; i < size; ++i) { delete elt[i]; }
        delete [] elt; 
    }

    // Methods
    int getSize() { return size; }

    void display();

    // Operators
    DVDArrayP &operator=(const DVDArrayP &arr);
    DVD &operator[](int i);



};

#endif  // _DVDARRAYP_H_