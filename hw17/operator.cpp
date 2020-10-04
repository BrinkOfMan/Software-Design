#include <iostream>
using namespace std;

class lowEffort{
    double aNum;
    char dummy;
public:
    lowEffort(double n) {aNum = n; dummy = 'e';}
    double getNum(){return aNum;}
};

double operatorDivide(lowEffort lE, int x) {
    return lE.getNum() / x;
}

int main(){

    cout << "Enter a number ";

    double input;
    cin >> input;

    lowEffort var(input);

    cout << "Dividing " << var.getNum() << " by 5 gives the result " << operatorDivide(var, 5) << endl;

    return 0;
}
