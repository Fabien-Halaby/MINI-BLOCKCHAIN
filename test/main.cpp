#include "../include/Chicken.hpp"
#include "../include/Block.hpp"
#include "../include/Blockchain.hpp"
#include <iostream>

using namespace std;

int main() {
    Chicken akoho("Fana","Male",2.5,12);
    Chicken akoho1("Nasi","Female",1.5,10);
    Chicken akoho2("Fana","Male",1.75,13);
    Chicken akoho3("Mi","Female",1.5,10);
    Chicken akoho4("Fana","Male",1.5,15);

    Block a({akoho1,akoho2});
    Block b({akoho3,akoho4,akoho});

    Blockchain blockchain({{"genesis",a}});

    a.addChicken(Chicken("AB","Male",10.5,18));
    a.display();
    a.removeChicken(akoho1);
    a.display();

    b.display();

    a.searchChickenByName("Fanas");
    a.searchChickenByWeight(1.5);
    a.display();
    a.dropDuplicatesByName("Fana");
    a.display();

    return 0;
}