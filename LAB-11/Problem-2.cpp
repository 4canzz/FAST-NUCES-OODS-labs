#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node {
private:
    int data;
    Node *next;
public:
    Node(int d) : data(d), next(NULL) {}
    int getData() { return data; }
    void setData(int d) { data = d; }
    Node* getNext() { return next; }
    void setNext(Node* n) { next = n; }
};

class List {
private:
    Node *head;
public:
    List() { head = NULL; }

    void insert(int val) {
        Node *pnew = new Node(val);
        if (!head) {
            head = pnew;
            return;
        }
        Node *temp = head;
        while (temp->getNext())
            temp = temp->getNext();
        temp->setNext(pnew);
    }

    void remove(int val) {
        if (!head) return;
        if (head->getData() == val) {
            Node *temp = head;
            head = head->getNext();
            delete temp;
            return;
        }
        Node *curr = head;
        while (curr->getNext()) {
            if (curr->getNext()->getData() == val) {
                Node *temp = curr->getNext();
                curr->setNext(curr->getNext()->getNext());
                delete temp;
                return;
            }
            curr = curr->getNext();
        }
    }

    Node* getHead() { return head; }
};

class Graph {
private:
    List *adj;
    int numVertices;
public:
    Graph(int n) : numVertices(n), adj(new List[n]) {}

    int getNumVertices() { return numVertices; }
    void insertEdge(int frmVertex, int toVertex) { adj[frmVertex].insert(toVertex); }
    void removeEdge(int frmVertex, int toVertex) { adj[frmVertex].remove(toVertex); }

    int numberOfEdges() {
        int count = 0;
        for (int i = 0; i < numVertices; i++) {
            Node *curr = adj[i].getHead();
            while (curr) {
                count++;
                curr = curr->getNext();
            }
        }
        return count;
    }

    int degree(int v) {
        int deg = 0;
        Node *curr = adj[v].getHead();
        while (curr) {
            deg++;
            curr = curr->getNext();
        }
        return deg;
    }

    void depthfirstSearch(int s) {
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;

        stack<int> st;
        st.push(s);

        while (!st.empty()) {
            int v = st.top();
            st.pop();

            if (!visited[v]) {
                cout << v << " ";
                visited[v] = true;
            }

            Node *curr = adj[v].getHead();
            int count = 0;
            Node *tmp = curr;
            while (tmp) {
                count++;
                tmp = tmp->getNext();
            }

            int *nbrs = new int[count];
            tmp = curr;
            for (int i = 0; i < count; i++) {
                nbrs[i] = tmp->getData();
                tmp = tmp->getNext();
            }

            for (int i = count - 1; i >= 0; i--) {
                if (!visited[nbrs[i]])
                    st.push(nbrs[i]);
            }
            delete[] nbrs;
        }

        cout << endl;
        delete[] visited;
    }

    void breadthfirstSearch(int s) {
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }

        queue<int> q;
        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int v = q.front(); q.pop();
            cout << v << " ";

            Node *curr = adj[v].getHead();
            while (curr) {
                int nbr = curr->getData();
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
                curr = curr->getNext();
            }
        }

        cout << endl;
        delete[] visited;
    }
};

int main() 
{ 
    Graph *g; 
    //creating an object of graph with 5 vertices  
    g=new Graph(5); 
    //inserting edges in the graph  
    g->insertEdge(0,1); 
    g->insertEdge(0,4);  
    g->insertEdge(1,0);  
    g->insertEdge(1,2);  
    g->insertEdge(1,3);  
    g->insertEdge(1,4);  
    g->insertEdge(2,1);  
    g->insertEdge(2,3);  
    g->insertEdge(3,1);  
    g->insertEdge(3,2);  
    g->insertEdge(3,4);  
    g->insertEdge(4,0);  
    g->insertEdge(4,1);  
    g->insertEdge(4,3); 
    //display total number of edges 
    cout<< "Number of edges are "<< g->numberOfEdges()<<endl; 
    //display degree of vertex number 4  
    cout<<"Degree of vertex "<<g->degree(4)<<endl; 

    cout<<"Output for Depth first search starting from vertex 0 "<<endl;  
    g->depthfirstSearch(0); 
    cout<<"Output for Breadth first search starting from vertex 0 "<<endl;  
    g->breadthfirstSearch(0); 
    return 0; 
}

/*Exercise 2: 
Implement the in Lab Exercise1 using Adjacency List for representing the graph.*/