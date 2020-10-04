#include "DVDArrayP.h"

// ########################################################################################
// ########################## Start of DVD's function definitions #########################
// ########################################################################################

// constructor
DVD::DVD(int i, const char* t, const char* dir) {
    // Assign id
    id = i;
    // Assign title
    int len = 0; while (t[len++] != 0) {}
    title = new char[len];
    for(int i = 0; i < len; ++i) { title[i] = t[i]; }
    // Assign director
    len = 0; while (dir[len++] != 0) {}
    director = new char[len];
    for(int i = 0; i < len; ++i) { director[i] = dir[i]; }
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
    for(int i = 0; i < len; ++i) { title[i] = d.title[i]; }
    // Copy d's director
    len = 0; while (d.director[len++] != 0) {}
    director = new char[len];
    for(int i = 0; i < len; ++i) { director[i] = d.director[i]; }
}

// Methods
void DVD::setTitle(const char* t){
    delete [] title;
    int len = 0; while(t[len++] != 0) {}
    title = new char[len];
    for(int i = 0; i < len; ++i) { title[i] = t[i];} 
}

void DVD::setDirector(const char* d){
    delete [] director;
    int len = 0; while(d[len++] != 0) {}
    director = new char[len];
    for(int i = 0; i < len; ++i) { director[i] = d[i]; }
}

// Operators
DVD &DVD::operator=(const DVD& d){
    // Copy d's id
    id = d.id;

    // Copy d's title
    delete [] title;
    int len = 0; while(d.title[len++] != 0){}
    title = new char[len];
    for(int i = 0; i < len; ++i) { title[i] = d.title[i]; }

    // Copy d's director
    len = 0; while (d.director[len++] != 0) {}
    director = new char[len];
    for(int i = 0; i < len; ++i) { director[i] = d.director[i]; }

    // Then return the DVD created
    return *this;
}
// ########################################################################################
// ################## End of DVD's definitions, beginning of DVDArrayP's ##################
// ########################################################################################

// Constructor
DVDArrayP::DVDArrayP(int sz){
    // Create a new DVD array of sz size, then assign all values to be 0 pointers
    size = sz;
    elt = new DVD*[sz];
    for(int i = 0; i < sz; ++i) { elt[i] = 0; }
}

// Default constructor
DVDArrayP::DVDArrayP(){
    // Use DEFAULT_SIZE to do the above function's task
    size = DEFAULT_SIZE;
    elt = new DVD*[size];
    for(int i = 0; i < size; ++i) { elt[i] = 0; }
}

// Copy constructor
DVDArrayP::DVDArrayP(const DVDArrayP &arr){
    size = arr.size;
    elt = new DVD*[size];
    for(int i = 0; i < size; ++i) { 
        if(arr.elt[i] == 0){ elt[i] = 0; }
        else{ elt[i] = new DVD(*(arr.elt[i])); }
    }
}

// Methods
void DVDArrayP::display(){
    for(int i = 0; i < size; ++i){
        if (elt[i]){
            cout << i << ":\t"; elt[i] -> display();
        }
    }
}

// Operators
DVDArrayP &DVDArrayP::operator=(const DVDArrayP& arr){
    // Copy reference DVDarray's size and release current DVDarray's memory
    size = arr.size;
    for(int i = 0; i < size; ++i){
        if(elt[i] != 0){ delete elt[i]; }
    }
    delete [] elt;

    // Copy reference DVDarray's values into current array
    elt = new DVD*[size];
    for(int i = 0; i < size; ++i) { 
        if(arr.elt[i] == 0){ elt[i] = 0; }
        else{ elt[i] = new DVD(*(arr.elt[i])); }
    }

    // Then return the DVDArrayP created
    return *this;
}

DVD &DVDArrayP::operator[](int i){
    
    if (i >= 0 && i < size) {
        
        if (elt[i] != 0){
            return *elt[i];
        }
        else{
            elt[i] = new DVD;
            return *elt[i];
        }
        
    }
    else if (i < 0){
        cerr << "Index out of range, returning 0th element.\n";
        if (elt[0] != 0){
            return *elt[0];
        }
        else{
            elt[0] = new DVD;
            return *elt[0];
        }
    }
    else{
        cerr << "Index out of range, returning final element.\n";
        if (elt[size - 1] != 0){
            return *elt[size - 1];
        }
        else{
            elt[size - 1] = new DVD;
            return *elt[size - 1];
        }
    }
}

