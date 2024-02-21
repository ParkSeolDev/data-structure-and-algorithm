#include <iostream>
#include <cassert>
using namespace std;

void Print(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    Print(arr, n);
    cout << endl;

    // Bubble Sort
    {
        for (int i = n; i >= 0; i--)
        {
            bool swapped = false;

            for (int j = 1; j < i; j++)
            {
                if (arr[j-1] > arr[j]) {
                    swap(arr[j - 1], arr[j]);
                    swapped = true;
                }

                Print(arr, n);
            }

            cout << endl;

            if (swapped == false)
                break;
        }
    }

    // Best case
    // Stability
}