#include <iostream>
using namespace std;

// Function to find a peak element in a 2D array using divide and conquer
int findPeak2DDivideConquer(int arr[][100], int startRow, int endRow, int cols) {
    int midRow = startRow + (endRow - startRow) / 2;
    int maxCol = 0;

    // Find the global maximum in the middle column
    for (int j = 0; j < cols; ++j) {
        if (arr[midRow][j] > arr[midRow][maxCol]) {
            maxCol = j;
        }
    }

    // Check if arr[midRow][maxCol] is a peak
    if ((midRow == 0 || arr[midRow - 1][maxCol] <= arr[midRow][maxCol]) &&
        (midRow == endRow || arr[midRow + 1][maxCol] <= arr[midRow][maxCol])) {
        return arr[midRow][maxCol];
    }

    // If not, recursively search in the subarray with the higher value
    if (midRow > 0 && arr[midRow - 1][maxCol] > arr[midRow][maxCol]) {
        return findPeak2DDivideConquer(arr, startRow, midRow - 1, cols);
    } else {
        return findPeak2DDivideConquer(arr, midRow + 1, endRow, cols);
    }
}

// Function to find all peak elements in a 2D array using divide and conquer
void findPeaks2DDivideConquer(int arr[][100], int rows, int cols) {
    cout << "Peak elements are at indices: \n";
    for (int i = 0; i < rows; ++i) {
        int peakValue = findPeak2DDivideConquer(arr, 0, rows - 1, cols);

        // Print the indices if the current element is a peak
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] == peakValue) {
                cout << "(" << i << ", " << j << ")\n";
            }
        }
    }
}

int main() {
    int rows, cols;

    // Get the dimensions of the 2D array from the user
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int arr[100][100]; // Assuming a maximum size of 100x100, you can adjust this

    // Get array elements from the user
    cout << "Enter the elements of the 2D array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element at position (" << i << ", " << j << "): ";
            cin >> arr[i][j];
        }
    }

    // Find and print all peak elements in the 2D array using divide and conquer
    findPeaks2DDivideConquer(arr, rows, cols);

    return 0;
}

