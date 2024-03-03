#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct student {
    int id;
    string name;
    double grade = -1.0;
};

bool comparestudents(const student& a, const student& b) {
    return a.id < b.id;
}

int main() {
    vector<student> students;
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Update grade" << endl;
        cout << "3. View all students" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name;
            double grade;

            cout << "Enter student ID: ";
            cin >> id;
            if (find_if(students.begin(), students.end(),
                [id](const student& s) { return s.id == id; }) != students.end()) {
                cout << "Error: student ID already exists." << endl;
            }
            else {
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter student grade: ";
                cin >> grade;

                students.push_back({ id, name, grade });
                cout << "Student added successfully" << endl;
            }
            break;
        }
        case 2: {
            int id;
            double grade;

            cout << "Enter student ID to update grade: ";
            cin >> id;

            auto it = find_if(students.begin(), students.end(),
                [id](const student& s) { return s.id == id; });

            if (it == students.end()) {
                cout << "Error: student not found." << endl;
            }
            else {
                cout << "Enter new grade: ";
                cin >> grade;
                it->grade = grade;
                cout << "Grade updated successfully" << endl;
            }
            break;
        }
        case 3: {
            if (students.empty()) {
                cout << "No students added yet." << endl;
            }
            else {
                sort(students.begin(), students.end(), comparestudents);
                cout << "id\tname\tgrade\n";
                for (const student& student : students) {
                    cout << student.id << "\t" << student.name << "\t";
                    if (student.grade == -1.0) {
                        cout << "Not entered" << endl;
                    }
                    else {
                        cout << student.grade << endl;
                    }
                }
            }
            break;
        }
        case 4: {
            cout << "Program exited" << endl;
            break;
        }
        default: {
            cout << "Invalid choice." << endl;
        }
        }
    } while (choice != 4);

    return 0;
    system("pause");
}