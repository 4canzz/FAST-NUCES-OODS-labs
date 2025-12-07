#pragma once
#include <stdexcept>
#include "List.h"

template <typename T>
class Queue {
private:
    SNode<T>* front;
    SNode<T>* rear;
public:
    Queue() { front = NULL; rear = NULL; }
    bool isEmpty() { return front == NULL && rear == NULL; }

    void put(T value) {
        SNode<T>* temp = new SNode<T>(value);
        if (!front) { 
            front = rear = temp; 
            return; 
        }
        rear->SetNext(temp);
        rear = temp;
    }

    T get() {
        if (isEmpty()) throw runtime_error("Queue is empty");
        SNode<T>* del = front;
        T val = del->getData();
        if (front == rear) {
            front = rear = NULL;
        }   
        else front = front->GetNext();
        delete del;
        return val;
    }

    void print() {
        SNode<T>* temp = front;
        while (temp) {
            cout << temp->getData() << " ";
            temp = temp->GetNext(); 
        }
        cout << endl;
    }

    ~Queue() {
        while (front) {
            SNode<T>* temp = front;
            front = front->GetNext();
            delete temp; 
        }
        rear = NULL;
    }
};