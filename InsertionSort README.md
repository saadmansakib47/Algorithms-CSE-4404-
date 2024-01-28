# Insertion Sort

## Overview

Insertion Sort is a simple sorting algorithm that builds the final sorted array one element at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. However, it has several advantages: it is simple, efficient for small datasets, and adaptive.

## Algorithm Steps:

1. **Start**: Begin the sorting process.

2. **Iterate Through List**: For each element in the list, starting from the second element, compare it with the elements before it.

3. **Shift and Insert**: If the current element is smaller than the elements before it, shift those elements to the right and insert the current element in its correct position.

4. **Repeat**: Repeat steps 2-3 for each element in the list.

5. **Completion**: The entire list is now sorted.

## Pseudocode

```plaintext
function insertionSort(arr):
    n = length(arr)
    
    for i from 1 to n - 1:
        key = arr[i]
        j = i - 1
        
        # Shift and insert in correct position
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j = j - 1
        
        arr[j + 1] = key
