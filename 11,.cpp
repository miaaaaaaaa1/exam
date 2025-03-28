#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
};

struct Subject {
    string name;
    int lessonsPerWeek;
};

struct Grade {
    string studentName;
    string subject;
    vector<int> marks;
};

vector<Student> students;
vector<Subject> subjects;
vector<Grade> grades;

void addStudent() {
    Student s;
    cout << "Enter student name: "; cin >> s.name;
    students.push_back(s);
}

void addSubject() {
    Subject sub;
    cout << "Enter subject name: "; cin >> sub.name;
    cout << "Enter number of lessons per week: "; cin >> sub.lessonsPerWeek;
    subjects.push_back(sub);
}

void addGrade() {
    Grade g;
    int mark;
    cout << "Enter student name: "; cin >> g.studentName;
    cout << "Enter subject: "; cin >> g.subject;
    cout << "Enter grades (end with -1): ";
    while (cin >> mark && mark != -1) {
        g.marks.push_back(mark);
    }
    grades.push_back(g);
}

void saveToFile() {
    ofstream file("journal_data.txt");
    for (const auto& s : students) {
        file << "Student: " << s.name << endl;
    }
    for (const auto& sub : subjects) {
        file << "Subject: " << sub.name << ", Lessons per week: " << sub.lessonsPerWeek << endl;
    }
    for (const auto& g : grades) {
        file << "Grade: " << g.studentName << ", " << g.subject << " - ";
        for (int m : g.marks) file << m << " ";
        file << endl;
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "1. Add Student\n2. Add Subject\n3. Add Grades\n4. Save to File\n5. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
        case 1: addStudent(); break;
        case 2: addSubject(); break;
        case 3: addGrade(); break;
        case 4: saveToFile(); break;
        }
    } while (choice != 5);
}
