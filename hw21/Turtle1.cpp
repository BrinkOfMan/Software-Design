#include<iostream>
using namespace std;
 
class Turtle {
    bool waxed;
    char *greeting;
public:
    Turtle(short n);
    Turtle(const Turtle &t);
    ~Turtle() { delete [] greeting; }
    void turtleSpeak();
};

Turtle::Turtle(short n) {
    waxed = (n>5);
    greeting = new char[3];
    greeting[0] = 'h';  greeting[1] = 'i';
    greeting[2] = '\0';
}

Turtle::Turtle( const Turtle &t ) {
    waxed = t.waxed;
    int len;
    for(len=0; t.greeting[len] != '\0'; ++len) ;
    greeting = new char[len+1];
    for(int i=0; i<len+1; ++i) greeting[i] = t.greeting[i];
}

void Turtle::turtleSpeak(){
    cout << "\t###################\n";
    cout << "\t# The turtle says #\n";
    cout << "\t###################\n";

    cout << "\nI AM A METHOD DEFINED OUTSIDE THE CLASS\n";
    cout << "\nWATCH AS I CONSUME THIS S T R A W B E R R Y\n";
}

int main()
{
    Turtle crush(150), squirt(1);
    Turtle twin(squirt);

    twin.turtleSpeak();
}
