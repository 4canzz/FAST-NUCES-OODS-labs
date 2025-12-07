#include "DeliveryApp.h"
#include <iostream>
using namespace std;

DeliveryApp::DeliveryApp(int hashSize) : shipments(hashSize) {
    graph.addRoute(0, 1, 380);
    graph.addRoute(0, 3, 350);
    graph.addRoute(1, 2, 1400);
    graph.addRoute(2, 3, 900);
}

void DeliveryApp::addRoute(int fromCity, int toCity, int distance) {
    graph.addRoute(fromCity, toCity, distance);
}

bool DeliveryApp::insertShipment(int id, string sender, string receiver, string src, string dest) {
    return shipments.insertShipment(id, sender, receiver, src, dest);
}
void DeliveryApp::findRouteForShipment(int shipmentID) {

    Shipment* s = shipments.searchShipment(shipmentID);
    if (!s) {
        cout << "Shipment ID " << shipmentID << " not found." << endl;
        return;
    }

    int srcIndex = graph.getCityIndex(s->FromCity);
    int destIndex = graph.getCityIndex(s->ToCity);

    if (srcIndex == -1 || destIndex == -1) {
        cout << "Invalid cities for shipment." << endl;
        return;
    }

    cout << endl << "Route for shipment " << shipmentID << " (" << s->FromCity << " -> " << s->ToCity << "): "<< endl ;
    graph.findShortestRoute(srcIndex, destIndex);
}

void DeliveryApp::printMap() { graph.printRouteMap(); }