#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Employee {
    int id;
    string firstName, lastName, department;
    double salary;

    friend ostream& operator<<(ostream& os, const Employee& e) {
        os << e.id << " " << e.firstName << " " << e.lastName << " " << e.department << " " << e.salary;
        return os;
    }
};

template <typename T>
class BNode {
private:
    T data;
    BNode<T>* left;
    BNode<T>* right;
public:
    BNode();
    BNode(T val);
    void setRight(BNode<T>* x);
    BNode<T>* getRight() const;
    void setLeft(BNode<T>* x);
    BNode<T>* getLeft() const;
    void setData(T val);
    T getData() const;
};

class BST {
private:
    BNode<Employee>* root;
    BNode<Employee>* insert(BNode<Employee>* node, Employee e, bool &success);
    BNode<Employee>* search(BNode<Employee>* node, int id);
    void inorder(BNode<Employee>* node);
    void reverseInorder(BNode<Employee>* node);
    void saveToFile(ofstream &out, BNode<Employee>* node);
public:
    BST();
    void saveToFile(const string &filename);
    bool insert(Employee e);
    bool remove(int id);
    bool search(int id);
    void displayAscending();
    void displayDescending();
};

