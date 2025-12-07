#include "Graph.h"
#include <iostream>
#include <string>
#include <climits>
using namespace std;

Graph::Graph() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adj[i][j] = -1;
        }

    }
}

void Graph::addRoute(int u, int v, int distance) {
    if (u < 0 || v < 0 || u >= MAX || v >= MAX) {
        cout << "Invalid city index." << endl;
        return;
    }
    adj[u][v] = adj[v][u] = distance;
}

void Graph::removeRoute(int u, int v) {
    if (u < 0 || v < 0 || u >= MAX || v >= MAX) {
        cout << "Invalid city index." << endl;
        return;
    }
    adj[u][v] = adj[v][u] = -1;
}

int Graph::getCityIndex(string c) {
    for (int i = 0; i < MAX; i++)
        if (cities[i] == c) return i;
    return -1;
}

void Graph::printRouteMap() {
    cout << endl << "=== Route Map (Adj Matrix) ===" << endl;
    cout << "        ";
    for (int i = 0; i < MAX; i++)
        cout << cities[i] << "  ";
    cout << endl;

    for (int i = 0; i < MAX; i++) {
        cout << cities[i] << "  ";
        for (int j = 0; j < MAX; j++) {
            cout << adj[i][j] << "  ";
        }
        cout << endl;
    }
}

void Graph::dijkstraRecursive(int dist[], bool visited[], int parent[]) {
    const int INF = INT_MAX;
    int minNode = -1;
    int minDist = INF;

    for (int i = 0; i < MAX; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minNode = i;
        }
    }

    if (minNode == -1) return;
    visited[minNode] = true;

    for (int v = 0; v < MAX; v++) {
        if (adj[minNode][v] != -1) {  
            int newDist = dist[minNode] + adj[minNode][v];
            if (newDist < dist[v]) {
                dist[v] = newDist;
                parent[v] = minNode;
            }
        }
    }

    dijkstraRecursive(dist, visited, parent);
}

void Graph::findShortestRoute(int src, int dest) {
    const int INF = INT_MAX;
    int dist[MAX];
    bool visited[MAX];
    int parent[MAX];

    for (int i = 0; i < MAX; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[src] = 0;

    dijkstraRecursive(dist, visited, parent);

    if (dist[dest] == INF) {
        cout << "No possible route." << endl;
        return;
    }

    int path[MAX];
    int count = 0;
    for (int cur = dest; cur != -1; cur = parent[cur]) {
        path[count++] = cur;
    }

    cout << "Shortest route: ";
    for (int i = count - 1; i >= 0; i--) {
        cout << cities[path[i]];
        if (i > 0) cout << " -> ";
    }

    cout << "  (Distance = " << dist[dest] << ")" << endl;
}
