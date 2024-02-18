# Improved Kruskal's Algorithm for Minimum Spanning Tree using Bucket Sort and Disjoint-Set Union (DSU)
In this improved version of Kruskal's algorithm, we utilize the Bucket Sort algorithm to efficiently sort the edges based on their weights. By employing Bucket Sort, we can achieve a time complexity of O(E + V) for sorting the edges, significantly reducing the overall time complexity of the algorithm.

# Kruskal's algorithm with Bucket Sort and DSU employs the following steps:

Bucket Sort: We distribute the edges into buckets based on their weights. Each bucket represents a range of edge weights. By sorting the edges into buckets, we reduce the time complexity of sorting from O(E log E) to O(E + V).

Disjoint-Set Union (DSU): We initialize a DSU data structure to handle union and find operations on disjoint sets efficiently.

Construct Minimum Spanning Tree (MST): We iterate through the buckets in ascending order of weights. For each bucket, we process the edges in it and add them to the MST if adding the edge does not form a cycle. We use the DSU data structure to determine whether adding an edge creates a cycle.

# Pseudocode 
KruskalMSTWithBucketSort(edges, V):
    1. Find the maximum edge weight among all edges in the graph.
    2. Initialize a vector of vectors to represent buckets, each bucket corresponding to a weight value from 0 to the maximum edge weight.
    3. Distribute edges into buckets based on their weights using Bucket Sort.
    4. Initialize a parent array to store the parent of each vertex. Initialize all elements to -1.
    5. Initialize an integer variable edgeCount to 0.
    6. Iterate through the buckets in ascending order of weights:
        a. For each edge in the current bucket:
            i. If edgeCount is equal to V - 1 (number of vertices minus 1), break the loop (MST is complete).
            ii. Find the parent of the source vertex (x) and the parent of the destination vertex (y) using the find function.
            iii. If x and y are not in the same set (i.e., they do not have the same parent):
                - Print the edge (source - destination) and its weight.
                - Union the sets of x and y using the Union function.
                - Increment edgeCount.
    7. End loop.

# Time Complexity
Sorting edges using Bucket Sort: O(E + V)
DSU operations and constructing MST: O(E log V)
Overall time complexity: O(E + V) + O(E log V) = O(E log V)

# Note : 
The primary advantage of using Bucket Sort in Kruskal's Algorithm lies in reducing the constant factor associated with the sorting process. While both Bucket Sort and traditional comparison-based sorting algorithms like QuickSort or MergeSort have the same theoretical time complexity, Bucket Sort typically exhibits better performance in practice for certain scenarios.

Here's why Bucket Sort might be advantageous:

Reduced Overhead: Bucket Sort has a lower overhead compared to comparison-based sorting algorithms, as it operates based on distributing elements into buckets rather than repeatedly comparing elements.

Improved Cache Locality: Bucket Sort tends to have better cache locality, especially when the number of buckets is small compared to the total number of elements. This can lead to fewer cache misses and better overall performance.

Optimized for Specific Range: In Kruskal's Algorithm, the edge weights typically have a known range (e.g., weights are integers between 0 and some maximum value). Bucket Sort takes advantage of this knowledge and directly sorts elements into buckets, which can be more efficient than general-purpose sorting algorithms.
