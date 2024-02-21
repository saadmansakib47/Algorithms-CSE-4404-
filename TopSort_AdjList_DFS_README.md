# Topological Sort (Input : Adjacency List, DFS Implementation) 
## Overview
Topological Sort is an algorithm used to order the vertices of a directed graph such that for every directed edge from vertex u to vertex v, u comes before v in the ordering. It's commonly used in scheduling tasks with dependencies, compiling software, and resolving dependencies in package management systems.

## Time Complexity
The time complexity of Topological Sort is O(V+E), where V is the number of vertices and E is the number of edges in the graph.

## Steps
1.Perform Depth-First Search (DFS) on the graph.
2.During DFS, recursively visit all adjacent vertices of a vertex.
3.While visiting a vertex, push it onto a stack.
4.Once all adjacent vertices are visited, push the current vertex onto the stack.
5.After DFS traversal, the stack contains vertices in reverse topological order.
6.Pop vertices from the stack to get the topological order.

## Pseudocode 
```plaintext 
DFS(adjList, v, visited, topoOrder):
    visited[v] = true
    for each u in adjList[v]:
        if not visited[u]:
            DFS(adjList, u, visited, topoOrder)
    topoOrder.push(v)

TopologicalSort(adjList, V):
    visited = array of size V initialized with false
    topoOrder = empty stack
    for i from 0 to V-1:
        if not visited[i]:
            DFS(adjList, i, visited, topoOrder)
    Print "Topological Sort: "
    while not topoOrder.empty():
        print topoOrder.top()
        topoOrder.pop()
```

## Model Input 
Enter the number of vertices: 5
Enter the edges (format: vertex1 vertex2):
0 1
0 3
1 2
2 3
3 4

## Model Output 
Topological Sort: 0 1 2 3 4
