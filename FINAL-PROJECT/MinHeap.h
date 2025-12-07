#pragma once
#include "List.h"
using namespace std;

struct HeapNode {
    int vertex;
    int dist;
};

class MinHeap {
private:
    HeapNode* arr;
    int size;
    int capacity;

    void swap(HeapNode &a, HeapNode &b) {
        HeapNode temp = a;
        a = b;
        b = temp;
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i != 0 && arr[parent(i)].dist > arr[i].dist) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int l = left(i), r = right(i);
        int smallest = i;

        if (l < size && arr[l].dist < arr[smallest].dist) smallest = l;
        if (r < size && arr[r].dist < arr[smallest].dist) smallest = r;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap(int cap = 500) {
        capacity = cap;
        size = 0;
        arr = new HeapNode[capacity];
    }

    bool isEmpty() { return size == 0; }

    void push(int vertex, int dist) {
        if (size == capacity) return;

        arr[size].vertex = vertex;
        arr[size].dist = dist;

        heapifyUp(size);
        size++;
    }

    HeapNode pop() {
        HeapNode root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapifyDown(0);
        return root;
    }

    ~MinHeap() {
        delete[] arr;
    }
};