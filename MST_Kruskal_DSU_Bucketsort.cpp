#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// Structure to represent an edge in the graph
struct Edge {
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

// Function to perform Bucket Sort on edges based on their weights
void bucketSort(vector<Edge>& edges, int maxWeight) {
    int n = edges.size();
    vector<vector<Edge>> buckets(maxWeight + 1);

    // Distribute edges into buckets based on their weights
    for (const auto& edge : edges) {
        buckets[edge.weight].push_back(edge);
    }

    // Concatenate all buckets to get sorted edges
    int index = 0;
    for (int i = 0; i <= maxWeight; ++i) {
        for (const auto& edge : buckets[i]) {
            edges[index++] = edge;
        }
    }
}

// Function to find set of an element i
int find(vector<int>& parent, int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Function to perform union of two sets
void Union(vector<int>& parent, int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Function to find Minimum Spanning Tree using Kruskal's algorithm with Bucket Sort and DSU
void KruskalMSTWithBucketSort(vector<Edge>& edges, int V) {
    // Find maximum edge weight
    int maxWeight = 0;
    for (const auto& edge : edges) {
        maxWeight = max(maxWeight, edge.weight);
    }

    // Sort edges using Bucket Sort
    bucketSort(edges, maxWeight);

    vector<int> parent(V, -1); // To store parent of each vertex

    cout << "Edges in the Minimum Spanning Tree:\n";
    int edgeCount = 0;
    for (const auto& edge : edges) {
        if (edgeCount == V - 1) // MST has V-1 edges
            break;

        int x = find(parent, edge.src);
        int y = find(parent, edge.dest);

        if (x != y) {
            cout << edge.src << " - " << edge.dest << " (Weight: " << edge.weight << ")\n";
            Union(parent, x, y);
            edgeCount++;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    // Create a vector to store edges of the graph
    vector<Edge> edges;

    cout << "Enter the edges and their weights (format: vertex1 vertex2 weight):\n";
    for (int i = 0; i < E; ++i)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        edges.push_back(createEdge(src, dest, weight));
    }

    // Find and print the Minimum Spanning Tree using Kruskal's algorithm with Bucket Sort and DSU
    KruskalMSTWithBucketSort(edges, V);

    return 0;
}

