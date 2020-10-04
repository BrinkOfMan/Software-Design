#include <iostream>
using namespace std;
#include "Date.h"
#include "Event.h"

int main(){

    Date ** dp;
    dp = new Date *[2];
    dp[1] = new Date(11,18,19);

    cout << "Today is " << dp[1] -> getMonth() << "/" << dp[1] -> getDay() << "/20" << dp[1] -> getYear() << endl;
    
    Event meeting;
    cout << "Event title is " << meeting.getTitle() << endl;
    cout << "Description is " << meeting.getDescription() << endl;

    meeting.setTitle("Epic");
    meeting.setDescription("Walking down the fightin' side of me");
    cout << "Event title is now " << meeting.getTitle() << endl;
    cout << "Description is now " << meeting.getDescription() << endl;

    ClassWork mathHomework;
    cout << "Event title is " << mathHomework.getTitle() << endl;
    cout << "Description is " << mathHomework.getDescription() << endl;
    cout << "Is mathHomework an exam? " << mathHomework.getExam() << endl;
    mathHomework.setDue(11,20,19);
    cout << "When is mathHomework due?\n";
    mathHomework.printDue();

    return 0;
}