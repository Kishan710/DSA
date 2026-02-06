#include <iostream>
#include <vector>
#include <string>
using namespace std;


template <typename T1, typename T2>
class MemoryCalculate {
public:
    T1 id;
    T2 name;


    MemoryCalculate(T1 id, T2 name) {
        this->id = id;
        this->name = name;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    vector<MemoryCalculate<int, string>> students;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);

            students.push_back(MemoryCalculate<int, string>(id, name));
            cout << "Student Added Successfully!\n";
        }
        else if (choice == 2) {
            if (students.empty()) {
                cout << "No students found.\n";
            } else {
                cout << "\n--- Student List ---\n";
                for (const auto &s : students) {
                    s.display();
                }
            }
        }
        else if (choice == 3) {
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;

            bool found = false;
            for (auto it = students.begin(); it != students.end(); ++it) {
                if (it->id == id) {
                    students.erase(it);
                    cout << "Student Removed Successfully!\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student with given ID not found.\n";
            }
        }
        else if (choice == 4) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;

            bool found = false;
            for (const auto &s : students) {
                if (s.id == id) {
                    cout << "Student Found:\n";
                    s.display();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student with given ID not found.\n";
            }
        }
        else if (choice == 0) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);
}
