#include <iostream>
#include <algorithm>
using namespace std;

template <class DT>
class MaxHeap
{
private:
	DT *arr;
	int last;
	int maxSize;
public:
	//part1: constructor initializes array of size maxsize
	MaxHeap(int maxsize) : last(-1), maxSize(maxsize), arr(new DT[maxsize]) {}
	//part2: Inserts data into its appropriate position
	//within the Heap
	bool insert(const DT data) {
		if (last == maxSize - 1) return false;
		arr[++last] = data;
		int child = last;
		int parent = (child - 1) / 2;
		while (child > 0) {
			if (arr[child] > arr[parent]) {
				std::swap(arr[parent], arr[child]);
				child = parent;
			} else break;
		}
		return true;
	}
	//part3: removes the element present in the the root
	//of the Heap and readjusts it to form MaxHeap again
	DT Delete() {
		if (last == -1) return DT();
		DT del = arr[0];
		if (last == 0) {
			last--;
			return del;
		}

		arr[0] = arr[last--];
		int i = 0;

		while (true) {
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			int largest = i;

			if (left <= last && arr[left] > arr[largest]) largest = left;
			if (right <= last && arr[right] > arr[largest]) largest = right;
			if (largest != i) {
				std::swap(arr[i], arr[largest]);
				i = largest;
			}
			else break;
		}
		return del;
	}
	//part4: prints all the data present in the Heap
	//use the appropriate traversal
	void printContents() {
		if (last == -1) {
			cout << "heap empty" << endl; 
			return;
		}
		for (int i = 0; i <= last; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	//part5: destructor, deletes the MaxHeap
	~MaxHeap() { delete[] arr; };
};

int main()
{
	MaxHeap<int> *mxHeap; //creating an object of maxheap
	mxHeap = new MaxHeap<int>(40);
	//insert following data in the MaxHeap
	mxHeap->insert(12);
	mxHeap->insert(43);
	mxHeap->insert(9);
	mxHeap->insert(2);
	mxHeap->insert(14);
	mxHeap->insert(16);
	mxHeap->insert(13);
	mxHeap->insert(12);
	mxHeap->printContents();
	//Carry out 2 deletions from the MaxHeap
	int output;
	output = mxHeap->Delete();

	cout << "output of first deletion is " << output << endl;
	mxHeap->printContents();

	output = mxHeap->Delete();

	cout << "output of first deletion is " << output << endl;
	mxHeap->printContents();
	return 0;
}

/*Exercise 1: 
Implement the MaxHeap class definition given as follows (you may name it as MaxHeap.h).
#ifndef MAX_HEAP_H
#defineMAX_HEAP_H
Using namespace std;

template<class DT>
classMaxHeap
{
public:
    //part1: constructor initializes array of size maxsize
    MaxHeap(int maxsize);
    //part2: Inserts data into its appropriate position
    //within the Heap
    bool insert(constDT data);
    //part3: removes the element present in the the root
    //of the Heap and readjusts it to form MaxHeap again
    DTdelete();
    //part4: prints all the data present in the Heap
    //use the appropriate traversal
    void printContents();
    //part5: destructor, deletes the MaxHeap
    ~MaxHeap();
private:
    DT *arr;
};
#endif

You may test your code using the following client
//Following is a sample client
#include<iostream>
#include"MaxHeap.h"
using namespace std;
int main()
{
    MaxHeap<int> *mxHeap; //creating an object of maxheap
    mxHeap=new MaxHeap<int>(40);
    //insert following data in the MaxHeap
    mxHeap->insert(12);
    mxHeap ->insert(43);
    mxHeap ->insert(9);
    mxHeap ->insert(2);
    mxHeap ->insert(14);
    mxHeap ->insert(16);
    mxHeap ->insert(13);
    mxHeap ->insert(12);
    mxHeap->printContents();
    //Carry out 2 deletions from the MaxHeap
    int output;
    output=mxHeap->delete();

    cout << "output of first deletion is " << output << endl;

    mxHeap->printContents();
    output=mxHeap->delete();

    cout << "output of second deletion is " << output << endl;

    mxHeap->printContents();
    return 0;
}*/