#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Type a number" << endl;
    cin >> n;
    cout << "The next 10 even numbers are:" << endl;
    if(n % 2 == 0){
        for(int i = 1 ; i <= 10; ++i)
            cout << n + (i*2) << endl;
    }

    else{
        for(int i = 1 ; i <= 10; ++i)
            cout << n + (i*2) - 1 << endl;
    }
  
}