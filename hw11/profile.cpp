#include "../react.h"


int main(){
    init();

    const int firstNameInd = 10;
    const int lastNameInd = 18;
    const int classYrInd = 27;
    const int countryInd = 35;
    const int countryNameInd = 50;
    const int iceCreamInd = 65;
    const int favBookInd = 105;
    const int book1Ind = 124;
    const int book2Ind = 132;
    const int book3Ind = 156;
    const int book4Ind = 165;
    const int book5Ind = 181;
    const int heightInd = 194;
    const int bornInd = 206;
    const int dateInd = 212;
    const int survivorInd = 223;
    const int survivorInd2 = 230;

    print_at(firstNameInd,"Ethan");
    print_at(lastNameInd,"Brinkman");
    print_at(classYrInd,"2021");
    print_at(countryInd, "Home Country:");
    print_at(countryNameInd,"United States ");
    print_at(iceCreamInd, "Favorite ice cream: Mint chocolate chip");
    print_at(favBookInd,"My favorite books:");
    print_at(book1Ind,"Frindle");
    print_at(book2Ind,"This Changes Everything");
    print_at(book3Ind,"I, Robot");
    print_at(book4Ind,"Y: The Last Man");
    print_at(book5Ind,"Odyssey");
    print_at(heightInd, "6 feet tall");
    print_at(bornInd, "Born:");
    print_at(dateInd,"10/29/1998");
    print_at(survivorInd,"Cancer");
    print_at(survivorInd2,"survivor");

    add_yaml("profile.yaml", {{"firstNameInd",firstNameInd},{"lastNameInd",lastNameInd},{"classYrInd",classYrInd}, {"countryInd",countryInd},{"countryNameInd",countryNameInd},{"iceCreamInd",iceCreamInd},{"favBookInd",favBookInd},{"book1Ind",book1Ind},{"book2Ind",book2Ind},{"book3Ind",book3Ind},{"book4Ind",book4Ind},{"book5Ind",book5Ind},{"heightInd",heightInd},{"bornInd",bornInd},{"dateInd",dateInd},{"survivorInd",survivorInd},{"survivorInd2",survivorInd2}});
    quit();
}