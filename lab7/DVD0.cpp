/*DISCLAIMER: I started Friday's homework before the lab, so I already
  knew to define functions that would take up more than 1 line outside of the class.
  Because of this, DVD1 will look exactly the same as DVD0*/
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

// constructor
DVD::DVD(int i, const char* t, const char* dir) {
    // Assign id
    id = i;
    // Assign title
    int len = 0; while (t[len++] != 0) {}
    title = new char[len];
    for(int i = 0; i < len; ++i){title[i] = t[i];}
    // Assign director
    len = 0; while (dir[len++] != 0) {}
    director = new char[len];
    for(int i = 0; i < len; ++i) {director[i] = dir[i];}
}

// Default constructor
DVD::DVD(){
    // No id
    id = 0;
    // No title 
    title = new char[1]; title[0] = 0;
    // No director
    director = new char[1]; director[0] = 0;
}

// Copy constructor
DVD::DVD(const DVD &d){
    // Copy d's id
    id = d.id;
    // Copy d's title
    int len = 0; while (d.title[len++] != 0) {}
    title = new char[len];
    for(int i = 0; i < len; ++i){title[i] = d.title[i];}
    // Copy d's director
    len = 0; while (d.director[len++] != 0) {}
    director = new char[len];
    for(int i = 0; i < len; ++i) {director[i] = d.director[i];}
}

void DVD::setTitle(const char* t){
    delete [] title;
    int len = 0; while(t[len++] != 0) {}
    title = new char[len];
    for(int i = 0; i < len; ++i) {title[i] = t[i];}
}

void DVD::setDirector(const char* d){
    delete [] director;
    int len = 0; while(d[len++] != 0) {}
    director = new char[len];
    for(int i = 0; i < len; ++i) {director[i] = d[i];}
}

DVD& DVD::operator=(const DVD& d){
    // Copy d's id
    id = d.id;
    // Copy d's title
    delete [] title;
    int len = 0; while(d.title[len++] != 0){}
    title = new char[len];
    for(int i = 0; i < len; ++i) {title[i] = d.title[i];}
    // Copy d's director
    len = 0; while (d.director[len++] != 0) {}
    director = new char[len];
    for(int i = 0; i < len; ++i) {director[i] = d.director[i];}
    // Then return the DVD created
    return *this;
}

int main() {
    char str[] = "Gandhi";
    DVD d1(4, str, "Richard Attenborough");
    DVD d2;
    DVD d3(d1);
    
    cout << "After constructors:" << endl;
    d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
    d2.display(); cout << endl; // [0.  /]
    d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
    
    str[0] = 'X';
    
    cout << "Test for dynamically allocated copies" << endl;
    d1.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
    d2.display(); cout << endl; // [0.  /]
    d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
    
    cout << d2.getId() << endl; // 0
    cout << d1.getTitle() << endl; // Gandhi
    cout << d1.getDirector() << endl; // Richard Attenborough
    
    d1.setId(2);
    d1.setTitle("Shadowlands");
    d2.setDirector("Ingmar Bergman");
    cout << d2.getTitle();
    cout << d2.getDirector();
    
    cout << "After state changes:" << endl;
    d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
    d2.display(); cout << endl; // [0.  /Ingmar Bergman]
    d3.display(); cout << endl; // [4.  Gandhi/Richard Attenborough]
    
    d3 = d2;
    d2.setTitle("Wild Strawberries");
    
    cout << "After more state changes:" << endl;
    d1.display(); cout << endl; // [2.  Shadowlands/Richard Attenborough]
    d2.display(); cout << endl; // [0.  Wild Strawberries/Ingmar Bergman]
    d3.display(); cout << endl; // [0.  /Ingmar Bergman]
}
