#include "Reptile.h"

Reptile::Reptile(string name, string species, int age) : Animal(name, species, age) {
}

string Reptile::getType() const {
    return "Reptile";
}

void Reptile::display() const {
    cout << "[REPTILE] ";
    Animal::display();
    cout << endl;
}