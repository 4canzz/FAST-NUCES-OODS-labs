//Following is a sample client
#include<iostream>
#include"BinaryTree.h"
#include"BinaryTree.cpp"

using namespace std;
int main()
{
    //creating an object of binary tree
    BinaryTree<int> *BT=new BinaryTree<int>();
    //array to pass, 0 means no node exists
    int Arr[15]={0,1,2,3,4,5,6,7,8,9,10,0,12,13,14};
    BT->BuildTree(Arr,15); //building the tree from the array
    cout<<"***************************************************"<<endl;
    return 0;
}

/*Exercise 1: 
Implement the Binary tree node class andpart1 and part 2 of the Binary tree class
definition given in the header file (name it as BinaryTree.h) below:
#ifndef BINARYTREE_H
#define BINARYTREE_H
template<class DT>
class BNode
{
public:
    BNode();
    void setLeftChild(BNode<DT>* n);
    BNode<DT>* getLeftChild();
    void setRightChild(BNode<DT>* n);
    BNode<DT>* getRightChild();
    void setData(DT pdate);
    DT getData();
private:
    DT data;
    BNode* leftchild;
    BNode* rightchild;
};
template<class DT>
class BinaryTree
{
public:
    //part1: constructor
    BinaryTree ();
    //part 2:
    //Build the binary tree from the data given in the array.
    //If a node doesn't exist the array element is 0
    void BuildTree(DT *Arr, int Size);
    //part3: post order traversal (recursive)
    //you may call any other function with parameters which might be needed
    void PostOrder();
    //part4: pre order traversal (recursive)
    // you may call any other function with parameters which might be needed
    void PreOrder();
    //part5: in order traversal (recursive)
    // you may call any other function with parameters which might be needed
    void InOrder();
    // part6: prints the height of the binary tree, you may pass any parameters needed
    int calculateDepth();
private:
    // you may add any other private members which might be needed by recursive functions
    BNode<DT>* root;
};

You may test your code using the client program given below:
//Following is a sample client
#include<iostream>
#include"BinaryTree.h"
#include"BinaryTree.cpp"
using namespace std;
int main()
{
    //creating an object of binary tree
    BinaryTree<int> *BT=new BinaryTree<int>();
    //array to pass, 0 means no node exists
    int Arr[15]={0,1,2,3,4,5,6,7,8,9,10,0,12,13,14};
    BT->BuildTree(Arr,15); //building the tree from the array
    cout<<"***************************************************"<<endl;
    return 0;
}
#endif*/