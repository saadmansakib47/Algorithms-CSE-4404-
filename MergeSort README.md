# Merge Sort

## Overview

Merge Sort is a divide-and-conquer algorithm that divides the unsorted list into n sublists, each containing one element, and then repeatedly merges sublists to produce new sorted sublists until there is only one sublist remaining.

## Algorithm Steps:

1. **Divide**: Divide the unsorted list into n sublists, each containing one element.

2. **Merge Sublists**: Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining.

3. **Completion**: The final sorted list is now complete.

## Pseudocode

```plaintext
function mergeSort(arr):
    if length(arr) <= 1:
        return arr
    
    # Divide the array into two halves
    mid = length(arr) / 2
    left_half = arr[0:mid]
    right_half = arr[mid:]
    
    # Recursively apply mergeSort to each half
    left_half = mergeSort(left_half)
    right_half = mergeSort(right_half)
    
    # Merge the sorted halves
    return merge(left_half, right_half)

function merge(left, right):
    result = []
    i = j = 0
    
    # Merge the two sorted arrays
    while i < length(left) and j < length(right):
        if left[i] <= right[j]:
            result.push(left[i])
            i = i + 1
        else:
            result.push(right[j])
            j = j + 1
    
    # Append any remaining elements from both arrays
    result = result + left[i:]
    result = result + right[j:]
    
    return result
