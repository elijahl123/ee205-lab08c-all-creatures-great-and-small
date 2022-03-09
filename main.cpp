#include <iostream>
#include <cassert>
#include "animal.hpp"

int main() {
    Animal myFirstAnimal = Animal("Felis catus");
    myFirstAnimal.setGender(MALE);
    myFirstAnimal.setWeight(19);
    myFirstAnimal.printInfo();

#ifndef NDEBUG
    cout << "Beginning Testing" << endl;
    assert(Animal::validSpecies("") == false);
    assert(Animal::validKingdom("Not Animalia") == false);
    assert(Animal::validKingdom("Animalia") == true);
    assert(Animal::validWeight(0.0) == false);
    Animal testAnimal = Animal("Felis catus");
    testAnimal.setGender(MALE);
    testAnimal.setGender(FEMALE); // should fail
    testAnimal.setWeight(10);
    testAnimal.setWeight(0); // should fail
    testAnimal.printInfo();
    cout << "Ending Testing" << endl;
#endif

    return 0;
}
