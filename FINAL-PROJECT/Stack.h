#pragma once
#include <stdexcept>
#include "List.h"

template <typename T>
class Stack {
private:
    SNode<T>* top;
public:
    Stack() : top(NULL) {}
    bool isEmpty() { return top == NULL; }

    void push(T value) {
        SNode<T>* temp = new SNode<T>(value);
        temp->SetNext(top);
        top = temp;
    }

    bool pop() {
        if (!top) return false;
        SNode<T>* temp = top;
        top = top->GetNext();
        delete temp;
        return true;
    }

    T peek() { 
        if (!top) throw runtime_error("Stack empty");
        return top->getData();
    }

    void print() {
        SNode<T>* temp = top;
        while (temp) { 
            cout << temp->getData() << " ";
            temp = temp->GetNext(); 
        }
        cout << endl;
    }

    ~Stack() {
        while (top) { 
            SNode<T>* temp = top;
            top = top->GetNext();
            delete temp; 
        }
    }
};