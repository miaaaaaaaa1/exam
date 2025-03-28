#include <iostream>
#include <map>
using namespace std;

class GasStation {
    map<string, double> fuelPrices;
    map<string, double> fuelStock;
    double cash;
public:
    GasStation() : cash(0) {
        fuelPrices["Petrol"] = 50.0;
        fuelPrices["Diesel"] = 48.0;
        fuelStock["Petrol"] = 1000;
        fuelStock["Diesel"] = 800;
    }

    void adminMode() {
        cout << "Admin Mode: \n1. Refill Fuel \n2. Change Prices \n3. View Sales\n";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            refillFuel();
            break;
        case 2:
            changePrices();
            break;
        case 3:
            viewSales();
            break;
        }
    }

    void refillFuel() {
        for (auto& item : fuelStock) {
            cout << "Refill " << item.first << " (current: " << item.second << "L): ";
            double amount;
            cin >> amount;
            item.second += amount;
        }
    }

    void changePrices() {
        for (auto& item : fuelPrices) {
            cout << "New price for " << item.first << ": ";
            cin >> item.second;
        }
    }

    void viewSales() {
        cout << "Total cash earned: " << cash << " UAH\n";
    }

    void userMode() {
        cout << "Select fuel type (Petrol/Diesel): ";
        string type;
        cin >> type;

        if (fuelPrices.find(type) == fuelPrices.end()) {
            cout << "Invalid fuel type!\n";
            return;
        }

        cout << "Enter amount in liters: ";
        double liters;
        cin >> liters;

        if (fuelStock[type] < liters) {
            cout << "Not enough fuel available!\n";
            return;
        }

        double cost = fuelPrices[type] * liters;
        cout << "Total cost: " << cost << " UAH. Proceed with payment? (yes/no): ";
        string confirm;
        cin >> confirm;

        if (confirm == "yes") {
            fuelStock[type] -= liters;
            cash += cost;
            cout << "Fuel dispensed!\n";
        }
        else {
            cout << "Transaction canceled.\n";
        }
    }
};

int main() {
    GasStation station;
    cout << "Enter mode (1 - Admin, 2 - User): ";
    int mode;
    cin >> mode;
    if (mode == 1) {
        station.adminMode();
    }
    else {
        station.userMode();
    }
}
