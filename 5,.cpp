#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Ingredient {
    string name;
    double price;
};

struct Pizza {
    string name;
    vector<string> ingredients;
    double price;
};

vector<Pizza> pizzaMenu;
map<string, Ingredient> ingredientStock;

void addPizza() {
    Pizza p;
    cout << "Enter pizza name: ";
    cin >> p.name;
    int count;
    cout << "Number of ingredients: ";
    cin >> count;
    double totalPrice = 0;
    for (int i = 0; i < count; i++) {
        string ing;
        cout << "Enter ingredient name: ";
        cin >> ing;
        if (ingredientStock.find(ing) != ingredientStock.end()) {
            p.ingredients.push_back(ing);
            totalPrice += ingredientStock[ing].price;
        }
        else {
            cout << "Ingredient not available.\n";
        }
    }
    p.price = totalPrice;
    pizzaMenu.push_back(p);
}

void viewPizzas() {
    for (const auto& p : pizzaMenu) {
        cout << p.name << " (" << p.price << "$): ";
        for (const auto& i : p.ingredients) cout << i << ", ";
        cout << "\n";
    }
}

void orderPizza() {
    string name;
    cout << "Enter pizza name to order: ";
    cin >> name;
    for (const auto& p : pizzaMenu) {
        if (p.name == name) {
            cout << "Total: " << p.price << "$. Payment received.\nEnjoy!\n";
            return;
        }
    }
    cout << "Pizza not found!\n";
}

int main() {
    int choice;
    do {
        cout << "1. Add Pizza\n2. View Pizzas\n3. Order Pizza\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: addPizza(); break;
        case 2: viewPizzas(); break;
        case 3: orderPizza(); break;
        }
    } while (choice != 4);
}
