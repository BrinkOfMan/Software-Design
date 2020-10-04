#ifndef _Event_H_
#define _Event_H_
#include <iostream>
#include "Date.h"
using namespace std;

class Event{
protected:
    char *title;
    short priority;
    Date startDay;
    int startTime;
    int endTime;
    Date reminderDay;
    int reminderTime;
    char *description;
public:
    // Constructors
    Event();

    // Destructor
    ~Event() {delete [] title; delete [] description;}

    // Get functions
    char *&getTitle(){return title;}
    char *&getDescription(){return description;}
    short getPriority(){return priority;}
    int getStartTime(){return startTime;}
    int getEndTime(){return endTime;}
    int getReminderTime(){return reminderTime;}

    // Set functions
    void setPriority(short val){priority = val;}
    void setStartTime(short time){startTime = time;}
    void setEndEtime(short time){endTime = time;}
    void setReminderTime(short time){reminderTime = time;}
    void setStartDay(short m, short d, short y) {startDay.setAll(m,d,y);}
    void setReminderDay(short m, short d, short y) {reminderDay.setAll(m,d,y);}

    // Set functions (definitions only)
    void setTitle(const char *str);
    void setDescription(const char *str);

    // Other functions
    
};

class ClassWork:public Event{
protected:
    bool exam;
    char *className;
    Date due;
    Date startWorking;
    int timeSpend;
public:
    // Constructors
    ClassWork();

    // Destructor
    ~ClassWork(){delete [] className;}

    // Get functions
    bool getExam() {return exam;}
    char *&getClass() {return className;}
    int getTimeSpend() {return timeSpend;}

    // Set functions
    void setExam(bool e){exam = e;}
    void setTimeSpend(int time){timeSpend = time;}
    void setDue(short m, short d, short y){due.setAll(m,d,y);}
    void setStartWorking(short m, short d, short y){startWorking.setAll(m,d,y);}

    // Set functions (definitions only)
    void setClassName(const char *str);

    // Other functions
    void printDue(){cout << due.getMonth() << "/" << due.getDay() << "/20" << due.getYear() << endl;}


};


#endif  // _Event_H_