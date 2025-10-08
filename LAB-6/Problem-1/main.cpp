#include "queue.h"
#include "queue.cpp"  
#include <iostream>  
using namespace std;
int main()
{
	Queue<int> *q = new Queue<int>();
	if (q->IsEmpty())
		cout << "Queue is currently empty" << endl;
	q->Put(1);
	q->Put(2);
	q->Put(3);
	while (!q->IsEmpty()) {
		int value = q->Get();
		cout << value << endl;
	}
	return 0;
}

/*Exercise 1: 
Implement the following Queue definition using singly linked list (you may use the Singly Linked List 
that you already developed in Lab 3), you may also add any functions needed in the Singly Linked List
definition given in Lab 3. Your implementation should work for the main function provided. 

#ifndef QUEUE_H  
#define QUEUE_H  
template<class DT> 
class Queue 
{ 
private: 
	//include private variables according to the underlying data structure  public: 
	//contructor  
public:
	Queue(); 
	//puts element at the rear end of the Queue if it is not full. Must be O(1)  
	void Put(DT element); 
	//if queue not empty then delete the element at front of the Queue. Must be O(1)  
	DT Get(); 
	//return true if the Queue is empty and false if it is not  
	bool IsEmpty(); 
	//return true if the Queue is full and false if it is not  
	bool IsFull(); 
}; 
#endif

#include"Queue.h"  
#include"Queue.cpp"  
#include<iostream>  
using namespace std; 
int main() 
{ 
	Queue<int> *q = new Queue<int>(); 
	if(q->IsEmpty()) 
		cout<<"Queue is currently empty"<<endl; 
	q->Put(1); 
	q->Put(2); 
	q->Put(3); 
	while (!q->IsEmpty()) 
	{ 
		int value=q->Get();  
		cout<<value<<endl; 
	} 
	return 0; 
}
*/
