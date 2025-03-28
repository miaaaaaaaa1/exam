#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Service {
    string name;
    double price;
};

struct Order {
    string sender;
    string receiver;
    string item;
    double cost;
    bool completed;
};

vector<Service> services;
vector<Order> orders;

void addService() {
    Service s;
    cout << "Enter service name: "; cin >> s.name;
    cout << "Enter price: "; cin >> s.price;
    services.push_back(s);
}

void addOrder() {
    Order o;
    cout << "Enter sender name: "; cin >> o.sender;
    cout << "Enter receiver name: "; cin >> o.receiver;
    cout << "Enter item description: "; cin >> o.item;
    cout << "Enter cost: "; cin >> o.cost;
    o.completed = false;
    orders.push_back(o);
}

void completeOrder() {
    string sender;
    cout << "Enter sender name to complete order: "; cin >> sender;
    for (auto& o : orders) {
        if (o.sender == sender && !o.completed) {
            o.completed = true;
            cout << "Order marked as completed.\n";
            return;
        }
    }
    cout << "Order not found!\n";
}

void saveToFile() {
    ofstream file("orders.txt");
    for (const auto& o : orders) {
        file << o.sender << " " << o.receiver << " " << o.item << " " << o.cost << " " << o.completed << endl;
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "1. Add Service\n2. Add Order\n3. Complete Order\n4. Save to File\n5. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: addService(); break;
        case 2: addOrder(); break;
        case 3: completeOrder(); break;
        case 4: saveToFile(); break;
        }
    } while (choice != 5);
}
