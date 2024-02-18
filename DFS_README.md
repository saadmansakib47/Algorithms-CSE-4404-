# Depth-First Search (DFS) Algorithm

This repository contains a C++ implementation of the Depth-First Search (DFS) algorithm. DFS is a graph traversal technique used to explore a graph by traversing as far as possible along each branch before backtracking. It is often used to find connected components, detect cycles, and solve problems such as maze traversal.

## Overview

Depth-First Search (DFS) is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It traverses a graph by starting at a root vertex and explores as far as possible along each branch before backtracking. DFS uses a stack data structure to keep track of vertices to visit.

## Algorithm Steps

1. Initialize a stack to store vertices.
2. Push the starting vertex onto the stack.
3. While the stack is not empty:
   - Pop a vertex from the stack.
   - If the vertex has not been visited:
     - Mark the vertex as visited.
     - Explore its adjacent vertices and push them onto the stack.
4. Repeat until the stack is empty.

## Pseudocode

```plaintext
function DFS(adj, V, start):
// Initialize stack to store vertices
stack = empty stack
// Mark all vertices as not visited
visited[V] = {false}
// Push the starting vertex onto the stack
stack.push(start)
// Mark the starting vertex as visited
visited[start] = true
while stack is not empty:
    // Pop a vertex from the stack
    current = stack.pop()
    // Process the current vertex
    // Print or store the current vertex
    // Explore its adjacent vertices
    for each neighbor of current:
        if neighbor is not visited:
            // Mark the neighbor as visited
            visited[neighbor] = true
            // Push the neighbor onto the stack
            stack.push(neighbor)

## Time Complexity

The time complexity of DFS is O(V + E), where V is the number of vertices and E is the number of edges in the graph.
