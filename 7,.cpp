#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Service {
public:
    string type;
    string name;
    double price;
    Service(string t, string n, double p) : type(t), name(n), price(p) {}
};

class Haircut : public Service {
public:
    Haircut(string n, double p) : Service("Haircut", n, p) {}
};

class Coloring : public Service {
public:
    Coloring(string n, double p) : Service("Coloring", n, p) {}
};

class Manicure : public Service {
public:
    string extra;
    Manicure(string n, double p, string e) : Service("Manicure", n, p), extra(e) {}
};

class CosmeticProcedure : public Service {
public:
    int duration;
    CosmeticProcedure(string n, int d, double p) : Service("Cosmetic", n, p), duration(d) {}
};

vector<Service*> services;

void addService() {
    string type, name, extra;
    double price;
    int duration;
    cout << "Enter service type (Haircut/Coloring/Manicure/Cosmetic): "; cin >> type;
    cout << "Enter name: "; cin >> name;
    cout << "Enter price: "; cin >> price;
    if (type == "Haircut") services.push_back(new Haircut(name, price));
    else if (type == "Coloring") services.push_back(new Coloring(name, price));
    else if (type == "Manicure") {
        cout << "Enter extras: "; cin >> extra;
        services.push_back(new Manicure(name, price, extra));
    }
    else if (type == "Cosmetic") {
        cout << "Enter duration (min): "; cin >> duration;
        services.push_back(new CosmeticProcedure(name, duration, price));
    }
}

void listServices() {
    sort(services.begin(), services.end(), [](Service* a, Service* b) {
        return a->type < b->type || (a->type == b->type && a->name < b->name);
        });
    for (auto s : services) {
        cout << s->type << " - " << s->name << " - $" << s->price << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "1. Add Service\n2. List Services\n3. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: addService(); break;
        case 2: listServices(); break;
        }
    } while (choice != 3);
}
