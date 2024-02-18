#include <iostream>
#include <stack>
using namespace std;

// Function to perform Depth-First Search (DFS)
void DFS(int adj[][100], int V, int start) {
    // Array to keep track of visited vertices
    bool visited[V] = {false};

    // Stack for DFS traversal
    stack<int> stack;

    // Push the starting vertex onto the stack
    stack.push(start);

    // Mark the starting vertex as visited
    visited[start] = true;

    // Print the starting vertex
    cout << "DFS Traversal from vertex " << start << ": ";

    while (!stack.empty()) {
        // Get the top vertex from the stack
        int current = stack.top();
        stack.pop();

        // Print the current vertex
        cout << current << " ";

        // Visit all adjacent vertices of the current vertex
        for (int i = 1; i <= V; ++i) {
            if (adj[current][i] && !visited[i]) {
                // If the neighbor has not been visited, mark it as visited and push it onto the stack
                visited[i] = true;
                stack.push(i);
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
    cout << "Enter the starting vertex for DFS: ";
    cin >> start_vertex;

    // Perform Depth-First Search (DFS)
    DFS(adj, V, start_vertex);

    return 0;
}

