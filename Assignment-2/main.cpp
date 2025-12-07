#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"
using namespace std;

int main() {
    BST tree;
    ifstream file;
    file.open("employee.txt");

    if (!file.is_open()) {
        cout << "Error: employees.txt not found.\n";
        return 1;
    }

    Employee e;
    while (file >> e.id >> e.firstName >> e.lastName >> e.department >> e.salary) tree.insert(e);


    int choice;
    do {
        cout << endl << "--- Employee Management System ---" << endl;
        cout << "1. Display Employees (Ascending)" << endl;
        cout << "2. Display Employees (Descending)" << endl;
        cout << "3. Search Employee by ID" << endl;
        cout << "4. Add Employee by ID" << endl;
        cout << "5. Remove Employee by ID" <<endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << endl << "Employees (Ascending Order):" << endl ;
            tree.displayAscending();
            break;
        case 2:
            cout << endl << "Employees (Descending Order):" << endl;
            tree.displayDescending();
            break;
        case 3: {
            int id;
            cout << "Enter Employee ID to search: ";
            cin >> id;
            tree.search(id);
            break;
        }
        case 4: {
            ofstream out("employee.txt", ios::app);
            Employee e;
            cout << "Enter Employee ID, First Name, Last Name, Department, Salary in the preceeding format." << endl;
            cin >> e.id >> e.firstName >> e.lastName >> e.department >> e.salary;
            if (tree.insert(e))  {
                cout << "Employee Added successfully";
                out << endl << e << endl;
            }
            out.close();
            break;
        }
        case 5: {
            int id;
            cout << "Enter Employee ID to remove: ";
            cin >> id;
            if (tree.remove(id)) {
                cout << "Employee removed successfully." << endl;
                tree.saveToFile("employee.txt");
            } else cout << "Employee not found." << endl;
            break;
        }
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 6);

    file.close();
    return 0;
}
