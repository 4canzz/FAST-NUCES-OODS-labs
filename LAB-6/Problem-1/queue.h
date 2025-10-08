#ifndef QUEUE_H  
#define QUEUE_H  
using namespace std;

template<typename DT>
class Node;

template<class DT>
class Queue
{
private:
	//include private variables according to the underlying data structure  public: 
	Node<DT>* front;
	Node<DT>* rear;
public:
	//contructor  
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
