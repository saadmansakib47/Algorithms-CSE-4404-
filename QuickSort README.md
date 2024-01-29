# Quick Sort

## Overview

Quick Sort is a divide-and-conquer sorting algorithm that uses a pivot element to partition the array into two sub-arrays, and then recursively sorts the sub-arrays. It is an efficient and widely used sorting algorithm.

## Algorithm Steps:

1. **Choose Pivot**: Select a pivot element from the array.

2. **Partition**: Partition the array into two sub-arrays - elements less than the pivot and elements greater than the pivot.

3. **Recursively Sort Sub-arrays**: Apply the quick sort algorithm recursively to the sub-arrays.

4. **Combine**: Combine the sorted sub-arrays to get the final sorted array.

## Time Complexity
O(n^2) in the worst case, but O(n log n) on average, where n is the number of elements in the array.

## Pseudocode

```plaintext
function quickSort(arr, low, high):
    if low < high:
        # Partition the array
        pi = partition(arr, low, high)
        
        # Recursively sort the sub-arrays
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)

function partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    
    for j from low to high - 1:
        if arr[j] <= pivot:
            i = i + 1
            swap(arr[i], arr[j])
    
    swap(arr[i + 1], arr[high])
    return i + 1
