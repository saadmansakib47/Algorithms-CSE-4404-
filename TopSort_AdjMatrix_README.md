# Topological Sort (Straightforward) 

## Overview
Topological Sort is an algorithm used to order the vertices of a directed graph such that for every directed edge from vertex u to vertex v, u comes before v in the ordering. It's commonly used in scheduling tasks with dependencies, compiling software, and resolving dependencies in package management systems.

## Time Complexity
The time complexity of Topological Sort is O(V+E), where V is the number of vertices and E is the number of edges in the graph.

## Steps
1.Calculate the indegree of each vertex.
2.Identify vertices with an indegree of 0 (initial set of vertices).
3.Remove these vertices from the graph along with their incident edges.
4.Update the indegrees of the remaining vertices.
5.Repeat steps 2-4 until all vertices are visited or a cycle is detected.

## Pseudocode
```plaintext
LookWhoseIndegree0(graph, indegree):
    nodes = []
    for each vertex v in graph:
        if indegree[v] == 0:
            nodes.push_back(v)
    return nodes

TopologicalSort(graph):
    V = number of vertices in graph
    Calculate indegree of each vertex
    
    for i from 0 to V-1:
        nodes = LookWhoseIndegree0(graph, indegree)
        if nodes is empty:
            print "Graph has a cycle. Topological sort is not possible."
            return
        for each node in nodes:
            print node
            Update indegree of adjacent vertices
            Mark current node as visited
```
## Model Input 
Enter the number of vertices: 5
Enter the adjacency matrix:
0 1 0 0 0
0 0 1 1 0
0 0 0 1 1
0 0 0 0 1
0 0 0 0 0

## Model Output 
Topological Sort: 0 1 2 3 4

