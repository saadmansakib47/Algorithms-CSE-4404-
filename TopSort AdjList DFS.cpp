#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to perform Depth-First Search (DFS) for Topological Sort
void DFS(vector<vector<int>>& adjList, int v, vector<bool>& visited, stack<int>& topoOrder)
{
    visited[v] = true;
    for (int u : adjList[v])
    {
        if (!visited[u])
            DFS(adjList, u, visited, topoOrder);
    }
    topoOrder.push(v);
}

// Function to perform Topological Sort using DFS
void TopologicalSort(vector<vector<int>>& adjList, int V)
{
    vector<bool> visited(V, false);
    stack<int> topoOrder;

    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
            DFS(adjList, i, visited, topoOrder);
    }

    cout << "Topological Sort: ";
    while (!topoOrder.empty())
    {
        cout << topoOrder.top() << " ";
        topoOrder.pop();
    }
    cout << endl;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    // Initialize adjacency list
    vector<vector<int>> adjList(V);

    cout << "Enter the edges (format: vertex1 vertex2):\n";
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    // Perform Topological Sort
    TopologicalSort(adjList, V);

    return 0;
}

