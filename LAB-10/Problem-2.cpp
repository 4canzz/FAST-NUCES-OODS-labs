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
	MinHeap(int maxsize) : last(-1), maxSize(maxsize), arr(new DT[maxsize]) {}
	//part2: Inserts data into its appropriate position
	//within the Heap
	bool insert(const DT data) {
		if (last == maxSize - 1) return false;
		arr[++last] = data;
		int child = last;
		int parent = (child - 1) / 2;
		while (child > 0) {
			if (arr[child] < arr[parent]) {
				std::swap(arr[parent], arr[child]);
				child = parent;
			}
			else break;
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
			int smallest = i;

			if (left <= last && arr[left] < arr[smallest]) smallest = left;
			if (right <= last && arr[right] < arr[smallest]) smallest = right;
			if (smallest != i) {
				std::swap(arr[i], arr[smallest]);
				i = smallest;
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
	~MinHeap() { delete[] arr; };
};

int main()
{
	MinHeap<int> *mnHeap; //creating an object of maxheap
	mnHeap = new MinHeap<int>(40);
	//insert following data in the MaxHeap
	mnHeap->insert(12);
	mnHeap->insert(43);
	mnHeap->insert(9);
	mnHeap->insert(2);
	mnHeap->insert(14);
	mnHeap->insert(16);
	mnHeap->insert(13);
	mnHeap->insert(12);
	mnHeap->printContents();
	//Carry out 2 deletions from the MaxHeap
	int output;
	output = mnHeap->Delete();

	cout << "output of first deletion is " << output << endl;
	mnHeap->printContents();

	output = mnHeap->Delete();

	cout << "output of first deletion is " << output << endl;
	mnHeap->printContents();
	return 0;
}

/*Exercise 2: Alter the definition as well as implementation of the MaxHeap done in Exercise1 to
create a MinHeap carrying integer data. You may test your code using the following client
//Following is a sample client
#include<iostream>
#include"MinHeap.h"
using namespace std;
int main()
{
    MinHeap<int> *mnHeap; //creating an object of MinHeap
    mnHeap=new MinHeap<int>(40);
    //insert following data in the MinHeap
    mnHeap->insert(12);
    mnHeap ->insert(43);
    mnHeap ->insert(9);
    mnHeap ->insert(2);
    mnHeap ->insert(14);
    mnHeap ->insert(16);
    mnHeap ->insert(13);
    mnHeap ->insert(12);
    mnHeap->printContents();
    //Carry out 2 deletions from the MinHeap
    int output;
    output=mnHeap->delete();

    cout << "output of first deletion is " << output << endl;

    mnHeap->printContents();
    output=mnHeap->delete();

    cout << "output of second deletion is " << output << endl;

    mnHeap->printContents();
    return 0;
}*/
