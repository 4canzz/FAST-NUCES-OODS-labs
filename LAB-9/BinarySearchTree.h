#pragma once
#include <iostream>
#include"BNode.h"
using namespace std;

template<class DType>
class BinarySearchTree
{
public:
    //part1: constructor
    BinarySearchTree();
    //part2: Create and insert a BNode carrying data
    //in the binary search tree. It return true if
    //insertion takes place successfully and false otherwise
    bool insert(const DType data);
    //part3: Search for data in the binary search tree
    // and return the pointer of the node carrying data
    BNode<DType>* search(const DType data);
    //part4: prints all the data present in the tree
    //sorted in ascending order
    void printSorted();
    //part5: delete the BNode carrying data from the
    //binary search tree. It return true if
    //deletion takes place successfully and false otherwise
    bool Delete(const DType data);
    //part6: destructor, delete all nodes
    ~BinarySearchTree();
private:
    void inorder(BNode<DType>* node);
    void destroyTree(BNode<DType>* node);
    BNode<DType> * root;
};