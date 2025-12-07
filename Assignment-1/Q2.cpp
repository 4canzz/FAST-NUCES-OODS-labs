/* 24L - 6116. Syed Furqan Hassan, BEE-3D
Question No. 2 (CLO No. 2) Marks: 50
Determine the best data structure that you have studied so far and design the solution to the following
problem. You are asked to develop a program to maintain records of patients admitted to a hospital.
Each record contains a patient’s ID, name, and disease.
Your program should support the following operations:
1. Admit a new patient (add to the system).
2. Discharge a patient (delete their record efficiently).
3. Print the list of currently admitted patients.*/

/*
Justification for using Doubly Linked List Data Structure:
This program uses a DLL to store patient records. A DLL allows efficient insertion  and deletion of nodes without shifting elements (O(1)). 
This is suitable for maintaining hospital records because patients may be admitted or discharged at any time, and deleting
a node only requires updating two pointers.
*/

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node { 
private: 
	T data; 
	Node *next;
    Node *prev; 
public: 
	Node(T val) : data(val), next(NULL), prev(NULL) {}
	void setData(T val) { data = val; }
	T& getData() { return data; }
	Node<T>* GetNext() { return next; }
	void SetNext(Node *x) { next = x; }
    Node<T>* GetPrev() { return prev; }
    void SetPrev(Node *x) { prev = x; }
};

template <typename T>
class DLList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    DLList() : head(NULL), tail(NULL) {}
    ~DLList() {
		Node<T>* temp = head;
    	while (temp) {
			Node<T>* next = temp->GetNext();
			delete temp;
			temp = next;
	    }
    }

    void push_back(const T& newData) {
        Node<T>* newNode = new Node<T>(newData);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->SetNext(newNode);       
        newNode->SetPrev(tail);
        tail = newNode; 
    }

    bool Delete(Node<T>* pTobeDeleted) {
        if (!pTobeDeleted) return false;
        if (pTobeDeleted->GetPrev()) pTobeDeleted->GetPrev()->SetNext(pTobeDeleted->GetNext());
        else head = pTobeDeleted->GetNext();
        if (pTobeDeleted->GetNext()) pTobeDeleted->GetNext()->SetPrev(pTobeDeleted->GetPrev());
        else tail = pTobeDeleted->GetPrev();
        delete pTobeDeleted;
        return true;
    }   

    void printList() {
        if (!head) {
            cout << endl << "No patients currently admitted." << endl;
            return;
        }
        Node<T>* temp = head;
        cout << endl <<"--- Current Patients ---" << endl;
        while (temp) {
            cout << "ID: " << temp->getData().id << endl;
            cout << ", Name: " << temp->getData().name << endl;
            cout << ", Disease: " << temp->getData().disease << endl;
            temp = temp->GetNext();
        }
        cout << endl << "-------------------------" << endl;
    }

    Node<T>* SearchbyID(int key) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->getData().id == key) return temp;
            temp = temp->GetNext();
        }
        return NULL;
    }
};

struct Patient {
    int id;
    string name;
    string disease;
    Patient(int i, const string& n, const string& d) : id(i), name(n), disease(d) {}
};

class Hospital {
private:
    DLList<Patient> patients;
public:
    void admitPatient(int id, const string& name, const string& disease) {
        patients.push_back(Patient(id, name, disease));
        cout << "Patient admitted successfully." << endl;
    }

    void dischargePatient(int id) {
        if (patients.Delete(patients.SearchbyID(id))) cout << "Patient discharged successfully." << endl;
        else cout << "Patient with ID " << id << " not found." << endl;
    }

    void printPatients() {
        patients.printList();
    }

    void searchPatient(int id) {
        Node<Patient>* result = patients.SearchbyID(id);
        if (result) {
            Patient& p = result->getData();
            cout << "Patient found: " << endl;
            cout << "ID: " << p.id << endl;
            cout << ", Name: " << p.name << endl;
            cout << ", Disease: " << p.disease << endl;
        } else cout << "No patient found with ID " << id << endl;
    }
};

int main() {
    Hospital hospital;
    int choice;

    while (true) {
        cout << endl  << "--- Hospital Management Menu ---" << endl;
        cout << "1. Admit new patient" << endl;
        cout << "2. Discharge a patient" << endl;
        cout << "3. Print all admitted patients" << endl;
        cout << "4. Search for a patient" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name, disease;
            cout << "Enter patient ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter patient name: ";
            getline(cin, name);
            cout << "Enter patient disease: ";
            getline(cin, disease);
            hospital.admitPatient(id, name, disease);
        } 
        else if (choice == 2) {
            int id;
            cout << "Enter patient ID to discharge: ";
            cin >> id;
            hospital.dischargePatient(id);
        } 
        else if (choice == 3) {
            hospital.printPatients();
        } 
        else if (choice == 4) {
            int id;
            cout << "Enter patient ID to search: ";
            cin >> id;
            hospital.searchPatient(id);
        } 
        else if (choice == 5) {
            cout << "Exiting program" << endl;
            break;
        } 
        else {
            cout << "Invalid choice, try again." << endl;
        }
    }
    return 0;
}