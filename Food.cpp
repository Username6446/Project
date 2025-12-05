#include "Food.h"

Food::Food() 
    :Food("NoName", 0.0)
{}

Food::Food(string n, double p) {
    name = n;
    price = p;
}

string Food::getName() const {
    return name;
}

double Food::getPrice() const {
    return price;
}