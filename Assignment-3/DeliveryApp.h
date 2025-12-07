#pragma once
#include "Graph.h"
#include "Hashtable.h"
#include <iostream>
using namespace std;

class DeliveryApp {
private:
    Graph graph;
    HashTable shipments;
public:
    DeliveryApp(int hashSize);
    void addRoute(int fromCity, int toCity, int distance);
    bool insertShipment(int id, string sender, string receiver, string src, string dest);
    void findRouteForShipment(int shipmentID);
    void printMap();
};
