# Bubble Sort

## Overview

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

## Algorithm Steps:

1. **Start**: Begin the sorting process.

2. **Iterate Through List**: For each element in the list, starting from the first element, compare it with the next element.

3. **Swap if Necessary**: If the current element is greater than the next element, swap them.

4. **Continue Iterating**: Continue this process for each pair of adjacent elements in the list.

5. **One Pass Completed**: After completing one pass through the list, the largest unsorted element is now at the end.

6. **Repeat**: Repeat steps 2-5 for the remaining unsorted portion of the list.

7. **Completion**: Continue the process until the entire list is sorted.

##  Time Complexity : 
O(n^2) in the worst case, where n is the number of elements in the array.

## Pseudocode

```plaintext
function bubbleSort(arr):
    n = length(arr)
    
    for i from 0 to n - 1:
        for j from 0 to n - i - 1:
            # Compare adjacent elements and swap if necessary
            if arr[j] > arr[j + 1]:
                swap(arr[j], arr[j + 1])
