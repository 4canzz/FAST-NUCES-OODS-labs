#include <iostream>
#include<Windows.h>
using namespace std;

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;
public:
    Node(T val) : data(val), next(NULL) {}
    void SetData(T val) { data = val; }
    T& getData() { return data; }
    Node<T>* GetNext() { return next; }
    void SetNext(Node<T>* x) { next = x; }
};

template <typename T>
class List {
private:
    Node<T>* head;
public:
    List() { head = NULL; }
    void insert(T val) {
        Node<T>* pnew = new Node<T>(val);
        if (!head) head = pnew;
        else {
            pnew->SetNext(head);
            head = pnew;
        }
    }
    bool search(T val) {
        Node<T>* temp = head;
        while (temp != NULL) {
            if (temp->getData() == val) return true;
            temp = temp->GetNext();
        }
        return false;
    }
    void printList() {
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->getData() << " ";
            temp = temp->GetNext();
        }
    }
};

template<class DT>
class Hashtable
{
public:
    Hashtable(int hashsize) : size(hashsize), arr(new List<DT>* [size]) {
        for (int i = 0; i < size; i++) arr[i] = new List<DT>();
    }
    bool store(DT key) {
        int index = hash(key);
        if (!arr[index]->search(key)) {
            arr[index]->insert(key);
            cout << "stored at index " << index << endl;
            return true;
        }
        cout << "key already exists at index " << index << endl;
        return false;
    }

    bool search(DT key) {
        int index = hash(key);
        if (arr[index]->search(key)) {
            cout << "found at index " << index << endl;
            return true;
        }
        return false;
    }

    void printdata() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            arr[i]->printList();
        }
    }
private:
    int size;
    List<DT>** arr;
    int hash(int key) { return key % size; }
};

int main()
{
    int num_of_identifiers;
    cout << "Enter maximum number of keys that need to be stored in the hashtable: ";
    cin >> num_of_identifiers;
    int size_hashtable;
    cout << "Enter size of hashtable needed to store these many identifiers (hint: use prime number): ";
    cin >> size_hashtable;
    //create a hashtable of this size
    Hashtable<int>* ht = new Hashtable<int>(size_hashtable);
    for (int i = 0; i < num_of_identifiers; i++)
    {
        int key = rand() % 1000;
        bool was_stored = ht->store(key);
        if (!was_stored) cout << key << " could not be stored as it already exists or table is full" << endl;
    }
    ht->printdata();
    int find_key;
    cout << "Enter the key to search for " << endl;
    cin >> find_key;
    DWORD start, end;//measure time
    start = GetTickCount();
    bool found = ht->search(find_key);
    end = GetTickCount();
    double cpu_time_used = end - start;
    if (found) cout << "it was found in " << cpu_time_used << " milliseconds" << endl;
    else cout << "not found in " << cpu_time_used << " milliseconds" << endl;
    return 0;
}

/*Exercise 2: Generate n random numbers (using rand%1000) and store them is a hashtable
(use an array of singly linked lists). The value of n should be asked from the user at runtime
and decide the size of array to use accordingly (hint: big prime number).  
Please use the modulus function (%) as the hashfunction and Chaining as the Overflow handling
technique. You may use the singly linked list code implemented in lab 3 to manage the chain held
at each index of the hashtable.
You have to implement the following ADT of Hashtable:  

#ifndef HSH_H  
#define HSH_H  
#include"SList.h" 
template<class DT>  
class Hashtable  
{ 
public:  
    Hashtable(int size);  
    bool store(DT key);  
    bool search(DT key);  
    void printdata();  
private:  
    int size;  
    List<DT>** arr;  
};  
#endif
*/  
