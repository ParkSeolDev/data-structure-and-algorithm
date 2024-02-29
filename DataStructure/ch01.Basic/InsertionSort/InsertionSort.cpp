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
    // 오른쪽으로 하나씩 밀기
    {
        int arr[] = {1, 2, 4, 5, 3, 6};
        int n = sizeof(arr) / sizeof(arr[0]);

        Print(arr, n);
        cout << endl;

        // i = 4부터 시작
        int i = 4;
        int key = arr[i];
        int j = i;
        for (; j > 0 && key < arr[j-1]; j--)
        {
            arr[j] = arr[j - 1];
        }

        // 삽입
        arr[j] = key;

        Print(arr, n);
        cout << endl;
    }

    // 삽입 정렬
    {
        int arr[] = {2, 1, 4, 5, 3, 6};
        int n = sizeof(arr) / sizeof(arr[0]);

        Print(arr, n);
        cout << endl;

        for (int i = 1; i < n; i++)
        {
            int key = arr[i];
            int j = i;

            for (; j > 0 && key < arr[j-1]; j--)
            {
                arr[j] = arr[j - 1];
            }

            arr[j] = key;
        }
        
        Print(arr, n);
        cout << endl;
    }
}