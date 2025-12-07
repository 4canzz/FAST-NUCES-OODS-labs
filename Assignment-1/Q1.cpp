/* 24L - 6116. Syed Furqan Hassan, BEE-3D
Question No. 1 (CLO No. 2) Marks: 50
You are given a singly linked list of integers. Write the code to split it into two new linked lists:
• List A: contains nodes at even positions (0-based indexing).
• List B: contains nodes at odd positions.
Finally, print both lists.*/

#include <iostream>
using namespace std;

class Node { 
private: 
	int data; 
	Node *next; 
public: 
	Node(int val) : data(val), next(NULL) {}
	void setData(int val) { data = val; }
	int getData() { return data; }
	Node* GetNext() { return next; }
	void SetNext(Node *x) { next = x; }
};

class List { 
private:
	Node* head;
public: 
	List() : head(NULL) {}
	~List() {
		Node* temp = head;
    	while (temp) {
			Node* next = temp->GetNext();
			delete temp;
			temp = next;
    	}
	}
	
	void Insert(Node* pBefore, Node* pNew) {
		if (!head) {  
			head = pNew; 
			pNew->SetNext(NULL);
		} else {
			pNew->SetNext(pBefore -> GetNext());
			pBefore->SetNext(pNew);
		}
	}

	void push_back(Node* pNew) {
		if(head) {
			Node* temp = head;
			while(temp->GetNext())
				temp = temp->GetNext();
			temp->SetNext(pNew);
		} else { head = pNew; }
	}

	void Delete(Node* pToBeDeleted) {
		if (!head) return;
		if (pToBeDeleted == head) { 
			head = head -> GetNext();
			delete pToBeDeleted;
			return;
		}
		Node* prev = head;
		while(prev->GetNext() != NULL && prev->GetNext() != pToBeDeleted) { 
		    prev = prev->GetNext();  
		}
        prev -> SetNext(pToBeDeleted->GetNext());
        delete pToBeDeleted;
	} 

	void printList() {
		Node* temp = head;
		while (temp) {
			cout << temp-> getData() << " "; 
			temp = temp->GetNext();  
		}
		cout << endl;
	}

    void SplitAndPrintLinkedList (List* A, List* B) {
		Node* temp = head;
		int index = 0;
		while (temp) {
			Node* tempNode = new Node(temp->getData());
			if (index++ % 2 == 0)
				A->push_back(tempNode);
			else
				B->push_back(tempNode);

			temp = temp->GetNext();
		}
		cout << "list A (even nodes (assuming 0 indexing)) : " << endl;
		A->printList();
		cout << "list B (odd nodes): " << endl;
		B->printList(); 
    }
};

int main() {
    Node* a = new Node(0);
    Node* b = new Node(1);
    Node* c = new Node(2);
    Node* d = new Node(3);
    Node* e = new Node(4);
    Node* f = new Node(5);
    List* list = new List();
    list->push_back(a);  
	list->push_back(b);  
	list->push_back(c);  
	list->push_back(d);  
	list->push_back(e); 
    list->push_back(f); 
	cout << "linked list: " << endl;
	list->printList();
    List* A = new List();
    List* B = new List();
	cout << "after spliting linked list: " << endl;
    list->SplitAndPrintLinkedList(A, B);
    return 0;
}
