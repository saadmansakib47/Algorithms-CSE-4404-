#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset
{
    int parent, rank;
};

// Function to create a graph edge
Edge createEdge(int src, int dest, int weight)
{
    Edge edge;
    edge.src = src;
    edge.dest = dest;
    edge.weight = weight;
    return edge;
}

// Function to find set of an element i
int find(vector<Subset>& subsets, int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two sets
void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find Minimum Spanning Tree using Kruskal's algorithm
void KruskalMST(vector<Edge>& edges, int V) {
    // Sort all edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
    {
        return a.weight < b.weight;
    });

    vector<Edge> MST; // To store the edges of the MST
    vector<Subset> subsets(V); // To store subsets for union-find

    // Initialize subsets for union-find
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int edgeCount = 0; // Count of edges added to MST
    int i = 0; // Index for traversing sorted edges array

    // Keep adding edges to the MST until V-1 edges are added
    while (edgeCount < V - 1 && i < edges.size()) {
        Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge doesn't cause cycle, include it in MST
        if (x != y) {
            MST.push_back(nextEdge);
            Union(subsets, x, y);
            edgeCount++;
        }
    }

    // Print the edges of the MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto& edge : MST) {
        cout << edge.src << " - " << edge.dest << " (Weight: " << edge.weight << ")\n";
    }
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

    // Find and print the Minimum Spanning Tree using Kruskal's algorithm
    KruskalMST(edges, V);

    return 0;
}
