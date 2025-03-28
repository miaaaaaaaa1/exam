#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Animal {
    string name;
    string diet;
};

struct Food {
    string name;
    double quantity;
};

struct FeedingLog {
    string date;
    string animal;
    string food;
    double amount;
};

vector<Animal> animals;
vector<Food> foods;
vector<FeedingLog> logs;

void addAnimal() {
    Animal a;
    cout << "Enter animal name: "; cin >> a.name;
    cout << "Enter diet: "; cin >> a.diet;
    animals.push_back(a);
}

void addFood() {
    Food f;
    cout << "Enter food name: "; cin >> f.name;
    cout << "Enter quantity: "; cin >> f.quantity;
    foods.push_back(f);
}

void addFeedingLog() {
    FeedingLog log;
    cout << "Enter date (YYYY-MM-DD): "; cin >> log.date;
    cout << "Enter animal name: "; cin >> log.animal;
    cout << "Enter food name: "; cin >> log.food;
    cout << "Enter amount: "; cin >> log.amount;
    logs.push_back(log);
}

void saveToFile() {
    ofstream file("zoo_data.txt");
    for (const auto& a : animals) {
        file << "Animal: " << a.name << ", " << a.diet << endl;
    }
    for (const auto& f : foods) {
        file << "Food: " << f.name << ", " << f.quantity << endl;
    }
    for (const auto& log : logs) {
        file << "Feeding: " << log.date << ", " << log.animal << ", " << log.food << ", " << log.amount << endl;
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "1. Add Animal\n2. Add Food\n3. Add Feeding Log\n4. Save to File\n5. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: addAnimal(); break;
        case 2: addFood(); break;
        case 3: addFeedingLog(); break;
        case 4: saveToFile(); break;
        }
    } while (choice != 5);
}
