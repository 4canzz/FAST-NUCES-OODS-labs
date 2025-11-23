#pragma once
#include <iostream>
using namespace std;

template <class DT>
class BNode {
private:
	DT data;
	BNode<DT>* leftchild;
	BNode<DT>* rightchild;
public:
	BNode() : leftchild(NULL), rightchild(NULL), data(DT()) {}
	void setLeftChild(BNode<DT>* x) { leftchild = x; }
	BNode<DT>* getLeftChild() { return leftchild; }
	void setRightChild(BNode<DT>* x) { rightchild = x; }
	BNode<DT>* getRightChild() { return rightchild; }
	void setData(DT pdata) { data = pdata; }
	DT getData() { return data; }
};