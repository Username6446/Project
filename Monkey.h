#pragma once
#include "Animal.h"

class Monkey : public Animal {
public:
    Monkey(string name, string species, int age);

    string getType() const override;
    void display() const override;
};