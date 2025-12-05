#include "Monkey.h"

Monkey::Monkey(string name, string species, int age) : Animal(name, species, age) {
}

string Monkey::getType() const {
    return "Monkey";
}

void Monkey::display() const {
    cout << "[MONKEY] ";
    Animal::display();
    cout << endl;
}