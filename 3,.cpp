#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Employee {
protected:
    string name, position, hireDate;
    int id, experience;
public:
    Employee(string n, string p, string h, int i, int e) : name(n), position(p), hireDate(h), id(i), experience(e) {}
    virtual double calculateSalary() = 0;
    virtual void display() {
        cout << "ID: " << id << " | Name: " << name << " | Position: " << position << " | Experience: " << experience << " years\n";
    }
    string getName() { return name; }
    string getPosition() { return position; }
    int getId() { return id; }
};

class HourlyEmployee : public Employee {
    double hourlyRate;
    int hoursWorked;
public:
    HourlyEmployee(string n, string p, string h, int i, int e, double rate, int hours) : Employee(n, p, h, i, e), hourlyRate(rate), hoursWorked(hours) {}
    double calculateSalary() override {
        return hourlyRate * hoursWorked;
    }
    void display() override {
        Employee::display();
        cout << "Hourly Rate: " << hourlyRate << " | Hours Worked: " << hoursWorked << " | Salary: " << calculateSalary() << "\n";
    }
    void setHours(int h) { hoursWorked = h; }
};

class SalariedEmployee : public Employee {
    double salary;
    int workedDays, sickDays;
public:
    SalariedEmployee(string n, string p, string h, int i, int e, double s, int wd, int sd) : Employee(n, p, h, i, e), salary(s), workedDays(wd), sickDays(sd) {}
    double calculateSalary() override {
        return salary * (workedDays / 30.0);
    }
    void display() override {
        Employee::display();
        cout << "Salary: " << salary << " | Worked Days: " << workedDays << " | Sick Days: " << sickDays << " | Final Salary: " << calculateSalary() << "\n";
    }
    void setWorkedDays(int wd) { workedDays = wd; }
};

vector<Employee*> employees;

void addEmployee() {
    string name, position, hireDate;
    int id, experience, type;
    cout << "Enter Name: "; cin >> name;
    cout << "Enter Position: "; cin >> position;
    cout << "Enter Hire Date: "; cin >> hireDate;
    cout << "Enter ID: "; cin >> id;
    cout << "Enter Experience (years): "; cin >> experience;
    cout << "Enter Type (1-Hourly, 2-Salaried): "; cin >> type;
    if (type == 1) {
        double rate;
        int hours;
        cout << "Enter Hourly Rate: "; cin >> rate;
        cout << "Enter Hours Worked: "; cin >> hours;
        employees.push_back(new HourlyEmployee(name, position, hireDate, id, experience, rate, hours));
    }
    else {
        double salary;
        int workedDays, sickDays;
        cout << "Enter Monthly Salary: "; cin >> salary;
        cout << "Enter Worked Days: "; cin >> workedDays;
        cout << "Enter Sick Days: "; cin >> sickDays;
        employees.push_back(new SalariedEmployee(name, position, hireDate, id, experience, salary, workedDays, sickDays));
    }
}

void viewEmployees() {
    sort(employees.begin(), employees.end(), [](Employee* a, Employee* b) {
        return a->getName() < b->getName();
        });
    for (auto e : employees) {
        e->display();
    }
}

int main() {
    int choice;
    do {
        cout << "1. Add Employee\n2. View Employees\n3. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: addEmployee(); break;
        case 2: viewEmployees(); break;
        }
    } while (choice != 3);
}
