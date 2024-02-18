# Bucket Sort

## Overview

Bucket Sort is a distribution-based sorting algorithm that divides the input array into a number of buckets. Each bucket is then sorted individually, either using a different sorting algorithm or by applying the bucket sort recursively. After sorting all the elements within the buckets, the sorted elements are concatenated to produce the final sorted array.

## Algorithm Steps

1. **Bucket Creation**: Create an array of buckets. The number of buckets can be determined based on the range of elements in the input array.

2. **Distribution**: Distribute the elements of the input array into the buckets based on a certain criteria. In this implementation, we use the value of each element divided by 10 to determine the bucket index.

3. **Sort Buckets**: Sort each bucket individually. In this implementation, we use the insertion sort algorithm to sort the elements within each bucket.

4. **Concatenate Buckets**: Concatenate the sorted elements of all buckets back into the original array.

## Time Complexity

The time complexity of Bucket Sort depends on the method used to sort the elements within each bucket. In this implementation, we use insertion sort to sort the elements within each bucket, resulting in an average-case time complexity of O(n^2) in the worst-case scenario, where n is the number of elements in the input array. However, the time complexity can be improved to O(n + k) if a different sorting algorithm with a better time complexity is used for sorting the buckets.

## Pseudocode

```plaintext
function bucketSort(arr):
    max_val = findMax(arr, n)
    num_buckets = max_val / 10 + 1
    
    create buckets array of size num_buckets
    
    distribute elements into buckets
    for each element in arr:
        determine bucket index
        add element to bucket
    
    sort elements within each bucket
    for each bucket:
        insertionSort(bucket)
    
    concatenate buckets back into original array
