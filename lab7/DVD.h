#ifndef _DVD_H_
#define _DVD_H_
#include<iostream>
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
    ~DVD(){delete [] title; delete[] director;}

    // Methods
    int getId(){return id;}
    const char* getTitle(){return title;}
    const char* getDirector(){return director;}

    void display(){cout << "[" << id << ".\t" << title << "/" << director << "]\n";}
    void setId(int i){id = i;}
    void setTitle(const char* t);
    void setDirector(const char* d);

    DVD& operator=(const DVD &d);
};

#endif  // _DVD_H_
