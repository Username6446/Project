#pragma once
#include <iostream>
using namespace std;
class Animal
{
protected:
	string name;
	size_t age;
	double weight;
	string type;

public:

	Animal(string type, string name, size_t age, double weight);
	virtual ~Animal();

	virtual void feed() const = 0;
	virtual void showInfo() const = 0;
	virtual void saveToFIle() const = 0;
	virtual void loadFromFile() = 0;
};

