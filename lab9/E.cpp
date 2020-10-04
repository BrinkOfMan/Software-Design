#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(){

    map<string, int> price;
    map<string, int> :: iterator it;
    price["socks"] = 1000;
    price["shoes"] = 3000;
    cout << price["socks"] << endl;  
    cout << price.size() << endl;

    it = price.find("socks");
    price.erase(it);
    price.emplace("socks",1000);
    cout << price.at("socks") << endl;

    for (auto p : price)
    cout << p.first << ' ' << p.second << endl;

    if (price.find("boots") == price.end())
        cout << "not found" << endl;
    price.erase("socks");
    for (auto p : price)
        cout << p.first << ' ' << p.second << endl;
    price.clear();


    return 0;
}