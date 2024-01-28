/*A greedy approach for 2D peak finding involves moving
to the neighbor with the maximum value until a peak is reached*/

#include <iostream>
using namespace std;

// Function to find a peak element in a 2D array using a greedy approach
int findPeak2DGreedy(int arr[][100], int row, int col, int rows, int cols) {
    int maxRowIndex = row;
    int maxCol = col;

    // Check the top neighbor
    if (row > 0 && arr[row - 1][col] > arr[maxRowIndex][maxCol]) {
        maxRowIndex = row - 1;
        maxCol = col;
    }

    // Check the bottom neighbor
    if (row < rows - 1 && arr[row + 1][col] > arr[maxRowIndex][maxCol]) {
        maxRowIndex = row + 1;
        maxCol = col;
    }

    // Check the left neighbor
    if (col > 0 && arr[row][col - 1] > arr[maxRowIndex][maxCol]) {
        maxRowIndex = row;
        maxCol = col - 1;
    }

    // Check the right neighbor
    if (col < cols - 1 && arr[row][col + 1] > arr[maxRowIndex][maxCol]) {
        maxRowIndex = row;
        maxCol = col + 1;
    }

    // If no neighbor is greater, (row, col) is a peak
    if (maxRowIndex == row && maxCol == col)
        return arr[row][col];
    // Move to the neighbor with the maximum value
    else
        return findPeak2DGreedy(arr, maxRowIndex, maxCol, rows, cols);
}

// Function to find all peak elements in a 2D array using a greedy approach
void findPeaks2DGreedy(int arr[][100], int rows, int cols) {
    cout << "Peak elements are at indices: \n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int peakValue = findPeak2DGreedy(arr, i, j, rows, cols);

            // Print the indices if the current element is a peak
            if (peakValue == arr[i][j]) {
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

    // Find and print all peak elements in the 2D array using a greedy approach
    findPeaks2DGreedy(arr, rows, cols);

    return 0;
}

