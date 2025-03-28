#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Athlete {
    string name;
    string coach;
    string country;
};

struct Event {
    string name;
};

struct Result {
    string date;
    string athlete;
    string event;
    double score;
};

vector<Athlete> athletes;
vector<Event> events;
vector<Result> results;

void addAthlete() {
    Athlete a;
    cout << "Enter athlete name: "; cin >> a.name;
    cout << "Enter coach name: "; cin >> a.coach;
    cout << "Enter country: "; cin >> a.country;
    athletes.push_back(a);
}

void addEvent() {
    Event e;
    cout << "Enter event name: "; cin >> e.name;
    events.push_back(e);
}

void addResult() {
    Result r;
    cout << "Enter date (YYYY-MM-DD): "; cin >> r.date;
    cout << "Enter athlete name: "; cin >> r.athlete;
    cout << "Enter event name: "; cin >> r.event;
    cout << "Enter score/time: "; cin >> r.score;
    results.push_back(r);
}

void saveToFile() {
    ofstream file("competition_data.txt");
    for (const auto& a : athletes) {
        file << "Athlete: " << a.name << ", " << a.coach << ", " << a.country << endl;
    }
    for (const auto& e : events) {
        file << "Event: " << e.name << endl;
    }
    for (const auto& r : results) {
        file << "Result: " << r.date << ", " << r.athlete << ", " << r.event << ", " << r.score << endl;
    }
    file.close();
}

void determineWinners(string eventName) {
    vector<Result> eventResults;
    for (const auto& r : results) {
        if (r.event == eventName) {
            eventResults.push_back(r);
        }
    }
    sort(eventResults.begin(), eventResults.end(), [](const Result& a, const Result& b) {
        return a.score < b.score;
        });
    cout << "Winner: " << eventResults.front().athlete << " with result " << eventResults.front().score << endl;
}

int main() {
    int choice;
    do {
        cout << "1. Add Athlete\n2. Add Event\n3. Add Result\n4. Save to File\n5. Determine Winner\n6. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: addAthlete(); break;
        case 2: addEvent(); break;
        case 3: addResult(); break;
        case 4: saveToFile(); break;
        case 5: {
            string eventName;
            cout << "Enter event name: "; cin >> eventName;
            determineWinners(eventName);
            break;
        }
        }
    } while (choice != 6);
}
