#include "Zoo.h"
#include "Bird.h"
#include "Reptile.h"
#include <iostream>
#include <fstream>

using namespace std;

Zoo::Zoo() {
    loadAll();
}

Zoo::~Zoo() {
    saveAll();
    for (auto a : animals) {
        delete a;
    }
    animals.clear();
}

void Zoo::Run() {
    int choice;
    do {
        cout << "\n=== ZOO MANAGER ===\n";
        cout << "1. Add Animal\n";
        cout << "2. List Animals\n";
        cout << "3. Edit Animal Age\n";
        cout << "4. Add Food\n";
        cout << "5. List Food\n";
        cout << "6. Feed Animal\n";
        cout << "7. View Log\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addAnimal(); break;
        case 2: listAnimals(); break;
        case 3: editAnimal(); break;
        case 4: addFood(); break;
        case 5: listFood(); break;
        case 6: feedAnimal(); break;
        case 7: viewLog(); break;
        case 0: break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}

void Zoo::addAnimal() {
    int type, age;
    string name, species;

    cout << "Type (1-Bird, 2-Reptile, 3-Monkey): ";
    cin >> type;

    cout << "Name: "; cin >> name;
    cout << "Species: "; cin >> species;
    cout << "Age: "; cin >> age;

    if (type == 1) animals.push_back(new Bird(name, species, age));
    else if (type == 2) animals.push_back(new Reptile(name, species, age));
    else if (type == 3) animals.push_back(new Monkey(name, species, age));
    else cout << "Unknown type!\n";
}

void Zoo::listAnimals() const {
    cout << "\n--- Animals ---\n";
    for (size_t i = 0; i < animals.size(); i++) {
        cout << i + 1 << ". ";
        animals[i]->display();
    }
}

void Zoo::editAnimal() {
    listAnimals();
    int idx, newAge;
    cout << "Select ID: "; cin >> idx;
    if (idx > 0 && idx <= (int)animals.size()) {
        cout << "New Age: "; cin >> newAge;
        animals[idx - 1]->setAge(newAge);
    }
}

void Zoo::addFood() {
    string name;
    double price;
    cout << "Name: "; cin >> name;
    cout << "Price: "; cin >> price;
    pantry.push_back(Food(name, price));
}

void Zoo::listFood() const {
    cout << "\n--- Pantry ---\n";
    for (size_t i = 0; i < pantry.size(); i++) {
        cout << i + 1 << ". " << pantry[i].getName() << " - " << pantry[i].getPrice() << endl;
    }
}

void Zoo::feedAnimal() {
    if (animals.empty() || pantry.empty()) {
        cout << "Error: Add animals and food first.\n";
        return;
    }

    int aIdx, fIdx;
    double amount;
    Date date;

    listAnimals();
    cout << "Select Animal ID: "; cin >> aIdx;

    listFood();
    cout << "Select Food ID: "; cin >> fIdx;

    cout << "Amount (kg): "; cin >> amount;

    cout << "Enter Day: "; cin >> date.day;
    cout << "Enter Month: "; cin >> date.month;
    cout << "Enter Year: "; cin >> date.year;
    cout << "Enter Time (HH:MM): "; cin >> date.time;

    if (aIdx > 0 && aIdx <= (int)animals.size() && fIdx > 0 && fIdx <= (int)pantry.size()) {
        Animal* a = animals[aIdx - 1];
        Food f = pantry[fIdx - 1];
        double totalCost = amount * f.getPrice();

        log.push_back(FeedingRecord(date, a->getName(), f.getName(), amount, totalCost));
        cout << "Fed successfully! Cost: " << totalCost << endl;
    }
    else {
        cout << "Invalid selection.\n";
    }
}

void Zoo::viewLog() const {
    cout << "\n--- Feeding Log ---\n";
    for (const auto& r : log) {
        Date d = r.getDate();
        cout << d.day << "." << d.month << "." << d.year << " " << d.time
            << " | " << r.getAnimalName() << " ate " << r.getAmount()
            << "kg of " << r.getFoodName() << " (Cost: " << r.getCost() << ")" << endl;
    }
}

void Zoo::saveAll() {
    ofstream f1(FILE_ANIMALS);
    f1 << animals.size() << endl;
    for (auto a : animals) {
        f1 << a->getType() << " " << a->getName() << " " << a->getSpecies() << " " << a->getAge() << endl;
    }
    f1.close();

    ofstream f2(FILE_FOOD);
    f2 << pantry.size() << endl;
    for (auto& f : pantry) {
        f2 << f.getName() << " " << f.getPrice() << endl;
    }
    f2.close();

    ofstream f3(FILE_LOG);
    if (f3.is_open()) {
        f3 << log.size() << endl;
        for (auto& r : log) {
            Date d = r.getDate();
            f3 << d.day << " " << d.month << " " << d.year << " " << d.time << " "
                << r.getAnimalName() << " " << r.getFoodName()
                << " " << r.getAmount() << " " << r.getCost() << endl;
        }
        f3.close();
    }
}

void Zoo::loadAll() {
    ifstream f1(FILE_ANIMALS);
    if (f1.is_open()) {
        int count, age;
        string type, name, species;
        f1 >> count;
        for (int i = 0; i < count; i++) {
            f1 >> type >> name >> species >> age;

            if (type == "Bird") animals.push_back(new Bird(name, species, age));
            else if (type == "Reptile") animals.push_back(new Reptile(name, species, age));
            else if (type == "Monkey") animals.push_back(new Monkey(name, species, age));
        }
        f1.close();
    }

    ifstream f2(FILE_FOOD);
    if (f2.is_open()) {
        int count;
        string name;
        double price;
        f2 >> count;
        for (int i = 0; i < count; i++) {
            f2 >> name >> price;
            pantry.push_back(Food(name, price));
        }
        f2.close();
    }

    ifstream f3(FILE_LOG);
    if (f3.is_open()) {
        int count;
        f3 >> count;

        Date d;
        string a, f;
        double am, c;

        for (int i = 0; i < count; i++) {
            f3 >> d.day >> d.month >> d.year >> d.time >> a >> f >> am >> c;
            log.push_back(FeedingRecord(d, a, f, am, c));
        }
        f3.close();
    }
}