#pragma once
#include <iostream>
#include <string>
using namespace std;

class Shipment {
public:
    Shipment() : id(-1), sender(""), receiver(""), FromCity(""), ToCity("") {}
    Shipment(int ID, string s, string r, string fromcity, string tocity)
     : id(ID), sender(s), receiver(r), FromCity(fromcity), ToCity(tocity) {}
    int id;
    string sender;
    string receiver;
    string FromCity;
    string ToCity;
};

class HashTable {
private:
    int SIZE;
    Shipment * table;
    bool* occupied;
public:
    HashTable(int hashsize);
    int hashFunction(int key);
    bool insertShipment(int id, string s, string r, string fromcity, string tocity);
    Shipment * searchShipment(int id);
    void removeShipment(int id);
};