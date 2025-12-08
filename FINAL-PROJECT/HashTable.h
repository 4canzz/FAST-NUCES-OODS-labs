#pragma once
#include "List.h"
using namespace std;

template<class T>
class Hashtable {
private:
    int size;
    SLList<T>** arr;
    int hash(T key) { return (int) key % size; }
public:
    Hashtable(int hashsize) : size(hashsize), arr(new SLList<T>* [size]) {
        for (int i = 0; i < size; i++) {
            arr[i] = new SLList<T>();
        }
    }
    bool store(T key) {
        int index = hash(key);
        if (!arr[index]->Search(key)) {
            arr[index]->Insert(key);
            return true;
        }
        return false;
    }

    bool remove(T key) {
        int index = hash(key);
        SNode<T>* target = arr[index]->Search(key);

        if (target != NULL) {
            arr[index]->Delete(target);
            return true; 
        }
        return false;
    }


    SNode<T>* search(T key) {
        int index = hash(key);
        if (arr[index]->Search(key)) {
            return arr[index]->Search(key);
        }
        return NULL;
    }

    void printdata() {
        for (int i = 0; i < size; i++) {
            if (arr[i]->GetHead() != NULL) arr[i]->printList();
        }
    }

    void saveToFile(string filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "Error: Could not save to " << filename << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            SNode<T>* temp = arr[i]->GetHead();
            while (temp != NULL) {
                outFile << temp->getData().fileFormat() << endl;
                temp = temp->GetNext();
            }
        }
        outFile.close();
    }

    int getSize() { return size; }

    SNode<T>* getBucketHead(int i){
        return arr[i]->GetHead();
    }

    ~Hashtable() {
        for (int i = 0; i < size; i++) {
            delete arr[i];
        }
        delete[] arr;
    }
};