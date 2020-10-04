#include"../print.h"

void n_years_later(int yrs, int man1, int &man2) {

    man1 += yrs;
    man2 += yrs;
}

int main() {
    int manWhoDoesNotAge = 25;
    int manWhoAges = 25;
    int years = 5;
    print("In 2020, the man who does not age is "); print_int(manWhoDoesNotAge);
    print("\nIn 2020, man who ages is "); print_int(manWhoDoesNotAge);
    n_years_later(years, manWhoDoesNotAge, manWhoAges);

    print("\n"); print_int(years); print(" years pass.\n");

    print("\nThe man who does not age is still ");  print_int(manWhoDoesNotAge);
    print("\nThe man who does not age is now ");  print_int(manWhoAges);
    print("\n");

}
