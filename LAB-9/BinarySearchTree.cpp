#pragma once
#include <iostream>
#include "BNode.h"
#include "BinarySearchTree.h"
using namespace std;

template<class DType>
BinarySearchTree<DType>::BinarySearchTree() : root(NULL) {}

template<class DType>
bool BinarySearchTree<DType>::insert(const DType data) {
    BNode<DType>* pnew = new BNode<DType>();
    pnew->setData(data);

    if (root == NULL) {
        root = pnew;
        return true;
    }

    BNode<DType>* curr = root;
    BNode<DType>* parent = NULL;

    while (curr) {
        parent = curr;

        if (data < curr->getData()) curr = curr->getLeftChild();
        else if (data > curr->getData()) curr = curr->getRightChild();
        else return false;
    }

    if (data < parent->getData()) parent->setLeftChild(pnew);
    else parent->setRightChild(pnew);

    return true;
}

template<class DType>
BNode<DType>* BinarySearchTree<DType>::search(const DType data) {
    BNode<DType>* curr = root;

    while (curr) {
        if (curr->getData() == data) return curr;

        if (data < curr->getData()) curr = curr->getLeftChild();
        else curr = curr->getRightChild();
    }
    return nullptr;
}

template<class DType>
void BinarySearchTree<DType>::inorder(BNode<DType>* node)
{
    if (node == nullptr) return;
    inorder(node->getLeftChild());
    cout << node->getData() << " ";
    inorder(node->getRightChild());
}

template<class DType>
void BinarySearchTree<DType>::printSorted() {
    inorder(root);
    cout << endl;
}

template<class DType>
bool BinarySearchTree<DType>::Delete(const DType data)
{
    BNode<DType>* curr = root;
    BNode<DType>* parent = NULL;
    bool isLeftChild = false; 

    while (curr&& curr->getData() != data) {
        parent = curr;
        if (data < curr->getData()) {
            isLeftChild = true;
            curr = curr->getLeftChild();
        } else {
            isLeftChild = false;
            curr = curr->getRightChild();
        }
    }

    if (!curr) return false;

    if (!curr->getLeftChild() && !curr->getRightChild()) {
        if (curr == root) root = NULL;  
        else if (isLeftChild) parent->setLeftChild(nullptr);
        else parent->setRightChild(nullptr);
        delete curr;
        return true;
    }

    if (!curr->getLeftChild()|| !curr->getRightChild()) {
        BNode<DType>* child = (curr->getLeftChild() != nullptr)
            ? curr->getLeftChild()
            : curr->getRightChild();

        if (curr == root) root = child;
        else if (isLeftChild) parent->setLeftChild(child);
        else parent->setRightChild(child);
        delete curr;
        return true;
    }

    BNode<DType>* successorParent = curr;
    BNode<DType>* successor = curr->getRightChild();
    while (successor->getLeftChild()) {
        successorParent = successor;
        successor = successor->getLeftChild();
    }

    curr->setData(successor->getData());

    if (successorParent->getLeftChild() == successor) successorParent->setLeftChild(successor->getRightChild());
    else successorParent->setRightChild(successor->getRightChild());

    delete successor;
    return true;
}

template<class DType>
void BinarySearchTree<DType>::destroyTree(BNode<DType>* node) {
    if (node == nullptr) return;
    destroyTree(node->getLeftChild());
    destroyTree(node->getRightChild());
    delete node;
}

template<class DType>
BinarySearchTree<DType>::~BinarySearchTree() { destroyTree(root); }