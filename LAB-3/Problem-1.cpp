#include <iostream>
using namespace std;

template <typename T>  
class Node 
{ 
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
class List { 
public: 
	// constructor of the Singly Linked List  
	List() : first(NULL) {}
	//Inserts the node pNew after the node pBefore 
	// if the list is empty, it makes pNew the first node of the list  
	void Insert(Node<T>* pBefore, Node<T>* pNew) {
		if (first == NULL) {  
			first = pNew; 
			pNew->SetNext(NULL);
		} else {
			pNew -> SetNext(pBefore -> GetNext());
			pBefore -> SetNext(pNew);
		}
	}
	//Deletes the node pToBeDeleted  
	void Delete(Node<T>* pToBeDeleted) {
		if (first == NULL) return;
		if (pToBeDeleted == first) { 
			first = first -> GetNext();
			delete pToBeDeleted;
			return;
		}
		Node<T>* prev = first;
		while(prev->GetNext() != NULL && prev->GetNext() != pToBeDeleted) { 
		    prev = prev->GetNext();  
		}
		if(prev->GetNext() == pToBeDeleted) {
			prev -> SetNext(pToBeDeleted->GetNext());
			delete pToBeDeleted;
		}
	}
	//prints the contents of the list  
	void printList() {
		Node<T>* temp = first;
		while (temp != NULL) {
			cout << temp-> getData() << " "; 
			temp = temp->GetNext();  
		}
		cout << endl;
	}
	//ADD ONE OR TWO MEMBER FUNCTION(s) DIFFERENT FOR EACH LAB SECTION
	void Search(T value) {
		if (first == NULL) return;
		Node<T>* temp = first;
		while (temp != NULL) {
			if (temp->getData() == value) {
				cout << "FOUND!" << endl;
				return;
			}
			temp = temp->GetNext(); 
		}
		cout << "NOT FOUND" << endl;
	}
private:
	Node<T> *first ;
};

int main() 
{ 
	Node<int> *a, *b, *c, *d, *e; 
	a = new Node<int>(1); 
	b = new Node<int>(2); 
	c = new Node<int>(3); 
	d = new Node<int>(4); 
	e = new Node<int>(5); 
	List<int> *list; 
	list = new List<int>(); 
	list->Insert(NULL,a);  
	list->Insert(a,b);  
	list->Insert(b,c);  
	list->Insert(a,d);  
	list->Insert(b,e); 
	list->printList();  
	list->Delete(a); 
	cout<<"\nAfter deleting first node"<<endl;  
	list->printList(); 
	// PLEASE ADD CALL TO MEMBER FUNCTION WHICH WOULD DIFFER SECTION-WISE 
	cout<<"\n After calling function"<<endl;
	list->Search(3);
	system("pause");
	return 0; 
}

/*Exercise 1: Implement a singly linked list. 
Implement all the methods given in the following class definition for singly linked list. Your code should work for the main function that follows. 

template <typename T>  
class Node 
{ 
public: 
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
    Node *link ; 
}; 

template <typename T>  
class List 
{ 
public: 
    // constructor of the Singly Linked List  
    List(); 
    //Inserts the node pNew after the node pBefore 
    // if the list is empty, it makes pNew the first node of the list 
    void Insert(Node<T>* pBefore, Node<T>* pNew); 
    //Deletes the node pToBeDeleted  
    void Delete(Node<T>* pToBeDeleted); 
    //prints the contents of the list  
    void printList(); 
    //ADD ONE OR TWO MEMBER FUNCTION(s) DIFFERENT FOR EACH LAB SECTION 
private: 
    Node<T> *first ;
}

int main() 
{ 
    Node<int> *a, *b, *c, *d, *e; 
    a = new Node<int>(1); 
    b = new Node<int>(2); 
    c = new Node<int>(3); 
    d = new Node<int>(4); 
    e = new Node<int>(5); 
    List<int> *list; 
    list = new List<int>(); 
    list->Insert(0 , a);  
    list->Insert(a , b);  
    list->Insert(b , c);  
    list->Insert(a , d);  
    list->Insert(b, e); 
    list->printList();  
    list->Delete(a); 
    cout<<"\nAfter deleting first node"<<endl;  
    list->printList(); 
    // PLEASE ADD CALL TO MEMBER FUNCTION WHICH WOULD DIFFER SECTION WISE e.g. list->reverse etc. 
    cout<<"\n After calling function"<<endl; list->printList(); 
    return 0; 
}
*/