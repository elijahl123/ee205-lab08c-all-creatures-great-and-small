//
// Created by Elijah Lopez on 3/8/22.
//

#include <iostream>
#include "animal.hpp"
#include "config.hpp"

using namespace std;

const string Animal::kingdom = "Animalia";

Animal::Animal(const string &species) {
    if (!validSpecies(species)) {
        return;
    }
    Animal::species = species;
    Animal::gender = UNKNOWN_GENDER;
}

Animal::Animal(const string &species, const enum Gender gender) {
    if (!validSpecies(species)) {
        return;
    }
    Animal::species = species;
    Animal::gender = gender;
}

Animal::Animal(const string &species, const enum Gender gender, const float weight) {
    if (!validSpecies(species)) {
        return;
    }
    if (!validWeight(weight)) {
        return;
    }
    Animal::species = species;
    Animal::gender = gender;
    Animal::weight = weight;
}

Animal::Animal(const string &species, const float weight) {
    if (!validSpecies(species)) {
        return;
    }
    if (!validWeight(weight)) {
        return;
    }
    Animal::species = species;
    Animal::gender = UNKNOWN_GENDER;
    Animal::weight = weight;
    isValid();
}

const string &Animal::getKingdom() {
    return kingdom;
}

const string &Animal::getSpecies() const {
    return species;
}

Gender Animal::getGender() const {
    return gender;
}

void Animal::setGender(const enum Gender newGender) {
    if (Animal::getGender() != UNKNOWN_GENDER) {
        cout << PROGRAM_NAME << ": previous gender must be UNKNOWN_GENDER" << endl;
    } else {
        Animal::gender = newGender;
    }
}

float Animal::getWeight() const {
    return weight;
}

void Animal::setWeight(const float newWeight) {
    if (newWeight <= 0) {
        cout << PROGRAM_NAME << ": weight must be greater than 0" << endl;
    } else {
        Animal::weight = newWeight;
    }
}

void Animal::printInfo() const {
    if (!isValid()) {
        return;
    }
    cout << "Animal Fields" << endl;
    cout << "    Kingdom = [" << getKingdom() << "]" << endl;
    cout << "    Species = [" << getSpecies() << "]" << endl;
    cout << "    Weight  = [" << getWeight()  << "]" << endl;
    cout << "    Gender  = [" << getGender()  << "]" << endl;
}

bool Animal::isValid() const {
    if (!validKingdom(getKingdom())) {
        return false;
    } else if (!validSpecies(getSpecies())) {
        return false;
    } else if (!validWeight(getWeight())) {
        return false;
    }
    return true;
}

bool Animal::validKingdom(const string& newKingdom) {
    if (newKingdom != "Animalia") {
        cout << PROGRAM_NAME << ": kingdom must be \'Animalia\'" << endl;
        return false;
    }
    return true;
}

bool Animal::validSpecies(const string& newSpecies) {
    if (newSpecies.empty()) {
        cout << PROGRAM_NAME << ": species name must not be empty" << endl;
        return false;
    }
    return true;
}

bool Animal::validWeight(const float newWeight) {
    if (newWeight <= 0) {
        cout << PROGRAM_NAME << ": weight must be greater than 0" << endl;
        return false;
    }
    return true;
}

