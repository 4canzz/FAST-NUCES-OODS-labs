#pragma once
#include <iostream>
using namespace std;

template <typename T>
class SNode {
private:
    T data;
    SNode* next;
public:
    SNode(T element) : data(element), next(NULL) {}
    void setData(T pVal) { data = pVal; }
    T getData() const { return data; }
    SNode* GetNext() const { return next; }
    void SetNext(SNode* x) { next = x; }
};

template <typename T>
class SLList {
private:
    SNode<T>* head;
public:
    SLList() : head(NULL) {}
    SNode<T>* GetHead() const { return head; }

    //overloaded Insert() for HashTable.h
    void Insert(T val) {
        SNode<T>* pnew = new SNode<T>(val);
        if (!head) head = pnew;
        else {
            pnew->SetNext(head);
            head = pnew;
        }
    }

    bool Insert(SNode<T>* pBefore, SNode<T>* pNew) {
        if (!pNew) return false;

        if (!pBefore) {
            pNew->SetNext(head);
            head = pNew;
            return true;
        }

        pNew->SetNext(pBefore->GetNext());
        pBefore->SetNext(pNew);
        return true;
    }

    bool Delete(SNode<T>* pToBeDeleted) {
        if (!pToBeDeleted || !head) return false;

        if (head == pToBeDeleted) {
            head = head->GetNext();
            delete pToBeDeleted;
            return true;
        }

        SNode<T>* temp = head;
        while (temp && temp->GetNext() != pToBeDeleted)
            temp = temp->GetNext();

        if (!temp) return false;

        temp->SetNext(pToBeDeleted->GetNext());
        delete pToBeDeleted;
        return true;
    }

    SNode<T>* Search(T value) {
        SNode<T>* temp = head;
        while (temp) {
            if (temp->getData() == value) return temp;
            temp = temp->GetNext();
        }
        return NULL;
    }
    void printList() {
        SNode<T>* temp = head;
        while (temp) {
            cout << temp->getData() << " ";
            temp = temp->GetNext();
        }
        cout << endl;
    }
    ~SLList() {
        SNode<T>* temp = head;
        while (temp) {
            SNode<T>* next = temp->GetNext();
            delete temp;
            temp = next;
        }
        head = NULL;
    }
};
