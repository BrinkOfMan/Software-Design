#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> v = {2, 3, 5, 7, 11};
    for (int i = 0; i < 5; ++i)
        cout << v[i] << endl;

    v[1] += 5;
    cout << v[1] << endl;

    int intarr[] = {1, 2, 3, 4, 5};
    //cout << v << endl; // error
    cout << intarr << endl; // prints a memory location

    for (int x : v) 
        cout << x << endl;

    cout << v.size() << endl;

    cout << "\npush_back\n";
    v.push_back(22);
    cout << endl << v.size() << endl;
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    cout << "\nerase\n";
    v.erase(v.begin() + 1);
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    cout << "\ninsert\n";
    v.insert(v.begin() + 2, 9);
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    cout << "\nclear\n";
    v.clear();
    cout << v.size() << endl;

    vector<int>myVector = {1,2,6,7,8};
    for(int i = 3; i < 6; ++i){
        myVector.insert(myVector.begin() + (myVector.size() / 2), i);
    }

    for (auto x : myVector) {
        cout << x <<  " ";
    }
    cout << endl;
    

    return 0;
}