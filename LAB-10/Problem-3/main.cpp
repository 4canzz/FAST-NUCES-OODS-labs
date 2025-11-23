#include <iostream>
#include "MinHeap.h"
#include "MinHeap.cpp"
using namespace std;

int main() {
    MinHeap<int> landingQueue(100);     
    cout << "Welcome to Lahore airport civil aviation landing system" << endl;

    while (true) {
        cout << "Is there an aircraft in airspace requesting to land? (Y/N)\n";
        string ans;
        cin >> ans;

        if (ans == "N") break;

        if (ans == "Y") {
            cout << "Please enter the amount of fuel present in the aircraft: " << endl;
            int fuel;
            cin >> fuel;
            landingQueue.insert(fuel);
        }
        else {
            cout << "Invalid input, please type Yes or No." << endl;
        }
    }

    cout << endl << "Grant access of runway to the aircrafts in the following order:" << endl;

    while (!landingQueue.isEmpty()) {
        int fuel = landingQueue.Delete();
        cout << "Aircraft with " << fuel << " units of fuel" << endl;
    }

    return 0;
}
