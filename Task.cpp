#include <iostream>
#include <map>
#include <string>

using namespace std;

void displayMenu() {
    cout << "1. Add Contact" << endl;
    cout << "2. Search Contact" << endl;
    cout << "3. Display All Contacts" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    map<string, string> contacts;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, phoneNumber;
            cout << "Enter the Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter the phone number: ";
            getline(cin, phoneNumber);
            contacts[name] = phoneNumber;
            cout << "Contact added successfully." << endl;
            break;
        }
        case 2: {
            string name;
            cout << "Enter the Name to search: ";
            cin.ignore();
            getline(cin, name);
            auto it = contacts.find(name);
            if (it != contacts.end()) {
                cout << "Phone number: " << it->second << endl;
            }
            else {
                cout << "Contact doesn't Exist" << endl;
            }
            break;
        }
        case 3: {
            if (contacts.empty()) {
                cout << "No contacts to display." << endl;
            }
            else {
                cout << "All contacts:" << endl;
                for (const auto& pair : contacts) {
                    cout << "Name: " << pair.first << ", Phone number: " << pair.second << endl;
                }
            }
            break;
        }
        case 4: {
            cout << "Program Exited." << endl;
            break;
        }
        default: {
            cout << "Invalid choice." << endl;
            break;
        }
        }
    } while (choice != 4);

    return 0;
    system("pause");
}