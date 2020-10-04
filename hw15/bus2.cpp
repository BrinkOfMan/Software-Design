#include <iostream>
using namespace std;

struct Business{
    long int number;
    char name[50];
    char location[50];
    float rating;

    void information(){
        cout << name << " can be reached at " << number << endl;
        cout << name << " is located in " << location << endl;
        cout << name << " has a rating of " << rating << endl;
    }
};

int main(){
    
    cout << endl;

    Business PlantFood{5558675309L,"Plant Food", "Minneapolis, Minnesota", 8.0};
    PlantFood.information();
    
    cout << endl;

    Business LawnBros{5555552966L,"The lawn brothers", "Rochester, Minnesota", 8.7};
    LawnBros.information();

    cout << endl;
    
    return 0;
}