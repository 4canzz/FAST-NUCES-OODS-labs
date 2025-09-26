#pragma once
template <typename T>
class Node { 
private: 
	T data; 
	Node *next;
    Node *prev; 
public: 
	Node(T val) : data(val), next(NULL), prev(NULL) {}
	void setData(T val) { data = val; }
	T& getData() { return data; }
	Node<T>* GetNext() { return next; }
	void SetNext(Node *x) { next = x; }
    Node<T>* GetPrev() { return prev; }
    void SetPrev(Node *x) { prev = x; }
};