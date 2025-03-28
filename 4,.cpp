#include <iostream>
#include <map>
using namespace std;

struct Ingredient {
    string name;
    double quantity;
};

struct Drink {
    string name;
    double price;
    map<string, double> ingredients;
};

map<string, Ingredient> stock = {
    {"Water", {"Water", 1000}},
    {"Coffee", {"Coffee", 500}},
    {"Tea", {"Tea", 500}},
    {"Sugar", {"Sugar", 300}},
    {"Milk", {"Milk", 400}}
};

map<string, Drink> menu = {
    {"Espresso", {"Espresso", 30, {{"Water", 50}, {"Coffee", 20}}}},
    {"Tea", {"Tea", 20, {{"Water", 200}, {"Tea", 10}}}},
    {"Cappuccino", {"Cappuccino", 40, {{"Water", 50}, {"Coffee", 20}, {"Milk", 50}}}}
};

double totalCash = 0;

void adminMenu() {
    int choice;
    do {
        cout << "\nAdmin Menu:\n1. Refill Ingredients\n2. View Stock\n3. Change Prices\n4. Collect Cash\n5. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) {
            string item;
            double amount;
            cout << "Enter ingredient: "; cin >> item;
            cout << "Enter amount to add: "; cin >> amount;
            stock[item].quantity += amount;
        }
        else if (choice == 2) {
            for (auto& i : stock) {
                cout << i.first << ": " << i.second.quantity << "g/ml available\n";
            }
        }
        else if (choice == 3) {
            string drink;
            double newPrice;
            cout << "Enter drink name: "; cin >> drink;
            cout << "Enter new price: "; cin >> newPrice;
            menu[drink].price = newPrice;
        }
        else if (choice == 4) {
            cout << "Collected cash: " << totalCash << "\n";
            totalCash = 0;
        }
    } while (choice != 5);
}

void userMenu() {
    int choice;
    do {
        cout << "\nUser Menu:\n1. Order Drink\n2. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) {
            string drink;
            cout << "Enter drink name: "; cin >> drink;
            if (menu.find(drink) != menu.end()) {
                Drink d = menu[drink];
                bool available = true;
                for (auto& i : d.ingredients) {
                    if (stock[i.first].quantity < i.second) {
                        available = false;
                        break;
                    }
                }
                if (available) {
                    for (auto& i : d.ingredients) {
                        stock[i.first].quantity -= i.second;
                    }
                    totalCash += d.price;
                    cout << "Enjoy your " << drink << "!\n";
                }
                else {
                    cout << "Not enough ingredients!\n";
                }
            }
            else {
                cout << "Drink not available!\n";
            }
        }
    } while (choice != 2);
}

int main() {
    int role;
    cout << "Select Mode: 1. Admin  2. User\nChoice: ";
    cin >> role;
    if (role == 1) adminMenu();
    else userMenu();
}
