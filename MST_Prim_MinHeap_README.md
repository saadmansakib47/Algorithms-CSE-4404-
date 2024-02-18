# Minimum Spanning Tree (MST) using Prim's Algorithm with Min Heap
# Overview
Prim's algorithm can also be implemented using a min heap instead of a priority queue to efficiently select the minimum weight edge. A min heap is a binary tree structure where the parent node has a smaller value than its children. By maintaining the heap property, the minimum element can be efficiently extracted.

## Time Complexity
Time complexity of Prim's algorithm with min heap: O(V log V + E log V)
## Pseudocode
function PrimMSTWithMinHeap(adj, V):
    Initialize min heap heap
    Initialize position array pos to track vertex positions in the heap
    Initialize key values for all vertices to INF
    Initialize parent array to store MST
    Initialize inMST array to keep track of vertices in MST

    Choose a starting vertex
    Insert starting vertex into the heap with key value 0

    while heap is not empty:
        Extract the minimum key vertex u from the heap
        Include u in the MST

        for each vertex v adjacent to u:
            if v is not in MST and edge weight(u, v) < key[v]:
                Update key[v] with edge weight(u, v)
                Update parent[v] to u
                If v is not in the heap, insert v into the heap with updated key value
                Otherwise, decrease key value of v in the heap and maintain heap property

    Print edges in the constructed MST
