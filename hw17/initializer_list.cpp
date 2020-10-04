#include <iostream>
using namespace std;

class Favorites{
    int number;
    char letter;
public:
    Favorites(int n, char l) { number = n; letter = l; }
    void show() {cout << "favorite number is " << number << " and their favorite letter is " << letter << endl; }
};

class Human{
    Favorites favs;
    char firstInitial;

public:
    Human(int num, char let, char init) : favs(num, let), firstInitial(init) { }
    char getInit() {return firstInitial;}
    void favorites() {favs.show();}
};

int main(){
    Human Ethan{317, 'e', 'E'};
    cout << Ethan.getInit() << "'s "; Ethan.favorites();
    return 0;
}