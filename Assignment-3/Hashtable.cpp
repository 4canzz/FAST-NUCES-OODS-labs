#include <iostream>
#include <string>
#include "Hashtable.h"
using namespace std;

HashTable::HashTable(int hashsize) : SIZE(hashsize), table(new Shipment[hashsize]), occupied(new bool[hashsize]()) {
    for (int i = 0; i < SIZE; i++)
        table[i].id = -1;
}

int HashTable::hashFunction(int key) { return key % SIZE; }


bool HashTable::insertShipment(int ID, string s, string r, string fromcity, string tocity) {
    Shipment temp(ID, s, r, fromcity, tocity);
    int index = hashFunction(ID);
    int j = index;

    do {
        if (!occupied[j] && (table[j].id == -1 || table[j].id == -2)) {
            table[j] = temp;
            occupied[j] = true;
            cout << "Stored Shipment of id " << ID << " successfully" << endl;
            return true;
        }

        if (occupied[j] && table[j].id == ID) {
            cout << "Key already exists at index " << j << endl;
            return false;
        }

        j = hashFunction(j + 1);
    } while (j != index);
    cout << "Table full, cannot store " << ID << endl;
    return false;
}

Shipment* HashTable::searchShipment(int id) {
    int index = hashFunction(id);
    int j = index;

    do {
        if (occupied[j] && table[j].id == id) return &table[j];
        if (!occupied[j] && table[j].id == -1) return NULL;
        j = hashFunction(j + 1);
    } while (j != index);
    return NULL;
}

void HashTable::removeShipment(int id) {
    int index = hashFunction(id);
    int j = index;

    do {
        if (occupied[j] && table[j].id == id) {
            table[j].id = -2;
            occupied[j] = false;
            cout << "Deleted Shipment of id " << id << " successfully" << endl;
            return; 
        }

        if (!occupied[j] && table[j].id == -1) {
            cout << "Shipment of ID " << id << " does not exist" << endl;
            return;
        }

        j = hashFunction(j + 1);
    } while (j != index);
}


/*
State	    occupied    id
Never used	false	    -1
Used	    true	    >= 0
Tombstone	false	    -2
*/