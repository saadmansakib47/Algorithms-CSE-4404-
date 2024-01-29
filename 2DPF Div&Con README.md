# 2D Peak Finding - Divide and Conquer Approach

## Problem Description

The 2D Peak Finding problem involves finding any peak element in a two-dimensional array. A peak element is an element that is greater than or equal to its neighbors. The divide and conquer approach for 2D Peak Finding involves recursively dividing the matrix and searching for peaks in subproblems.

## Divide and Conquer Approach

The divide and conquer approach for 2D Peak Finding involves recursively dividing the matrix and searching for peaks in subproblems. Here is an overview:

1. **Divide the Matrix**: Divide the matrix into two halves along the middle column.

2. **Find Global Maximum in Middle Column**: Find the global maximum in the middle column.

3. **Check Peak Condition**: Check if the current element is greater than or equal to its neighbors.

4. **Return Peak**: If the condition is met, return the coordinates of the current element; otherwise, decide whether to search in the left or right submatrix based on the neighbor with a larger value.

## Time Complexity 
O(m * log n), where m is the number of rows and n is the number of columns in the 2D matrix

### Pseudocode

```plaintext
function find2DPeakDivideConquer(matrix):
    rows = length(matrix)
    cols = length(matrix[0])
    
    return findPeakDivideConquer(matrix, 0, cols - 1, rows)

# Helper function to perform the divide and conquer
function findPeakDivideConquer(matrix, start_col, end_col, rows):
    mid_col = (start_col + end_col) / 2
    
    # Find the global maximum in the middle column
    max_row = findMaxInColumn(matrix, mid_col)
    
    # Check if the current element is greater than or equal to its neighbors
    if (max_row == 0 or matrix[max_row - 1][mid_col] <= matrix[max_row][mid_col]) and
       (max_row == rows - 1 or matrix[max_row + 1][mid_col] <= matrix[max_row][mid_col]):
        return [max_row, mid_col]
    
    # Decide whether to search in the left or right submatrix
    if mid_col > 0 and matrix[max_row][mid_col - 1] > matrix[max_row][mid_col]:
        return findPeakDivideConquer(matrix, start_col, mid_col - 1, rows)
    else:
        return findPeakDivideConquer(matrix, mid_col + 1, end_col, rows)

# Helper function to find the row with the maximum value in a column
function findMaxInColumn(matrix, col):
    max_val = matrix[0][col]
    max_row = 0
    
    for i from 1 to length(matrix) - 1:
        if matrix[i][col] > max_val:
            max_val = matrix[i][col]
            max_row = i
    
    return max_row
