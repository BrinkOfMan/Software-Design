#include "Event.h"

// ############################ Event class ############################

// ################
// ##Constructors##
// ################

// Default constructor
Event::Event(){
    title = new char[6];
    title[0] = 'E'; title[1] = 'v'; title[2] = 'e'; title[3] ='n'; title[4] = 't'; title[5] = 0;
    priority = 0;
    startDay.setAll(11,18,19);
    startTime = 0;
    endTime = 60;
    reminderDay.setAll(11,18,19);
    reminderTime = 0;
    description = new char[5];
    description[0] = 'D'; description[1] = 'e'; description[2] = 's'; description[3] = 'c'; description[4] = 0;
}

// ################
// ##Set function##
// ################

void Event::setTitle(const char *str){
    delete [] title;
    short sz;
    while(str[sz++] != 0);
    title = new char[sz];
    for(int i = 0; i < sz; ++i){title[i] = str[i];}
}

void Event::setDescription(const char *str){
    delete [] description;
    short sz;
    while(str[sz++] != 0);
    description = new char[sz];
    for(int i = 0; i < sz; ++i){description[i] = str[i];}
}

// ########################## ClassWork class ##########################

// ################
// ##Constructors##
// ################

// Default constructor
ClassWork::ClassWork():Event(){
    exam = false;
    className = new char[5];
    className[0] = 'M'; className[1] = 'a'; className[2] = 't'; className[3] = 'h'; className[4] = 0;
    due.setAll(11,18,19);
    startWorking.setAll(11,18,19);
    timeSpend = 1;
}

// ################
// ##Set function##
// ################

void ClassWork::setClassName(const char *str){
    delete [] className;
    short sz;
    while(str[sz++] != 0);
    className = new char[sz];
    for(int i = 0; i < sz; ++i){className[i] = str[i];}
}