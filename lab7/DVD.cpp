#include "DVD.h"


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