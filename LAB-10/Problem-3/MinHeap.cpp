#include <iostream>
#include "MinHeap.h"
using namespace std;

template <class DT>
MinHeap<DT>::MinHeap(int maxsize) : last(-1), maxSize(maxsize), arr(new DT[maxsize]) {}

template <class DT>
bool MinHeap<DT>::insert(const DT data) {
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

template <class DT>
DT MinHeap<DT>::Delete() {
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

template <class DT>
void MinHeap<DT>::printContents() {
    if (last == -1) {
        cout << "heap empty" << endl;
        return;
    }
    for (int i = 0; i <= last; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class DT>
bool MinHeap<DT>::isEmpty() { return last == -1; }

template <class DT>
MinHeap<DT>::~MinHeap() { delete[] arr; };