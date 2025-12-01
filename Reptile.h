#pragma once
#include "Animal.h"
class Reptile : public Animal
{
	bool isVenomous;
	string scaleType;
public:
	Reptile(string type, string name, size_t age, double weight, bool isVenomous, string scaleType);
};

