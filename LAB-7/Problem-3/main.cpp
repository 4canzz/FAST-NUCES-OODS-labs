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
    cout<<"Height of the Binary Tree is: "<<endl;
    BT-> calculateDepth();
    cout<<"***************************************************"<<endl;
    return 0;
}

/*Exercise 3:
Implement part6 of the header file given in exercise 1 that should calculate and print the height of
the Binary tree recursively. Please test it using the following client

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
    cout<<"Height of the Binary Tree is: "<<endl;
    BT-> calculateDepth();
    cout<<"***************************************************"<<endl;
    return 0;
}*/