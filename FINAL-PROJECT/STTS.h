#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "Graph.h"
#include "HashTable.h"

using namespace std;

const string cityname[6] = { "Lahore", "Islamabad", "Karachi", "Peshawar", "Chinot", "Multan" };

class Passenger {
private:
    int passengerID;
    string name;
    string cnic;
    string phone;

public:
    Passenger() : passengerID(0), name(""), cnic(""), phone("") {}
    Passenger(int id, string n, string c, string p) : passengerID(id), name(n), cnic(c), phone(p) {}

    int getID() const { return passengerID; }
    string getName() const { return name; }

    operator int() const { return passengerID; }

    bool operator==(const Passenger& other) const { return this->passengerID == other.passengerID; }

    string fileFormat() const {
        return to_string(passengerID) + " " + name + " " + cnic + " " + phone;
    }

    friend ostream& operator<<(ostream& os, const Passenger& p) {
        os << "[ID: " << p.passengerID << " | Name: " << p.name << "]";
        return os;
    }
};

class Route {
private:
    int routeID;
    int sourceCity;
    int destinationCity;
    int distance;
    int baseFare;
    int seatCapacity;
public:
    Route() : routeID(0), sourceCity(0), destinationCity(0), distance(0), baseFare(0), seatCapacity(0) {}
    Route(int id, int src, int dest, int dist, int fare, int cap)
        : routeID(id), sourceCity(src), destinationCity(dest), distance(dist), baseFare(fare), seatCapacity(cap) {}

    int getID() const { return routeID; }
    int getSource() const { return sourceCity; }
    int getDestination() const { return destinationCity; }
    int getDistance() const { return distance; }
    int getFare() const { return baseFare; }
    int getSeatCapacity() const { return seatCapacity; }

    void decreaseSeats() {
        if (seatCapacity > 0) seatCapacity--;
    }

    void increaseSeats() {
        seatCapacity++;
    }

    operator int() const { return routeID; }

    string fileFormat() const {
        return to_string(routeID) + " " + to_string(sourceCity) + " " +
            to_string(destinationCity) + " " + to_string(distance) + " " +
            to_string(baseFare) + " " + to_string(seatCapacity);
    }

    bool operator==(const Route& other) const { return this->routeID == other.routeID; }

    friend ostream& operator<<(ostream& os, const Route& r) {
        os << "[Route: " << r.routeID << " | " << cityname[r.sourceCity] << "->" << cityname[r.destinationCity]
            << " | Seats: " << r.seatCapacity << "]";
        return os;
    }
};

class Booking {
private:
    int bookingID;
    int passengerID;
    int routeID;
    int seatNumber;
    string date;
    int fare;
public:
    Booking() : bookingID(0), passengerID(0), routeID(0), seatNumber(0), date(""), fare(0) {}
    Booking(int id, int pID, int rID, int seat, string d, int f)
        : bookingID(id), passengerID(pID), routeID(rID), seatNumber(seat), date(d), fare(f) {}

    int getID() const { return bookingID; }
    int getRouteID() const { return routeID; }

    operator int() const { return bookingID; }

    bool operator==(const Booking& other) const { return this->bookingID == other.bookingID; }

    friend ostream& operator<<(ostream& os, const Booking& b) {
        os << "[Booking: " << b.bookingID << " | Pass: " << b.passengerID << " | Route: " << b.routeID << "]";
        return os;
    }
};

struct Action {
    string type;
    Booking data;
};

class STTSystem {
private:
    Hashtable<Passenger> passengers;
    Hashtable<Route> routes;
    Hashtable<Booking> activeBookings;
    Graph cityMap;
    Stack<Action> undoStack;
    Queue<int> waitList;
    int bookingCounter;
    long totalRevenue;
public:
    STTSystem(int pSize, int rSize, int cities)
        : passengers(pSize), routes(rSize), activeBookings(500), cityMap(cities), bookingCounter(1), totalRevenue(0) {}

    void loadData(string pFile, string rFile) {
        ifstream inFile;

        inFile.open(pFile);
        if (!inFile) cout << "Error: Could not open " << pFile << endl;
        else {
            int id;
            string name, cnic, phone;

            while (inFile >> id >> name >> cnic >> phone) {
                Passenger p(id, name, cnic, phone);
                passengers.store(p);
            }
            inFile.close();
        }

        inFile.open(rFile);
        if (!inFile) cout << "Error: Could not open " << rFile << endl;
        else {
            int id, src, dest, dist, fare, cap;

            while (inFile >> id >> src >> dest >> dist >> fare >> cap) {
                Route r(id, src, dest, dist, fare, cap);
                routes.store(r);
                cityMap.addEdge(src, dest, dist);
            }
            inFile.close();
        }
    }

    void bookTicket(int pID, int rID, string date) {
        Passenger pQuery(pID, "", "", "");
        Route rQuery(rID, 0, 0, 0, 0, 0);

        if (!passengers.search(pQuery)) {
            cout << "Error: Passenger ID " << pID << " not found!" << endl; return;
        }

        SNode<Route>* routeNode = routes.search(rQuery);
        if (routeNode == NULL) {
            cout << "Error: Route ID " << rID << " not found!" << endl; return;
        }

        Route r = routeNode->getData();

        if (r.getSeatCapacity() <= 0) {
            cout << endl << "! Route " << rID << " is FULL." << endl;
            cout << "! Adding Passenger " << pID << " to the Waitlist..." << endl;
            waitList.put(pID);
            return;
        }

        r.decreaseSeats();
        routeNode->setData(r);

        int currentFare = r.getFare();
        Booking newBooking(bookingCounter++, pID, rID, 1, date, currentFare);

        Action act;
        act.type = "BOOK";
        act.data = newBooking;
        undoStack.push(act);
        activeBookings.store(newBooking);

        totalRevenue += currentFare;

        cout << "Success! Ticket Booked." << endl;
        cout << endl;
        cout << " Ticket Details            " << endl;
        cout << "-----------------------------------------" << endl;
        cout << " Booking ID:   " << newBooking.getID() << endl;
        cout << " Passenger ID: " << pID << endl;
        cout << " Route:        " << cityname[r.getSource()] << " --> " << cityname[r.getDestination()] << endl;
        cout << " Date:         " << date << endl;
        cout << " Distance:     " << r.getDistance() << " km" << endl;
        cout << " Amount Paid:  PKR " << currentFare << endl;
        cout << "-----------------------------------------" << endl << endl;
    }

    void registerPassenger(int id, string name, string cnic, string phone) {
        Passenger p(id, name, cnic, phone);
        if (passengers.store(p)) cout << "Success: Passenger " << name << " (ID: " << id << ") registered." << endl;
        else cout << "Error: Passenger ID " << id << " already exists." << endl;
    }

    void undoLastAction() {
        if (undoStack.isEmpty()) {
            cout << "Nothing to undo." << endl;
            return;
        }

        Action last = undoStack.peek();
        undoStack.pop();

        if (last.type == "BOOK") {
            if (activeBookings.remove(last.data)) cout << "Booking Record " << last.data.getID() << " deleted." << endl;

            int rID = last.data.getRouteID();
            Route queryRoute(rID, 0, 0, 0, 0, 0);
            SNode<Route>* routeNode = routes.search(queryRoute);

            if (routeNode != NULL) {
                Route r = routeNode->getData();
                r.increaseSeats();
                routeNode->setData(r);

                totalRevenue -= r.getFare();

                cout << "Undo Successful: Seat freed for Route " << rID << "." << endl;
                cout << "Revenue Refunded: PKR " << r.getFare() << endl;

                if (!waitList.isEmpty()) {
                    int nextPassenger = waitList.get();
                    cout << endl << "ALERT: Seat available on Route " << rID << "!" << endl;
                    cout << "Passenger " << nextPassenger << " removed from Waitlist." << endl;
                    cout << "Please book ticket for Passenger " << nextPassenger << " manually." << endl;
                }
            }
        }
    }

    void generateAdminReport() {
        cout << endl;
        cout << "Daily Booking & Revenue Report: " << endl;
        cout << endl;
        cout << "Total Revenue Generated: PKR " << totalRevenue << endl;
        cout << "Active Bookings Log:" << endl;
        activeBookings.printdata();
        cout << "Waitlist Status: ";
        if (waitList.isEmpty()) cout << "Empty";
        else {
            cout << "(Next IDs): ";
            waitList.print();
        }

        cout << endl;
    }

    void showRoute(int src, int dest) {
        if (src >= cityMap.getV() || dest >= cityMap.getV()) {
            cout << "Invalid city IDs." << endl;
            return;
        }

        int* dist = new int[cityMap.getV()];
        cityMap.dijkstra(src, dist);

        if (dist[dest] == INT_MAX) cout << "No route exists between City " << src << " and City " << dest << endl;
        else cout << "Shortest distance: " << dist[dest] << " km" << endl;

        delete[] dist;
    }

    void saveChanges(string pFile, string rFile) {
        passengers.saveToFile(pFile);
        routes.saveToFile(rFile);
    }

    int findRouteID(int src, int dest) {
        for (int i = 0; i < routes.getSize(); i++) {
            SNode<Route>* temp = routes.getBucketHead(i);
            while (temp != NULL) {
                Route r = temp->getData();
                if (r.getSource() == src && r.getDestination() == dest) {
                    return r.getID();
                }
                temp = temp->GetNext();
            }
        }
        return -1;
    }
};