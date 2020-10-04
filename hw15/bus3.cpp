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

    void initialize(long int num, const char * nam, const char * loc, float rat){
        int i = 0;
        number = num;
        while(nam[i] != 0){
            name[i] = nam[i];
            ++i;
            if(nam[i] == 0) name[i] = 0;
        }
        i = 0;
        while(loc[i] != 0){
            location[i] = loc[i];
            ++i;
            if(loc[i] == 0) location[i] = 0;
        }
        rating = rat;
    }
};

int main(){
    
    cout << endl;

    Business PlantFood;
    PlantFood.initialize(5558675309L,"Plant Food", "Minneapolis, Minnesota", 8.0);
    PlantFood.information();
    
    cout << endl;

    Business LawnBros;
    LawnBros.initialize(5555552966L,"The lawn brothers", "Rochester, Minnesota", 8.7);
    LawnBros.information();

    cout << endl;
    
    return 0;
}