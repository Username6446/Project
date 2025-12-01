#pragma once
#include <iostream>
#include <vector>
#include "Animal.h"
#include "Food.h"
#include "FeedingRecord.h"
using namespace std;

class Zoo
{
private:
	vector<Animal*> animals;
	vector<Food> pantry;
	vector<FeedingRecord> log;
};

