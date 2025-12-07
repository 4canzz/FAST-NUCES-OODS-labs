#pragma once
#include <iostream>
#include <string>
using namespace std;

class Graph {
private:
    static const int MAX = 5; // FIXED NUMBER OF CITIES
    string cities[MAX] = {"Lahore", "Islamabad", "Karachi", "Multan", "Peshawar"};
    int adj[MAX][MAX];
    void dijkstraRecursive(int dist[], bool visited[], int parent[]);
public:
    Graph();
    void addRoute(int u, int v, int distance);
    void removeRoute(int u, int v);
    void findShortestRoute(int src, int dest);
    int getCityIndex(string c);
    void printRouteMap();
};