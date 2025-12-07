#pragma once
#include <climits>
#include "List.h" 
#include "MinHeap.h"  
using namespace std;

class Edge {
private:
    int to;
    int weight;
public:
    Edge() : to(0), weight(0) {}
    Edge(int t, int w) : to(t), weight(w) {}

    int getTo() const { return to; }
    int getWeight() const { return weight; }

    void setTo(int t) { to = t; }
    void setWeight(int w) { weight = w; }

    friend ostream& operator<<(ostream& os, const Edge& e) {
        os << "->" << e.to << "(wt:" << e.weight << ")";
        return os;
    }
};

class Graph {
private:
    int V;
    SLList<Edge>* adj;
public:

    Graph(int vertices) {
        V = vertices;
        adj = new SLList<Edge>[V];
    }

    int getV() const { return V; }

    SLList<Edge>& neighbors(int u) { return adj[u]; }

    void addEdge(int u, int v, int w) {
        Edge e(v, w);
        adj[u].Insert(e);
    }

    void printGraph() {
        cout << "Graph adjacency list: "  << endl;
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            adj[i].printList();
        }
        cout << endl;
    }

    void dijkstra(int src, int* dist) {
        bool* visited = new bool[V];

        for (int i = 0; i < V; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
        }

        dist[src] = 0;

        MinHeap heap(2000);
        heap.push(src, 0);

        while (!heap.isEmpty()) {
            HeapNode node = heap.pop();
            int u = node.vertex;

            if (visited[u]) continue;
            visited[u] = true;

            SNode<Edge>* temp = adj[u].GetHead();

            while (temp != NULL) {
                Edge e = temp->getData();
                int v = e.getTo();
                int w = e.getWeight();

                if (!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {

                    dist[v] = dist[u] + w;
                    heap.push(v, dist[v]);
                }

                temp = temp->GetNext();
            }
        }

        delete[] visited;
    }


    ~Graph() {
        delete[] adj;
    }
};
