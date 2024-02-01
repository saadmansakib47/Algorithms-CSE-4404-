#include <iostream>
using namespace std;

void countingSort(int arr[], int n)
{

    int maxElement = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
        }
    }

    // each element count store korar jonno array
    int* count = new int[maxElement + 1]();
    for (int i = 0; i < n; ++i)
    {
        count[arr[i]]++;
    }

    // store cumulative count
    for (int i = 1; i <= maxElement; ++i)
    {
        count[i] += count[i - 1];
    }

    // temporary arrayte sorted result store korlam
    int* result = new int[n];
    for (int i = n - 1; i >= 0; --i)
    {
        result[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // sorted result original arrayte copy korlam
    for (int i = 0; i < n; ++i)
    {
        arr[i] = result[i];
    }

    delete[] count;
    delete[] result;//freeing memory
}

int main()
{
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    int* arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << "Original Array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }

    countingSort(arr, n);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }

    delete[] arr; //freeing memory

    return 0;
}

