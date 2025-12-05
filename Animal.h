#pragma once
#include <string>
#include <iostream>
using namespace std;

class Animal {
protected:
    string name;
    string species;
    int age;

public:
    Animal(string name, string species, int age);
    virtual ~Animal();

    virtual string getType() const = 0;

    virtual void display() const;

    string getName() const;
    string getSpecies() const;
    int getAge() const;

    void setName(string name);
    void setSpecies(string species);
    void setAge(int age);
};