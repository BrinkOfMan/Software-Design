#include"../react.h"

struct Town {
    double total_pizza;
    int num_inhabitants;
    int num_students;
};

struct Machinery {
    int num_blinking_lights;
    double price;
    void increase_price_by(double extra) {
        price += extra;
    }
    double price_per_person(Town t) {
        return price/t.num_inhabitants;
    }
    void copy_price_from(Machinery m) {
        price = m.price;
    }
    void copy_price_to(Machinery &m) {
        m.price = price;
    }

};


int main(){

    Machinery GNE472 { 1024, 555444.33 };
    Town northfield {500000.1, 20007, 6000};
    Town faribault {400000, 23750, 2000};

    print("\nPrice before: {r}\n",{{"r",GNE472.price}});

    GNE472.increase_price_by(100000);

    print("\nPrice after: {r}\n\n",{{"r",GNE472.price}});

    print_double( GNE472.price_per_person(northfield) );
    print("\n");

    print_double( GNE472.price_per_person(faribault) );
    print("\n");

    Machinery GNG475 { 512, 111222.33 };
    GNG475.copy_price_from(GNE472);

    print("Copying price from GNE472 to GNG475: ");
    print_double(GNG475.price);
    print("\n");

    Machinery ABC123 { 2048, 867530.9 };
    ABC123.copy_price_to(GNG475);
    print("Copied price to GNG475 from ABC123: ");
    print_double(GNG475.price);
    print("\n");



    return 0;
}