#include <iostream>

using namespace std;

// Function to perform Bubble Sort on an array
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
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

    // Perform Bubble Sort
    bubbleSort(arr, size);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Don't forget to free the dynamically allocated memory

    return 0;
}

