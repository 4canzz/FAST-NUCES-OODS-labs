#include <iostream>
#include <stdexcept>
#include "stack.h"
using namespace std;

template <typename T>  
class Node 
{ 
public: 
	Node(T element) : data(element), next(NULL) {}
	void setData(T pVal) { data = pVal; }  
	T getData() { return data; } 
	Node* GetNext() { return next; }
	void SetNext(Node *x) { next = x; }
private: 
	T data; 
	Node *next; 
};


template <typename T>  
class SList { 
public:  
	SList() : head(NULL) {}
    void setHead(Node<T>* h) { head = h;}
    Node<T>* getHead() {return head;}
private:
	Node<T> *head ;
};

template<class KeyType>
Stack<KeyType>::Stack() : list(new SList<KeyType>()), top(NULL) {}

template<class KeyType>
bool Stack<KeyType>::IsFull() { return false; }

template<class KeyType>
bool Stack<KeyType>::IsEmpty() { return top == NULL; }

template<class KeyType>
void Stack<KeyType>::Push(const KeyType item) {
    Node<KeyType>* pnew = new Node<KeyType>(item);
    pnew->SetNext(top);
    top = pnew;
    list->setHead(top);
}

template<class KeyType>
KeyType Stack<KeyType>::Pop() {
    if(IsEmpty()) throw invalid_argument("List is Empty, cannot pop");
    Node<KeyType>* temp = top;
    KeyType popped = temp->getData();
    top = top->GetNext();
    list->setHead(top);
    delete temp;
    return popped;
}