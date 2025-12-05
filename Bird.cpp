#include "Bird.h"

Bird::Bird(string name, string species, int age) : Animal(name, species, age) 
{}

string Bird::getType() const {
    return "Bird";
}

void Bird::display() const {
    cout << "[BIRD] ";
    Animal::display();
    cout << endl;
}