#include"Stack.h"
#include"Stack.cpp"
#include<iostream>
using namespace std;
int main()
{
    Stack<int> *st =new Stack<int>();
    if(st->IsEmpty())
        cout<<"Stack is currently empty"<<endl;
    st->Push(1);
    st->Push(2);
    st->Push(3);
    while (!st->IsEmpty())
    {
        int value=st->Pop();
        cout<<value<<endl;
    }
    return 0;
}

/*Exercise 1: Implement Stack using singly linked list. 
Implement all the methods given in the following class definition for Stack using a singly linked
list  as the underlying data structure. Your implementation should work for the main function  
that follows. 
#ifndef STACK_H  
#define STACK_H 
template<class KeyType>  
class Stack 
{ //  
public: 
    // constructor , creates an empty stack  
    Stack(); 
    // returns true if Stack is full, otherwise return false  
    bool IsFull(); 
    //If number of elements in the Stack is zero return true,  
    otherwise return false 
    bool IsEmpty(); 
    // If Stack is not full, insert item into the Stack. Must be an  O(1) operation 
    void Push(const KeyType item); 
    // If Stack is empty return 0 or NULL; 
    // else return appropriate item from the Stack. Must be an O(1)  operation 
    KeyType Pop(); 
private: 
    SList <KeyType>* list;  
    Node<KeyType>* top; 
}; 
#endif

#include"Stack.h"  
#include"Stack.cpp"  
#include<iostream>  
using namespace std; 
int main() 
{ 
    Stack<int> *st =new Stack<int>(); 
    if(st->IsEmpty()) 
        cout<<"Stack is currently empty"<<endl; 
    st->Push(1); 
    st->Push(2); 
    st->Push(3); 
    while (!st->IsEmpty()) 
    { 
        int value=st->Pop();  
        cout<<value<<endl; 
    } 
    return 0; 
}
*/