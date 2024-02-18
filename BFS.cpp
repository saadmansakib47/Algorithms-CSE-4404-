#include <iostream>
#include <queue>
using namespace std;

// Function to perform Breadth-First Search (BFS)
void BFS(int adj[][100], int V, int start) {
    // Array to keep track of visited vertices
    bool visited[V] = {false};

    // Queue for BFS traversal
    queue<int> queue;

    // Enqueue the starting vertex
    queue.push(start);

    // Mark the starting vertex as visited
    visited[start] = true;

    // Print the starting vertex
    cout << "BFS Traversal from vertex " << start << ": ";

    while (!queue.empty()) {
        // Dequeue a vertex from the queue
        int current = queue.front();
        queue.pop();

        // Print the current vertex
        cout << current << " ";

        // Visit all adjacent vertices of the current vertex
        for (int i = 1; i <= V; ++i) {
            if (adj[current][i] && !visited[i]) {
                // If the neighbor has not been visited, mark it as visited and enqueue it
                visited[i] = true;
                queue.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    // Create an adjacency matrix representation of the graph
    int adj[100][100] = {0};

    cout << "Enter the edges (format: vertex1 vertex2):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // Assuming the graph is undirected
        adj[v][u] = 1; // If the graph is directed, remove this line
    }

    int start_vertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> start_vertex;

    // Perform Breadth-First Search (BFS)
    BFS(adj, V, start_vertex);

    return 0;
}
