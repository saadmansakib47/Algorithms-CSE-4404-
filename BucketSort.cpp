#include <iostream>
using namespace std;

// Function to find the maximum value in the array
int findMax(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort on an array
void bucketSort(int arr[], int n) {
    // Find the maximum value in the array
    int max_val = findMax(arr, n);

    // Create buckets based on the maximum value
    const int num_buckets = max_val / 10 + 1;
    int buckets[num_buckets][n]; // Array of buckets
    int bucket_sizes[num_buckets] = {0}; // Array to store sizes of buckets

    // Distribute elements into buckets
    for (int i = 0; i < n; ++i) {
        int bucket_index = arr[i] / 10; // Determine bucket index
        buckets[bucket_index][bucket_sizes[bucket_index]] = arr[i]; // Add element to bucket
        ++bucket_sizes[bucket_index]; // Increment bucket size
    }

    // Sort elements within each bucket using insertion sort
    for (int i = 0; i < num_buckets; ++i) {
        if (bucket_sizes[i] > 0) {
            insertionSort(buckets[i], bucket_sizes[i]);
        }
    }

    // Concatenate buckets back into original array
    int index = 0;
    for (int i = 0; i < num_buckets; ++i) {
        for (int j = 0; j < bucket_sizes[i]; ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int size;

    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    // Get array elements from the user
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Perform Bucket Sort
    bucketSort(arr, size);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Don't forget to free the dynamically allocated memory

    return 0;
}
