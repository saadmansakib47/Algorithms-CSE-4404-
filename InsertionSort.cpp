#include <iostream>
using namespace std;

// Function to perform Insertion Sort on an array
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int size;
    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    // Get array elements from the user
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Perform Insertion Sort
    insertionSort(arr, size);

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Don't forget to free the dynamically allocated memory
    return 0;
}

