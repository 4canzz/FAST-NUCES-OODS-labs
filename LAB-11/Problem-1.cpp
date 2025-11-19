#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Graph {
public:
    //part1: constructor initializes adjacency matrix
    Graph(int numVertex) : numVertices(numVertex) {
        adj_matrix = new int*[numVertex];
        for (int i = 0; i < numVertices; i++) {
            adj_matrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adj_matrix[i][j] = 0;
            }
        }
    }
    //part2: returns the number of vertices in the graph
    int GetNumVertices() { return numVertices; }
    //part3: returns the number of edges in the graph
    int numberOfEdges() {
        int count = 0;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (adj_matrix[i][j] == 1) count++;
            }
        }
        return count;
    }
    //part4: inserts edge going from one vertex to another
    void insertEdge(int frmVertex, int toVertex) {
        if (frmVertex >= 0 && frmVertex < numVertices && toVertex >= 0 && toVertex < numVertices)
            adj_matrix[frmVertex][toVertex] = 1;
    }
    //part5: removes edge going from one vertex to another
    void removeEdge(int frmVertex, int toVertex) {
        if (frmVertex >= 0 && frmVertex < numVertices && toVertex >= 0 && toVertex < numVertices)
        adj_matrix[frmVertex][toVertex] = 0;
    }
    //part6: returns the degree of the node passed
    int degree(int vertex) {
        int deg = 0;
        for (int j = 0; j < numVertices; j++) {
            if (adj_matrix[vertex][j] == 1) deg++;
        }
        return deg;
    }
    //part7: outputs the order in which vertices are visited during DFS
    //Starting from node s.
    void depthfirstSearch(int s) {
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;

        stack<int> st;  
        st.push(s);

        while (!st.empty()) {
            int v = st.top(); st.pop();
            if (!visited[v]) {
                cout << v << " ";
                visited[v] = true;
            }
            for (int i = numVertices - 1; i >= 0; i--) {
                if (adj_matrix[v][i] == 1 && !visited[i]) {
                    st.push(i);
                }
            }
        }

        cout << endl;
        delete[] visited;
    }
    //part8: outputs the order in which vertices are visited during BFS
    //Starting from node s.
    void breadthfirstSearch(int s) {
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++) {
            visited[i] = false;
        }

        queue<int> q;
        visited[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int i = 0; i < numVertices; i++) {
                if (adj_matrix[v][i] == 1 && visited[i] == false) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        cout << endl;
        delete[] visited;
    }
private:
    int **adj_matrix;
    int numVertices;
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

/*Exercise 1: 

Implement the following Graph ADT using Adjacency matrix representation of graph
#ifndef GRAPH_H
#defineGRAPH_H
Class Graph
{
public:
    //part1: constructor initializes adjacency matrix
    Graph(int numVertex);
    //part2: returns the number of vertices in the graph
    int GetNumVertices();
    //part3: returns the number of edges in the graph
    int numberOfEdges();
    //part4: inserts edge going from one vertex to another
    void insertEdge(int frmVertex, int toVertex);
    //part5: removes edge going from one vertex to another
    void removeEdge((int frmVertex, int toVertex);
    //part6: returns the degree of the node passed
    int degree(int vertex);
    //part7: outputs the order in which vertices are visited during DFS
    //Starting from node s.
    void depthfirstSearch(int s);
    //part8: outputs the order in which vertices are visited during BFS
    //Starting from node s.
    void breadthfirstSearch(int s);
private:
    int **adj_matrix;
    int numVertices;
};
#endif*/