# Kruskal's Algorithm for Minimum Spanning Tree using Depth-First Search (DFS)
# Overview 
Kruskal's algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, undirected graph. The MST is a subset of the edges of the graph that connects all the vertices together with the minimum possible total edge weight.

## Time Complexity: 
The time complexity of Kruskal's algorithm using the DFS approach is typically O(E log E), where E is the number of edges in the graph. Sorting the edges based on weight dominates the time complexity.
## Pseudocode:
KruskalMSTWithDFS(edges, V):
    Sort edges in non-decreasing order of weight
    
    Initialize an empty MST
    
    for each edge in sorted edges:
        if adding the edge to MST doesn't form a cycle:
            add the edge to MST
            
    return MST
