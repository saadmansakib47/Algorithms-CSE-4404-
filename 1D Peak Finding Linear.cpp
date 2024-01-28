#include <iostream>
using namespace std;

// Function to find all peak elements in a 1D array
void findPeaks(int arr[], int size, int peakIndices[], int& peakCount)
{
    for (int i = 0; i < size; ++i)
    {
        // Check if arr[i] is a peak
        if ((i == 0 || arr[i - 1] <= arr[i]) && (i == size - 1 || arr[i + 1] <= arr[i]))
        {
            peakIndices[peakCount++] = i;
        }
    }
}

int main()
{
    int size;

    // Get the size of the array from the user
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    // Get array elements from the user
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    const int maxPeaks = 100; // Choose a maximum size for the array
    int peakIndices[maxPeaks];
    int peakCount = 0;

    // Find all peak elements
    findPeaks(arr, size, peakIndices, peakCount);

    // Display all peak elements
    if (peakCount == 0)
    {
        cout << "No peak element found in the array.\n";
    }
    else
    {
        cout << "Peak elements are at indices: ";
        for (int i = 0; i < peakCount; ++i)
        {
            cout << peakIndices[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
