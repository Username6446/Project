#pragma once
#include "Animal.h"
class Bird : public Animal
{
private:
	bool canFly;
public:
	Bird(string type, string name, size_t age, double weight, bool canFly);
};

