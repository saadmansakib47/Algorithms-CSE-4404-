#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

#define INF INT_MAX

// Function to add an edge to the graph
void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight)); // Undirected graph
}

// Function to find the Minimum Spanning Tree using Prim's algorithm
void primMST(vector<pair<int, int>> adj[], int V) {
    // Priority queue to store vertices with their key values
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> key(V, INF); // Key values used to pick minimum weight edge
    vector<bool> inMST(V, false); // To keep track of vertices included in MST
    vector<int> parent(V, -1); // Array to store constructed MST

    int src = 0; // Start with vertex 0

    // Insert source vertex into the priority queue and set its key value to 0
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; // Extract the vertex with minimum key value
        pq.pop();

        inMST[u] = true; // Include vertex u in MST

        // Traverse all adjacent vertices of u
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;

            // If v is not in MST and weight of (u,v) is smaller than current key of v
            if (inMST[v] == false && weight < key[v]) {
                // Update key value and push v into the priority queue
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    // Print the constructed MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "\n";
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    // Adjacency list to represent the graph
    vector<pair<int, int>> adj[V];

    cout << "Enter the edges and their weights (format: vertex1 vertex2 weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        addEdge(adj, u, v, weight);
    }

    // Find and print the Minimum Spanning Tree using Prim's algorithm
    primMST(adj, V);

    return 0;
}

