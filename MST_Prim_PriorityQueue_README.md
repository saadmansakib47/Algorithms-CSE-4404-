# Minimum Spanning Tree (MST) using Prim's Algorithm with Priority Queue

# Overview
Prim's algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, undirected graph. It starts with an arbitrary vertex and expands the MST by greedily selecting the edge with the lowest weight that connects a vertex in the MST to a vertex outside the MST. Priority queues are commonly used in Prim's algorithm to efficiently select the minimum weight edge.

## Time Complexity
Time complexity of Prim's algorithm with priority queue: O(V^2) for dense graphs, O(E log V) for sparse graphs

## Pseudocode
function PrimMSTWithPriorityQueue(adj, V):
    Initialize priority queue pq
    Initialize key values for all vertices to INF
    Initialize parent array to store MST
    Initialize inMST array to keep track of vertices in MST

    Choose a starting vertex
    Insert starting vertex into the priority queue with key value 0

    while pq is not empty:
        Extract the minimum key vertex u from the priority queue
        Include u in the MST

        for each vertex v adjacent to u:
            if v is not in MST and edge weight(u, v) < key[v]:
                Update key[v] with edge weight(u, v)
                Update parent[v] to u
                Insert v into the priority queue with updated key value

    Print edges in the constructed MST
