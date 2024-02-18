# Radix Sort

## Overview

Radix Sort is a non-comparative sorting algorithm that sorts integers by processing individual digits of the numbers. It sorts the elements based on their radix (i.e., base) by grouping numbers with the same radix. Radix Sort can be implemented using any stable sorting algorithm as a subroutine for sorting each digit. In this implementation, we use the Counting Sort algorithm as the subroutine.

## Algorithm Steps

1. **Find Maximum Element**: Find the maximum element in the array to determine the number of digits in the largest element.

2. **Counting Sort for Each Digit**: Perform Counting Sort for each digit, starting from the least significant digit to the most significant digit. 

3. **Radix Sort**: Iterate over all digits, performing Counting Sort for each digit position. After processing all digits, the array becomes sorted.

## Time Complexity

The time complexity of Radix Sort is O(n * k), where n is the number of elements in the array and k is the number of digits in the maximum element. Since Counting Sort is used as a subroutine, its time complexity for each digit is O(n + k). Therefore, Radix Sort has linear time complexity under certain conditions.

## Pseudocode

```plaintext
function getMax(arr, n):
    maxElement = arr[0]
    for i from 1 to n-1:
        if arr[i] > maxElement:
            maxElement = arr[i]
    return maxElement

function countingSort(arr, n, exp):
    output = new array of size n
    count = new array of size 10, initialized to 0
    
    for i from 0 to n-1:
        count[(arr[i] / exp) % 10]++
    
    for i from 1 to 9:
        count[i] += count[i - 1]
    
    for i from n-1 down to 0:
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]
        count[(arr[i] / exp) % 10]--
    
    for i from 0 to n-1:
        arr[i] = output[i]

function radixSort(arr, n):
    maxElement = getMax(arr, n)
    
    for exp from 1 to maxElement, multiplied by 10:
        countingSort(arr, n, exp)
