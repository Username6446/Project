#pragma once
#include "Animal.h"

class Reptile : public Animal {
public:
    Reptile(string name, string species, int age);

    string getType() const override;
    void display() const override;
};