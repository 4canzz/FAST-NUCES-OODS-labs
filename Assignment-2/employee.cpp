#include "employee.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
BNode<T>::BNode() : left(NULL), right(NULL), data(T()) {}

template <typename T>
BNode<T>::BNode(T val) : left(NULL), right(NULL), data(val) {}

template <typename T>
void BNode<T>::setRight(BNode<T>* x) { right = x; }

template <typename T>
BNode<T>* BNode<T>::getRight() const { return right; }

template <typename T>
void BNode<T>::setLeft(BNode<T>* x) { left = x; }

template <typename T>
BNode<T>* BNode<T>::getLeft() const { return left; }

template <typename T>
void BNode<T>::setData(T val) { data = val; }

template <typename T>
T BNode<T>::getData() const { return data; }

//--BST private (helper) functions
void BST::saveToFile(ofstream &out, BNode<Employee>* node) {
    if (!node) return;
    saveToFile(out, node->getLeft());
    out << node->getData() << endl;
    saveToFile(out, node->getRight());
}

//insert helper (recrusive)
BNode<Employee>* BST::insert(BNode<Employee>* node, Employee e, bool &success) {
    if (!node) {
        success = true;
        return new BNode<Employee>(e);
    }
    if (e.id < node->getData().id) node->setLeft(insert(node->getLeft(), e, success));
    else if (e.id > node->getData().id) node->setRight(insert(node->getRight(), e, success));
    else {
        cout << "Duplicate ID " << e.id << " not allowed." << endl;
        success = false;
    }
    return node;
}
// search helper (recursive)
BNode<Employee>* BST::search(BNode<Employee>* node, int id) {
    if (!node) return NULL;
    if (id == node->getData().id) return node;
    else if (id < node->getData().id) return search(node->getLeft(), id);
    else return search(node->getRight(), id);
}
// display ascending helper (ascending in BST = inorder)
void BST::inorder(BNode<Employee>* node) {
    if (!node) return;
    inorder(node->getLeft());
    cout << node->getData() << endl;
    inorder(node->getRight());
}
// display descending helper (descending in BST = reverse inorder)
void BST::reverseInorder(BNode<Employee>* node) {
    if (!node) return;
    reverseInorder(node->getRight());
    cout << node->getData() << endl;
    reverseInorder(node->getLeft());
}

//--BST: public functions
BST::BST() : root(NULL) {}

void BST::saveToFile(const string &filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "Error opening file for writing.\n";
        return;
    }
    saveToFile(out, root);
    out.close();
}

bool BST::insert(Employee e) {
    bool success = false;
    root = insert(root, e, success);
    return success;
}

bool BST::remove(int id) {
    BNode<Employee>* curr = root;
    BNode<Employee>* parent = NULL;

    while (curr && curr->getData().id != id) {
        parent = curr;
        if (id < curr->getData().id) curr = curr->getLeft();
        else curr = curr->getRight();
    }

    if (!curr) {
        cout << "Employee not found.\n";
        return false;
    }

    if (!curr->getLeft() && !curr->getRight()) {
        if (curr != root) {
            if (parent->getLeft() == curr) parent->setLeft(NULL);
            else parent->setRight(NULL);
        } else root = NULL;
        delete curr;
    }

    else if (!curr->getLeft() || !curr->getRight() ) {
        BNode<Employee>* child;
        if (curr->getLeft()) child = curr->getLeft();
        else child = curr->getRight();

        if (curr != root) {
            if (curr == parent->getLeft()) parent->setLeft(child);
            else parent->setRight(child);
        } else root = child;
        delete curr;
    }

    else {
        BNode<Employee>* successorParent = curr;
        BNode<Employee>* successor = curr->getRight();

        while (successor->getLeft()) {
            successorParent = successor;
            successor = successor->getLeft();
        }

        curr->setData(successor->getData());

        if (successorParent->getLeft() == successor) successorParent->setLeft(successor->getRight());
        else successorParent->setRight(successor->getRight());

        delete successor;
    }

    return true;
}

bool BST::search(int id) {
    BNode<Employee>* result = search(root, id);
    if (!result) {
        cout << "Employee not found.\n";
        return false;
    } else {
        cout << result->getData() << endl;
        return true;
    }
}

void BST::displayAscending() { inorder(root); }

void BST::displayDescending() { reverseInorder(root); }


