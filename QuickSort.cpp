#include <iostream>
using namespace std;

// Function to partition the array and return the index of the pivot element
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; ++j) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            // Swap arr[i] and arr[j]
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    // Swap arr[i+1] and arr[high] (pivot)
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform Quick Sort on an array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the index of the pivot
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays on both sides of the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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

    // Perform Quick Sort
    quickSort(arr, 0, size - 1);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Don't forget to free the dynamically allocated memory

    return 0;
}

