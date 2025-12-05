#pragma once
#include <string>
using namespace std;

class Food {
private:
    string name;
    double price;

public:
    Food();
    Food(string n, double p);

    string getName() const;
    double getPrice() const;
};