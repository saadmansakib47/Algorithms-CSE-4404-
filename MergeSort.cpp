#include <iostream>

using namespace std;

// Function to merge two sorted subarrays into one sorted array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; ++i)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            ++i;
        } else {
            arr[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of leftArray[], if there are any
    while (i < n1) {
        arr[k] = leftArray[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < n2) {
        arr[k] = rightArray[j];
        ++j;
        ++k;
    }

    // Free the temporary arrays
    delete[] leftArray;
    delete[] rightArray;
}

// Function to perform Merge Sort on an array
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
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

    // Perform Merge Sort
    mergeSort(arr, 0, size - 1);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Don't forget to free the dynamically allocated memory

    return 0;
}

