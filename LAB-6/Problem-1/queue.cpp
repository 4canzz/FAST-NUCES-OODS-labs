#include <iostream>
#include "queue.h"
using namespace std;

template <typename DT>
class Node
{
public:
	Node(DT element) : data(element), next(NULL) {}
	void setData(DT pVal) { data = pVal; }
	DT getData() { return data; }
	Node* GetNext() { return next; }
	void SetNext(Node *x) { next = x; }
private:
	DT data;
	Node *next;
};

template <class DT>
Queue<DT>::Queue() : front(NULL), rear(NULL) {}

template <class DT>
void Queue<DT>::Put(DT element) {
	Node<DT>* temp = new Node<DT>(element);
	if (IsEmpty()) {
		rear = front = temp;
	}
	else rear->SetNext(temp);
	rear = temp;
}

template <class DT>
DT Queue<DT>::Get() {
	if (IsEmpty()) throw runtime_error("Queue is empty");
	Node<DT>* del = front;
	DT val = del->getData();
	if (front == rear) front = rear = NULL;
	else front = front->GetNext();
	delete del;
	return val;
}

template <class DT>
bool Queue<DT>::IsEmpty() { return front == NULL && rear == NULL; }

template <class DT>
bool Queue<DT>::IsFull() { return false; }