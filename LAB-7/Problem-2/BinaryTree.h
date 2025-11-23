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
        //int calculateDepth();
private:
    // you may add any other private members which might be needed by recursive functions
    BNode<DT>* root;
    //recrusive helpers
   void PostOrder(BNode<DT>* node);
   void PreOrder(BNode<DT>* node);
   void InOrder(BNode<DT>* node);
};
#endif