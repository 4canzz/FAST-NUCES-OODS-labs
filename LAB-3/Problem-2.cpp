#include <iostream>
using namespace std;

template<typename T>
class Node{ 
public:
    // constructor
    Node(T element) : data(element), link(NULL) {}
    //sets the KeyType data in the Node
    void setData(T pVal) { data = pVal; }
    // returns the KeyType data in the Node
    T getData() { return data; }
    // returns the link to the next node
    Node* GetNext() { return link; }
    // sets the link to the next node
    void SetNext(Node *x) { link = x; }
private:
    T data;
    Node *link;
};

template <typename T>
class SCList{
public: // constructor of the Singly Circular Linked List
    SCList() : last(NULL) {}
    /*Inserts the node pNew after the node pBefore
    if the list is empty, it makes pNew the first node of the list*/
    void Insert(Node<T>* pBefore, Node<T>* pNew) {
        if (!pNew) return;
        if (!last) { 
            last = pNew;
            pNew->SetNext(pNew);
            return;
        }
        if(pBefore == last) {
            pNew->SetNext(last->GetNext());
            last->SetNext(pNew);
            last = pNew;
            return;
        }
        pNew->SetNext(pBefore->GetNext());
        pBefore->SetNext(pNew);
    }
    //Deletes the node pToBeDeleted
    void Delete(Node<T>* pToBeDeleted) {
        if (!pToBeDeleted || !last) return;
        if (last == pToBeDeleted && last->GetNext() == last) {
            delete pToBeDeleted;
            last = NULL;
            return;
        }
        Node<T>* prev = last;
        while(prev->GetNext() != last && prev->GetNext() != pToBeDeleted) { 
            prev = prev->GetNext();  
        }
        if(prev->GetNext() == pToBeDeleted) {
            prev -> SetNext(pToBeDeleted->GetNext());
            if (last == pToBeDeleted) last = prev;
            delete pToBeDeleted;
        }
    }
    //prints the contents of the list
    void printList() {
        if(last) {
            Node<T>* temp = last->GetNext();  // start from first node
            do {
                cout << temp->getData() << " ";
                temp = temp->GetNext();
            } while (temp != last->GetNext());
            cout << endl;
        }
    }
    ~SCList() {
        if(!last) return;
        Node<T>* temp = last->GetNext();
        Node<T>* nextNode;
        while (temp != last) {
            nextNode = temp->GetNext();
            delete temp;
            temp = nextNode;
        }
        delete last;
        last = NULL;
    }
private:
    Node<T> *last ;
};

int main() {
    Node<int> *a, *b, *c, *d, *e; 
    a = new Node<int>(1); 
    b = new Node<int>(2); 
    c = new Node<int>(3); 
    d = new Node<int>(4); 
    e = new Node<int>(5); 
    SCList<int> list; 
    list.Insert(NULL,a);  
    list.Insert(a,b);  
    list.Insert(b,c);  
    list.Insert(c,d); 
    list.Insert(d,e);     
    cout << "printing the list: " << endl;
    list.printList(); 
    list.Delete(c);
    cout << "printing the list after deleting Node c (3) " << endl;
    list.printList();
    return 0;
}


/*Exercise 1: Implement a circular singly linked list. 
Implement all the methods given in the following class definition for circular singly linked list. 
Your code should work for the main function that follows. 

template<typename T>  
class Node 
{ public: 
    // constructor  
    Node(T element); 
    //sets the KeyType data in the Node  
    void setData(T pVal); 
    // returns the KeyType data in the Node  
    T getData(); 
    // returns the link to the next node  
    Node* GetNext(); 
    // sets the link to the next node  
    void SetNext(Node *x); 
private: 
    T data; 
    Node *link; 
}; 

template <typename T>  
class SCList 
{public: // constructor of the Singly Circular Linked List  
    SCList(); 
    //Inserts the node pNew after the node pBefore 
    //if the list is empty, it makes pNew the first node of the list 
    void Insert(Node<T>* pBefore, Node<T>* pNew); 
    //Deletes the node pToBeDeleted 
    void Delete(Node<T>* pToBeDeleted); 
    //prints the contents of the list  
    void printList(); 
private: 
    Node<T> *last ; 
};
*/
