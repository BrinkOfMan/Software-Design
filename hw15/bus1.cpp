#include <iostream>
using namespace std;

struct Business{
    long int number;
    char name[50];
    char location[50];
    float rating;
};

int main(){
    Business PlantFood{5558675309L,"Plant Food", "Minneapolis, Minnesota", 8.0};
    Business LawnBros{5555552966L,"The lawn brothers", "Rochester, Minnesota", 8.7};
    return 0;
}