#pragma once
#include <string>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
    string time;
};

class FeedingRecord {
private:
    Date date; 
    string animalName;
    string foodName;
    double amount;
    double cost;

public:
    FeedingRecord();
    FeedingRecord(Date date, string animalName, string foodName, double amount, double cost);

    Date getDate() const;
    string getAnimalName() const;
    string getFoodName() const;
    double getAmount() const;
    double getCost() const;
};