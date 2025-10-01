#ifndef STACK_H
#define STACK_H

using namespace std;
template<typename T>
class Node;
template<typename T>
class SList;

template<class KeyType>
class Stack 
{
public:
    // constructor , creates an empty stack
    Stack();
    // returns true if Stack is full, otherwise return false
    bool IsFull();
    //If number of elements in the Stack is zero return true, otherwise return false
    bool IsEmpty();
    // If Stack is not full, insert item into the Stack. Must be an O(1) operation
    void Push(const KeyType item);
    // If Stack is empty return 0 or NULL;
    // else return appropriate item from the Stack. Must be an O(1) operation
    KeyType Pop();
private:
    SList <KeyType>* list;
    Node<KeyType>* top;
};
#endif