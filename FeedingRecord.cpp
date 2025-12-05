#include "FeedingRecord.h"

FeedingRecord::FeedingRecord() {}

FeedingRecord::FeedingRecord(Date date, string animalName, string foodName, double amount, double cost) {
    this->date = date;
    this->animalName = animalName;
    this->foodName = foodName;
    this->amount = amount;
    this->cost = cost;
}

Date FeedingRecord::getDate() const { 
    return date; 
}

string FeedingRecord::getAnimalName() const { 
    return animalName;
}
string FeedingRecord::getFoodName() const { 
    return foodName; 
}
double FeedingRecord::getAmount() const { 
    return amount; 
}
double FeedingRecord::getCost() const { 
    return cost; 
}