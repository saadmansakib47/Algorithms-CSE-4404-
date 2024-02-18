# Kruskal's Algorithm for Minimum Spanning Tree using Disjoint-Set Union (DSU)
# Overview 
Kruskal's algorithm can also be implemented using the Disjoint-Set Union (DSU) data structure, which efficiently handles union and find operations on disjoint sets.

## Time Complexity: 
The time complexity of Kruskal's algorithm using the DSU approach is typically O(E log V), where V is the number of vertices and E is the number of edges in the graph. The time complexity is dominated by the sorting of edges and the union-find operations.

## Pseudocode:
KruskalMSTWithDSU(edges, V):
    Sort edges in non-decreasing order of weight
    
    Initialize an empty MST
    
    Initialize a DSU data structure
    
    for each edge in sorted edges:
        if adding the edge to MST doesn't form a cycle:
            add the edge to MST
            merge the sets of the endpoints of the edge
            
    return MST
