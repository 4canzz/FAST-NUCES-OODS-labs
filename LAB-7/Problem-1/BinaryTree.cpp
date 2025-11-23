#include<iostream>
#include"BinaryTree.h"
using namespace std;

template<class DT>
BNode<DT>::BNode() : rightchild(NULL), leftchild(NULL), data(DT()) {}

template<class DT>
void BNode<DT>::setLeftChild(BNode<DT>* n) { leftchild = n; }

template<class DT>
BNode<DT>* BNode<DT>::getLeftChild() { return leftchild; }

template<class DT>
void BNode<DT>::setRightChild(BNode<DT>* n) { rightchild = n; }

template<class DT>
BNode<DT>* BNode<DT>::getRightChild() { return rightchild; }

template<class DT>
void BNode<DT>::setData(DT pdate) { data = pdate; }

template<class DT>
DT BNode<DT>::getData() { return data; }

template<class DT>
BinaryTree<DT>::BinaryTree() : root(NULL) {}

template<class DT>
void BinaryTree<DT>::BuildTree(DT *Arr, int Size) {
    if(Size <= 1) return;
    BNode<DT>** nodes = new BNode<DT>*[Size];
    for(int i = 0; i < Size; i++) nodes[i] = nullptr;

    for(int i = 1; i < Size; i++) {
        if(Arr[i] != 0) {
            nodes[i] = new BNode<DT>();
            nodes[i]->setData(Arr[i]);
        }
    }

    root = nodes[1];

    for(int i = 1; i < Size; i++) {
        if(nodes[i] != nullptr) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if(leftIndex < Size) nodes[i]->setLeftChild(nodes[leftIndex]);
            if(rightIndex < Size) nodes[i]->setRightChild(nodes[rightIndex]);
        }
    }

    delete[] nodes;
}
