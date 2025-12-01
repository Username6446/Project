#include "Animal.h"

Animal::Animal(string type, string name, size_t age, double weight)
	:type{type}, name{name}, age{age}, weight{weight}
{
}

Animal::~Animal()
{
}
