#include <iostream>
using namespace std;

// Function to find all peak elements in a 1D array using divide and conquer
void findPeaksDivideConquer(int arr[], int start, int end, int size, int peakIndices[], int& peakCount) {
    int mid = start + (end - start) / 2;

    // Check if mid is a peak
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == size - 1 || arr[mid + 1] <= arr[mid])) {
        peakIndices[peakCount++] = mid;
    }

    // If the element to the left is greater, search in the left subarray
    if (mid > 0 && arr[mid - 1] > arr[mid])
        findPeaksDivideConquer(arr, start, mid - 1, size, peakIndices, peakCount);

    // If the element to the right is greater, search in the right subarray
    if (mid < size - 1 && arr[mid + 1] > arr[mid])
        findPeaksDivideConquer(arr, mid + 1, end, size, peakIndices, peakCount);
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

    const int maxPeaks = 100; // Choose a maximum size for the array
    int peakIndices[maxPeaks];
    int peakCount = 0;

    // Find all peak elements
    findPeaksDivideConquer(arr, 0, size - 1, size, peakIndices, peakCount);

    // Display all peak elements
    if (peakCount == 0) {
        cout << "No peak element found in the array.\n";
    } else {
        cout << "Peak elements are at indices: ";
        for (int i = 0; i < peakCount; ++i) {
            cout << peakIndices[i] << " ";
        }
        cout << endl;
    }

    delete[] arr; // Don't forget to free the dynamically allocated memory

    return 0;
}
