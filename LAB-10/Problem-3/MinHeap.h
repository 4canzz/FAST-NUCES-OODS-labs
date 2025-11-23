#pragma once
#include <iostream>
using namespace std;

template <class DT>
class MinHeap
{
private:
	DT *arr;
	int last;
	int maxSize;
public:
	//part1: constructor initializes array of size maxsize
	MinHeap(int maxsize);
	//part2: Inserts data into its appropriate position
	//within the Heap
	bool insert(const DT data);
	//part3: removes the element present in the the root
	//of the Heap and readjusts it to form MaxHeap again
	DT Delete();
	//part4: prints all the data present in the Heap
	//use the appropriate traversal
	void printContents();
    bool isEmpty();
	//part5: destructor, deletes the MaxHeap
	~MinHeap();
};