#include <iostream>
using namespace std;

class lowEffort{
    double aNum;
    char dummy;
public:
    lowEffort(double n) {aNum = n; dummy = 'e';}
    double getNum(){return aNum;}
    double operatorDivide(double n){ return aNum / n;}
};

//Testing 1 and 2
double operatorDivide(int x, lowEffort lE) {
    return lE.getNum() / x;
}

//Testing 3
double accessPrivate(lowEffort lE, int x){
    //return lE.aNum / x; gives the error "member "lowEffort::aNum" (declared at line 5) is inaccessible"
    return 0;
}

int main(){

    cout << "### TESTING PART 1 AND 2 ###\nEnter a number ";

    double input;
    cin >> input;

    lowEffort var(input);

    cout << "Dividing " << var.getNum() << " by 5 gives the result " << operatorDivide(5, var) << endl;
    cout << "Dividing, but method inside the class: " << var.operatorDivide(5) << endl;

    cout << "\n### TESTING PART 3 ###\n";

    cout << "Dividing " << var.getNum() << " by 5 gives the result " << accessPrivate(var, 5) << endl;
    cout << "Dividing, but method inside the class: " << var.operatorDivide(5) << endl;

    return 0;
}