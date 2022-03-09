///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08c_all_creatures_great_and_small - EE 205 - Spr 2022
///
/// @file animal.hpp
/// @version 1.0
///
/// @author Elijah Lopez <elijahl7@hawaii.edu>
/// @date   08_Mar_2022
///////////////////////////////////////////////////////////////////////////////


#ifndef EE205_LAB08C_ALL_CREATURES_GREAT_AND_SMALL_ANIMAL_HPP
#define EE205_LAB08C_ALL_CREATURES_GREAT_AND_SMALL_ANIMAL_HPP

#include <iostream>

using namespace std;

enum Gender {
    MALE = 1,
    FEMALE,
    UNKNOWN_GENDER
};

class Animal {
protected:
    static const string kingdom;
    string species;
    enum Gender gender;
    float weight;
public:
    Animal(const string &);

    Animal(const string &, enum Gender);

    Animal(const string &, enum Gender, float weight);

    Animal(const string &, float weight);

public:
    static const string &getKingdom();

    const string &getSpecies() const;

    Gender getGender() const;

    float getWeight() const;

    void setGender(enum Gender newGender);

    void setWeight(float newWeight);

    void printInfo() const;

    bool isValid() const;

    static bool validKingdom(const string &newKingdom);

    static bool validSpecies(const string &newSpecies);

    static bool validWeight(float newWeight);
};


#endif //EE205_LAB08C_ALL_CREATURES_GREAT_AND_SMALL_ANIMAL_HPP
