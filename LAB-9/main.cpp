//Following is a sample client
#include<iostream>
#include"BinarySearchTree.h"
#include"BinarySearchTree.cpp"
using namespace std;

int main()
{
    //creating an object of binary search tree
    BinarySearchTree<int> *BST=new BinarySearchTree<int>();
    //following insertions should happen successfully as we are inserting unique values
    BST->insert(12);
    BST->insert(4);
    BST->insert(9);
    BST->insert(2);
    BST->insert(14);
    BST->insert(16);
    BST->insert(13);
    //this insertion should fail as 12 already exists in the Binary Search tree
    BST->insert(12);
    //prints data carried by the BST in sorted manner
    BST->printSorted();
    //the first search would be successful and second would fail
    BNode<int>* n = BST->search(12);
    if(n) cout << "value exists" << endl;
    else cout << "value does not exist" << endl;
    BNode<int>* n = BST->search(23);
    if(n) cout << "value exists" << endl;
    else cout << "value does not exist" << endl;
    //prints data carried by the BST in sorted manner
    BST->printSorted();
    //deleting leaf node
    if(BST->Delete(16)) cout << "node carrying 16 deleted successfully" << endl;
    //deleting degree one node
    if(BST->Delete(2)) cout << "node carrying 2 deleted successfully" << endl;
    //deleting degree 2 node
    if(BST->Delete(12)) cout << "node carrying 12 deleted successfully" << endl;
    //prints data carried by the BST in sorted manner
    BST->printSorted();
    //destructor called
    delete BST;
    return 0;
}

/*Exercise 1:
Using the Binary tree node class that you implemented in Lab7, implement part1 to part 6 given in
the Binary Search Tree class definition given as follows (you may name it as BinarySearchTree.h).
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
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
    bool insert(constDType data);
    //part3: Search for data in the binary search tree
    // and return the pointer of the node carrying data
    BNode<DType> * search(const DType data);
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
    BNode<DType> * root;
};
#endif

You may test your code using the following client
//Following is a sample client
#include<iostream>
#include"BinarySearchTree.h"
#include"BinarySearchTree.cpp"
using namespace std;

int main()
{
    //creating an object of binary search tree
    BinarySearchTree<int> *BST=new BinarySearchTree<int>();
    //following insertions should happen successfully as we are inserting unique values
    BST->insert(12);
    BST->insert(4);
    BST->insert(9);
    BST->insert(2);
    BST->insert(14);
    BST->insert(16);
    BST->insert(13);
    //this insertion should fail as 12 already exists in the Binary Search tree
    BST->insert(12);
    //prints data carried by the BST in sorted manner
    BST->printSorted();
    //the first search would be successful and second would fail
    BNode<int>* n = BST->search(12);
    if(n) cout << "value exists" << endl;
    else cout << "value does not exist" << endl;
    BNode<int>* n = BST->search(23);
    if(n) cout << "value exists" << endl;
    else cout << "value does not exist" << endl;
    //prints data carried by the BST in sorted manner
    BST->printSorted();
    //deleting leaf node
    if(BST->Delete(16)) cout << "node carrying 16 deleted successfully" << endl;
    //deleting degree one node
    if(BST->Delete(2)) cout << "node carrying 2 deleted successfully" << endl;
    //deleting degree 2 node
    if(BST->Delete(12)) cout << "node carrying 12 deleted successfully" << endl;
    //prints data carried by the BST in sorted manner
    BST->printSorted();
    //destructor called
    delete BST;
    return 0;
}*/