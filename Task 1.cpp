#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> names;

    vector<double> grades;

    int choice;
    do {
        cout << "Menu: " << endl;
        cout << "1. Add student" << endl;
        cout << "2. View student grades" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            double grade;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter student grade: ";
            cin >> grade;

            if (grades.size() < names.size()) {
                grades.resize(names.size(), -1.0);
            }
            names.push_back(name);
            grades.push_back(grade);
            cout << "Student added successfully " << endl;
            break;
        }
        case 2: {
            if (names.empty()) {
                cout << "No students added yet." << endl;
            }
            else {
                for (int i = 0; i < names.size(); ++i) {
                    if (grades[i] == -1.0) {
                        cout << names[i] << ": Grade not entered yet." << endl;
                    }
                    else {
                        cout << names[i] << ": " << grades[i] << endl;
                    }
                }
            }
            break;
        }
        case 3: {
            cout << "Program Exited" << endl;
            break;
        }
        default: {
            cout << "Invalid choice." << endl;
        }
        }
    } while (choice != 3);

    return 0;
    system("pause");
}