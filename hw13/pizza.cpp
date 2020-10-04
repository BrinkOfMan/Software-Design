#include"../react.h"

struct Town {
    double total_pizza;
    int num_inhabitants;
    int num_students;
    double per_capita() {
        return total_pizza/num_inhabitants;
    }
    double pizza_for_students() {
        return per_capita() * num_students;
    }
    void eat_more(){
        total_pizza *= 1.10;
    }
    void show_change(){
        print("students likely ate {result} pizzas based on total per-capita consumption.\n",{{"result",pizza_for_students()}});
        total_pizza -= pizza_for_students();
        print("The number of pizza for students after removing their initial take from the total is: {res}\n",{{"res",pizza_for_students()}});
    }
};


int main(){

    Town northfield {500000.1, 20007, 6000};
    Town faribault {400000, 23750, 2000};

    print("The per-capita consumption of pizza for Northfield and Faribault is respectively {n} and {f}\n",{{"n",northfield.per_capita()},{"f",faribault.per_capita()}});

    print("Students in Northfield and Faribault respectively ate {n} and {f} pizzas.\n",{{"n",northfield.pizza_for_students()},{"f",faribault.pizza_for_students()}});

    print("\nIncreasing the amount of pizza consumed by 10% for both cities!\n\n");

    northfield.eat_more();
    faribault.eat_more();

    print("The new per-capita consumption of pizza for Northfield and Faribault is respectively {n} and {f}\n",{{"n",northfield.per_capita()},{"f",faribault.per_capita()}});

    print("Students in Northfield and Faribault respectively ate {n} and {f} pizzas.\n\n",{{"n",northfield.pizza_for_students()},{"f",faribault.pizza_for_students()}});

    print("Northfield ");
    northfield.show_change();
    print("\nFaribault ");
    faribault.show_change();

    return 0;
}