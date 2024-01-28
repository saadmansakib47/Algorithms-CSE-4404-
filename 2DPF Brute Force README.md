# 2D Peak Finding - Brute Force Approach

## Problem Description

The 2D Peak Finding problem involves finding any peak element in a two-dimensional array. A peak element is an element that is greater than or equal to its neighbors. The brute force approach for 2D Peak Finding involves scanning the entire matrix and identifying any element that satisfies the peak condition.

## Brute Force Approach

The brute force approach for 2D Peak Finding involves scanning the entire matrix and identifying any element that satisfies the peak condition. Here is an overview:

1. Iterate through each element in the matrix.
2. Check if the current element is greater than or equal to its neighbors (if they exist).
3. If the current element satisfies the peak condition, it is a peak.
4. Return the coordinates of the first peak element found.

### Pseudocode

```plaintext
function find2DPeakBruteForce(matrix):
    rows = length(matrix)
    cols = length(matrix[0])
    
    for i from 0 to rows - 1:
        for j from 0 to cols - 1:
            # Check if the current element is greater than or equal to its neighbors
            if (i == 0 or matrix[i - 1][j] <= matrix[i][j]) and
               (i == rows - 1 or matrix[i + 1][j] <= matrix[i][j]) and
               (j == 0 or matrix[i][j - 1] <= matrix[i][j]) and
               (j == cols - 1 or matrix[i][j + 1] <= matrix[i][j]):
                return [i, j]
