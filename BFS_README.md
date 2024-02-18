# Breadth-First Search (BFS) Algorithm

This repository contains a C++ implementation of the Breadth-First Search (BFS) algorithm. BFS is a graph traversal technique used to explore a graph by traversing all vertices at the current level before moving to the next level. It is often used to find shortest paths in unweighted graphs, solve puzzles, and discover connected components.

## Overview

Breadth-First Search (BFS) is a graph traversal algorithm that explores all vertices at the current level before moving to the next level. It traverses a graph level by level, starting from a root vertex. BFS uses a queue data structure to keep track of vertices to visit.

## Algorithm Steps

1. Initialize a queue to store vertices.
2. Enqueue the starting vertex into the queue.
3. While the queue is not empty:
   - Dequeue a vertex from the queue.
   - If the vertex has not been visited:
     - Mark the vertex as visited.
     - Enqueue its adjacent vertices into the queue.
4. Repeat until the queue is empty.

## Time Complexity

The time complexity of BFS is O(V + E), where V is the number of vertices and E is the number of edges in the graph.


## Pseudocode
```plaintext

function BFS(adj, V, start):
// Initialize queue to store vertices
queue = empty queue
// Mark all vertices as not visited
visited[V] = {false}
// Enqueue the starting vertex into the queue
queue.enqueue(start)
// Mark the starting vertex as visited
visited[start] = true
while queue is not empty:
    // Dequeue a vertex from the queue
    current = queue.dequeue()
    // Process the current vertex
    // Print or store the current vertex
    // Explore its adjacent vertices
    for each neighbor of current:
        if neighbor is not visited:
            // Mark the neighbor as visited
            visited[neighbor] = true
            // Enqueue the neighbor into the queue
            queue.enqueue(neighbor)
