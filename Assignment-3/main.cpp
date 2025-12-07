#include "DeliveryApp.h"
#include <iostream>
using namespace std;

int main() {
    int hashSize = 10;
    DeliveryApp app(hashSize);

    int choice;
    do {
        cout << endl <<"=== Delivery App Menu ===" << endl;
        cout << "1. Insert Shipment" << endl;
        cout << "2. Find Route for Shipment" << endl;
        cout << "3. Print Route Map" << endl;
        cout << "4. Add Route" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                string sender, receiver, fromCity, toCity;
                cout << "Enter Shipment ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Sender Name: ";
                getline(cin, sender);
                cout << "Enter Receiver Name: ";
                getline(cin, receiver);
                cout << "Enter Source City: ";
                getline(cin, fromCity);
                cout << "Enter Destination City: ";
                getline(cin, toCity);

                if (app.insertShipment(id, sender, receiver, fromCity, toCity)) {
                    cout << "Shipment inserted successfully." << endl;
                } else {
                    cout << "Failed to insert shipment (ID may already exist)." << endl;
                }
                break;
            }
            case 2: {
                int shipmentID;
                cout << "Enter Shipment ID: ";
                cin >> shipmentID;
                app.findRouteForShipment(shipmentID);
                break;
            }
            case 3:
                app.printMap();
                break;
            case 4: {
                int from, to, distance;
                cout << "Enter From City index (0-Lahore,1-Islamabad,2-Karachi,3-Multan,4-Peshawar): ";
                cin >> from;
                cout << "Enter To City index: ";
                cin >> to;
                cout << "Enter distance: ";
                cin >> distance;
                app.addRoute(from, to, distance);
                cout << "Route added successfully." << endl;
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
