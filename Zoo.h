#pragma once
#include <vector>
#include <string>
#include "Animal.h"
#include "Food.h"
#include "Monkey.h"
#include "FeedingRecord.h"

using namespace std;

class Zoo {
private:
    vector<Animal*> animals;
    vector<Food> pantry;
    vector<FeedingRecord> log;

    const string FILE_ANIMALS = "animals.txt";
    const string FILE_FOOD = "food.txt";
    const string FILE_LOG = "log.txt";

public:
    Zoo();
    ~Zoo();

    void Run();

    void addAnimal();
    void listAnimals() const;
    void editAnimal();

    void addFood();
    void listFood() const;

    void feedAnimal();
    void viewLog() const;

    void saveAll();
    void loadAll();
};