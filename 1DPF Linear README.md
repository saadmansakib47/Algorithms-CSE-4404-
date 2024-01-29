# 1D Peak Finding - Linear Approach

## Problem Description

The 1D Peak Finding problem involves finding any peak element in a one-dimensional array. A peak element is an element that is greater than or equal to its neighbors. The linear approach for 1D Peak Finding involves scanning the array from left to right and identifying any element that satisfies the peak condition.

## Linear Approach

The linear approach ensures that at least one peak element is found because, during the scan, the algorithm will identify the first element that is greater than or equal to its left neighbor. In the worst case, the peak element may be the last element in the array.

### General Idea

1. Start scanning the array from the leftmost element.
2. Check each element in the array.
3. If the current element is greater than or equal to its neighbors (if they exist), it is a peak element.
4. Return the index of the first peak element found.

### Pseudocode

```plaintext
function findPeakLinear(arr):
    for i from 0 to length(arr) - 1:
        if (i == 0 or arr[i - 1] <= arr[i]) and (i == length(arr) - 1 or arr[i + 1] <= arr[i]):
            return i

## Time Complexity :
O(n), where n is the size of the array.
