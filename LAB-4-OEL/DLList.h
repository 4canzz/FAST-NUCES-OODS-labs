#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class DLList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    DLList() : head(NULL), tail(NULL) {}
    ~DLList() {
		Node<T>* temp = head;
    	while (temp) {
			Node<T>* next = temp->GetNext();
			delete temp;
			temp = next;
	    }
    }

    void push_back(const T& newData) {
        Node<T>* newNode = new Node<T>(newData);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->SetNext(newNode);       
        newNode->SetPrev(tail);
        tail = newNode; 
    }

    bool Delete(Node<T>* pTobeDeleted) {
        if (!pTobeDeleted) return false;
        if (pTobeDeleted->GetPrev()) pTobeDeleted->GetPrev()->SetNext(pTobeDeleted->GetNext());
        else head = pTobeDeleted->GetNext();
        if (pTobeDeleted->GetNext()) pTobeDeleted->GetNext()->SetPrev(pTobeDeleted->GetPrev());
        else tail = pTobeDeleted->GetPrev();
        delete pTobeDeleted;
        return true;
    }   

    void printList() {
        if (!head) {
            cout << endl << "No voters currently available." << endl;
            return;
        }
        Node<T>* temp = head;
        cout << endl << "--- Current Voters ---" << endl;
        while (temp) {
            cout << temp->getData();
            temp = temp->GetNext();
        }
        cout << "-------------------------" << endl;
    }

    Node<T>* SearchbyCNIC(string CNIC) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->getData().cnic == CNIC) return temp;
            temp = temp->GetNext();
        }
        return NULL;
    }

    Node<T>* getMaxVotes() {
        if (!head) return NULL;
        Node<T>* maxNode = head;
        Node<T>* temp = head->GetNext();
        while (temp) {
            if (temp->getData().voteCount > maxNode->getData().voteCount) {
                maxNode = temp;
            }
            temp = temp->GetNext();
        }
        return maxNode;
    }
};
