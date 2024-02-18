
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;

#define INF INT_MAX

// Function to add an edge to the graph
void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight)); // Undirected graph
}

// Function to heapify a min heap
void heapify(vector<pair<int, int>>& heap, int i, vector<int>& pos) {
    int n = heap.size();
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].second < heap[smallest].second)
        smallest = left;

    if (right < n && heap[right].second < heap[smallest].second)
        smallest = right;

    if (smallest != i) {
        pos[heap[i].first] = smallest;
        pos[heap[smallest].first] = i;
        swap(heap[i], heap[smallest]);
        heapify(heap, smallest, pos);
    }
}

// Function to extract minimum element from min heap
pair<int, int> extractMin(vector<pair<int, int>>& heap, vector<int>& pos) {
    if (heap.empty())
        return make_pair(-1, -1);

    pair<int, int> root = heap[0];
    heap[0] = heap.back();
    pos[root.first] = -1;
    pos[heap[0].first] = 0;
    heap.pop_back();
    heapify(heap, 0, pos);

    return root;
}

// Function to decrease key value of a vertex in min heap
void decreaseKey(vector<pair<int, int>>& heap, vector<int>& pos, int v, int key)
{
    int idx = pos[v];
    heap[idx].second = key;
    while (idx > 0 && heap[(idx - 1) / 2].second > heap[idx].second) {
        pos[heap[idx].first] = (idx - 1) / 2;
        pos[heap[(idx - 1) / 2].first] = idx;
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
    // After moving up, if the vertex is still not at its correct position, move it down
    while (2 * idx + 1 < heap.size()) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        if (left < heap.size() && heap[left].second < heap[smallest].second)
            smallest = left;
        if (right < heap.size() && heap[right].second < heap[smallest].second)
            smallest = right;
        if (smallest != idx) {
            pos[heap[idx].first] = smallest;
            pos[heap[smallest].first] = idx;
            swap(heap[idx], heap[smallest]);
            idx = smallest;
        } else {
            break;
        }
    }
}

// Function to find the Minimum Spanning Tree using Prim's algorithm
void primMST(vector<pair<int, int>> adj[], int V) {
    vector<pair<int, int>> heap; // Min heap to store vertices with their key values
    vector<int> pos(V, -1); // Position of vertices in the heap
    vector<int> key(V, INF); // Key values used to pick minimum weight edge
    vector<bool> inMST(V, false); // To keep track of vertices included in MST
    vector<int> parent(V, -1); // Array to store constructed MST

    int src = 0; // Start with vertex 0

    // Insert source vertex into the heap and set its key value to 0
    heap.push_back(make_pair(src, 0));
    pos[src] = 0;
    key[src] = 0;

    while (!heap.empty()) {
        pair<int, int> top = extractMin(heap, pos);
        int u = top.first;
        inMST[u] = true;

        // Traverse all adjacent vertices of u
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;

            // If v is not in MST and weight of (u,v) is smaller than current key of v
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                if (pos[v] == -1) {
                    heap.push_back(make_pair(v, key[v]));
                    pos[v] = heap.size() - 1;
                } else {
                    decreaseKey(heap, pos, v, key[v]);
                }
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
