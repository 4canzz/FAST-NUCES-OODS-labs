#include <iostream>
#include<Windows.h>
using namespace std;

template<class DT>
class Hashtable
{
public:
    Hashtable(int sizehash) : size(sizehash), arr(new DT[sizehash]) {
        for(int i = 0; i < size; i++)
            arr[i] = -1;
    } 
     bool store(DT key) {
        int index = hash(key);
        int j = index;
        do {
            if (arr[j] == -1) {   
                arr[j] = key;
                cout << "stored at " << j << endl;
                return true;
            } else if (arr[j] == key) { 
                cout << "key already exists at " << j << endl;
                return false;
            }

            j = hash(j+1);
        } while (j != index);

        cout << "table full, cannot store " << key << endl;
        return false; 
    }
    bool search(DT key) {
        int index = hash(key);
        int j = index;
        while(arr[j]!= key) {
            j = hash(j+1);
            if(j == index || arr[j]== -1) return false;
        }
        cout << "found at " << j <<endl;
        return true;
    }
    bool Delete(DT key) {
        int index = hash(key);
        int j = index;

        do {
            if (arr[j] == key) {
                arr[j] = -1; 
                cout << "deleted key at " << j << endl;
                return true;
            }

            if (arr[j] == -1)  return false;

            j = hash(j+1);
        } while (j != index);

        return false;
    }
private:
    int size;
    DT* arr;
    int hash(DT key) { return key % size; }
};

int main()
{
    int num_of_identifiers;
    cout<<"Enter maximum number of keys that need to be stored in the hashtable: ";
    cin>>num_of_identifiers;
    int size_hashtable;
    cout<<"Enter size of hashtable needed to store these many identifiers (hint: use prime number): ";
    cin>>size_hashtable;
    //create a hashtable of this size
    Hashtable<int>* ht=new Hashtable<int>(size_hashtable);
    for (int i=0; i<num_of_identifiers; i++)
    {
        int key=rand()%1000;
        bool was_stored = ht->store(key);
        if(!was_stored)
        cout<<key<<" could not be stored as it already exists or table is full"<<endl;
    }
    int find_key;
    cout<<"Enter the key to search for "<<endl;
    cin>>find_key;
    DWORD start, end;//measure time
    start= GetTickCount();
    bool found= ht->search(find_key);
    end= GetTickCount();
    double cpu_time_used = end - start;
    if(found)
    cout<<"it was found in "<<cpu_time_used<<" milliseconds"<<endl;
    else
    cout<<"not found in "<<cpu_time_used<<" milliseconds"<<endl;
    return 0;
}

/*Exercise 1: 
Generate n random numbers (using rand%1000) and store them is a hash table. The value
of n should be asked from the user at runtime and decide the size of array to use accordingly
(hint: big prime number).
Please use the modulus function (%) as the hash function and Open addressing (or linear probing)
as the Overflow handling technique. You have to implement the following ADT of Hashtable:

Once all the n numbers have been stored in this hashtable, search for a particular number entered
by the user and note the time it takes to carry out the search. If the number is found (or not) 
let the user know accordingly.

#ifndef HSH_H
#define HSH_H
template<class DT>
class Hashtable
{
public:
    Hashtable(int sizehash);
    bool store(DT key);
    bool search(DT key);
    bool delete(DT key);
private:
    int size;
    DT* arr;
};*/