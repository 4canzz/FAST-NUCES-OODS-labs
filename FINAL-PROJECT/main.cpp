#include <iostream>
#include <limits>
#include "STTS.h"
using namespace std;

void displayMenu() {
    cout << endl <<"--- Smart Transport & Ticketing System ---" << endl;
    cout << "1. Book Ticket" << endl;
    cout << "2. Undo Last Booking" << endl;
    cout << "3. Plan Travel (Shortest Path)" << endl;
    cout << "4. View Daily Report" << endl;
    cout << "5. Register New Passenger" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";
}

void cleanInput() {
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

int main() {
    STTSystem system(500, 100, 6);

    cout << "Initializing System..." << endl;
    system.loadData("passenger.txt", "routes.txt"); 

    int choice;
    while (true) {
        displayMenu();
        
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number." << endl;
            cleanInput();
            continue;
        }

        switch (choice) {
        case 1: {
            int pID, rID;
            string date;
            
            cout << endl << "--- New Booking ---" << endl;
            cout << "Enter Passenger ID: "; 
            if (!(cin >> pID)) { 
                cout << "Invalid ID." << endl;
                cleanInput();
                break; 
            }
            
            cout << "Enter Route ID: "; 
            if (!(cin >> rID)) { 
                cout << "Invalid ID." << endl;
                cleanInput();
                break;
            }
            
            cout << "Enter Date (DD-MM-YYYY): "; 
            cin >> date;

            system.bookTicket(pID, rID, date);
            break;
        }
        case 2: 
            system.undoLastAction();
            break;
        case 3: { 
            int u, v;
            cout << endl << "--- Available Cities ---" << endl;

            for (int i = 0; i < 6; i++) {
                cout << "[" << i << "] " << cityname[i];
                if (i < 5) cout << "    ";
                if ((i + 1) % 3 == 0) cout << endl; 
            }
            cout << "------------------------" << endl;
            
            cout << "Enter Source City ID: ";
            if (!(cin >> u)) { cout << "Invalid Input." << endl; cleanInput(); break; }
            
            cout << "Enter Destination City ID: ";
            if (!(cin >> v)) { cout << "Invalid Input." << endl; cleanInput(); break; }

            system.showRoute(u, v);
            break;
        }
        case 4: 
            system.generateAdminReport();
            break;
        case 5: { 
            int id;
            string name, cnic, phone;
            cout << endl << "--- Register New Passenger ---" << endl;
            cout << "Enter ID: ";
            if (!(cin >> id)) { 
                cout << "Invalid ID." << endl;
                cleanInput();
                break;
            }
            
            cout << "Enter Name (No_Spaces): ";
            cin >> name;
            cout << "Enter CNIC: ";
            cin >> cnic;
            cout << "Enter Phone: ";
            cin >> phone;
            
            system.registerPassenger(id, name, cnic, phone);
            break;
        }
        case 6:
            cout << "Exiting system. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please select 1-5." << endl;
        }
    }
    return 0;
}