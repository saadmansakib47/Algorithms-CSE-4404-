#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
    int src, dest, weight;
};

// Function to create a graph edge
Edge createEdge(int src, int dest, int weight) {
    Edge edge;
    edge.src = src;
    edge.dest = dest;
    edge.weight = weight;
    return edge;
}

// Function to perform Depth-First Search (DFS)
void DFS(vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int src) {
    visited[src] = true;
    for (const auto& edge : adj[src]) {
        int neighbor = edge.first;
        if (!visited[neighbor]) {
            cout << src << " - " << neighbor << " (Weight: " << edge.second << ")\n";
            DFS(adj, visited, neighbor);
        }
    }
}

// Function to find Minimum Spanning Tree using Kruskal's algorithm with DFS
void KruskalMSTWithDFS(vector<Edge>& edges, int V) {
    // Sort all edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    vector<vector<pair<int, int>>> adj(V); // Adjacency list representation of the graph

    // Add edges to the adjacency list
    for (const auto& edge : edges) {
        adj[edge.src].push_back(make_pair(edge.dest, edge.weight));
        adj[edge.dest].push_back(make_pair(edge.src, edge.weight)); // Undirected graph
    }

    vector<bool> visited(V, false); // To keep track of visited vertices

    cout << "Edges in the Minimum Spanning Tree:\n";
    DFS(adj, visited, 0); // Start DFS from vertex 0
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    // Create a vector to store edges of the graph
    vector<Edge> edges;

    cout << "Enter the edges and their weights (format: vertex1 vertex2 weight):\n";
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        edges.push_back(createEdge(src, dest, weight));
    }

    // Find and print the Minimum Spanning Tree using Kruskal's algorithm with DFS
    KruskalMSTWithDFS(edges, V);

    return 0;
}

