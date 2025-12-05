#include "Animal.h"

Animal::Animal(string name, string species, int age) {
    this->name = name;
    this->species = species;
    this->age = age;
}

Animal::~Animal() {

}

void Animal::display() const {
    cout << "Name: " << name << ", Species: " << species << ", Age: " << age;
}

string Animal::getName() const { 
    return name; 
}
string Animal::getSpecies() const { 
    return species; 
}
int Animal::getAge() const { 
    return age; 
}

void Animal::setName(string name) {
    this->name = name;
}

void Animal::setSpecies(string species) {
    this->species = species;
}

void Animal::setAge(int age) {
    this->age = age;
}