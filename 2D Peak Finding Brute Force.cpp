#include <iostream>
using namespace std;

// Function to find all peak elements in a 2D array using brute force
void findPeaks2D(int arr[][100], int rows, int cols) {
    cout << "Peak elements are at indices: \n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            bool isPeak = true;

            // Check if arr[i][j] is greater than its neighbors
            if (i > 0 && arr[i - 1][j] > arr[i][j])
                isPeak = false;
            if (i < rows - 1 && arr[i + 1][j] > arr[i][j])
                isPeak = false;
            if (j > 0 && arr[i][j - 1] > arr[i][j])
                isPeak = false;
            if (j < cols - 1 && arr[i][j + 1] > arr[i][j])
                isPeak = false;

            // If arr[i][j] is a peak, print its indices
            if (isPeak) {
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

    // Find and print all peak elements in the 2D array
    findPeaks2D(arr, rows, cols);

    return 0;
}

