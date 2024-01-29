# Heap Sort

## Overview

Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure. It divides the input into a sorted and an unsorted region and iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region.

## Algorithm Steps:

1. **Build Heap**: Build a max-heap from the input array.

2. **Extract Elements**: Repeatedly extract the maximum element from the heap and move it to the sorted region.

3. **Heapify**: After each extraction, heapify the remaining elements to maintain the max-heap property.

4. **Completion**: The final sorted list is now complete.

## Time Complexity
O(n log n), where n is the number of elements in the array.

## Pseudocode

```plaintext
function heapSort(arr):
    n = length(arr)
    
    # Build max-heap
    for i from n / 2 - 1 down to 0:
        heapify(arr, n, i)
    
    # Extract elements and heapify
    for i from n - 1 down to 1:
        swap(arr[0], arr[i])
        heapify(arr, i, 0)

function heapify(arr, n, i):
    largest = i
    left_child = 2 * i + 1
    right_child = 2 * i + 2
    
    # Check if left child is larger than root
    if left_child < n and arr[left_child] > arr[largest]:
        largest = left_child
    
    # Check if right child is larger than root
    if right_child < n and arr[right_child] > arr[largest]:
        largest = right_child
    
    # Swap root with the largest element if needed
    if largest != i:
        swap(arr[i], arr[largest])
        # Recursively heapify the affected sub-tree
        heapify(arr, n, largest)
