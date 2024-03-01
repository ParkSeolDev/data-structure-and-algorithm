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

// 배열 arr에 x가 몇 번 나오는지 반환
int Count(int* arr, int size, int num)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (num == arr[i])
        {
            count++;
        }
    }
    return count;
}

// 배열 arr에 x가 있으면 index 반환, 없으면 -1 반환
int SequentialSearch(int* arr, int size, int num)
{
    // Horowitz
    int i;
    for (i = 0; i < size && arr[i] != num; i++){/* Do Nothing */};
    if (i == size)
        return -1;
    else
        return i;

    /*
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (num == arr[i])
        {
            index = i;
            break;
        }
    }
    return index;
    */
}

int SortedCountHelper(int* arr, int n, int x, int start)
{
    int count = 0;
    for (int i = start; i < n; i++)
    {
        if (arr[i] == x)
            count++;
        else
            break; // 조기 종료
    }

    return count;
}

int SortedCount(int* arr, int n, int x)
{
    int i = SequentialSearch(arr, n, x);

    if (i >= 0)
        return SortedCountHelper(arr, n, x, i + 1) + 1;
    else
        return 0;
}

void InsertionSort(int* arr, int n)
{
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

int main()
{
    // 정렬되지 않은 데이터를 가정
    int arr[] = {8, 1, 1, 3, 2, 5, 1, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Count 9 = " << Count(arr, n, 9) << endl;
    cout << "Count 2 = " << Count(arr, n, 2) << endl;
    cout << "Count 8 = " << Count(arr, n, 8) << endl;
    cout << "Count 1 = " << Count(arr, n, 1) << endl;
    cout << endl;

    cout << "Search 2 = " << SequentialSearch(arr, n, 2) << endl;
    cout << "Search 5 = " << SequentialSearch(arr, n, 5) << endl;
    cout << "Search 9 = " << SequentialSearch(arr, n, 9) << endl;
    cout << endl;

    InsertionSort(arr, n);
    cout << "Sorted Count 9 = " << SortedCount(arr, n, 9) << endl;
    cout << "Sorted Count 2 = " << SortedCount(arr, n, 2) << endl;
    cout << "Sorted Count 8 = " << SortedCount(arr, n, 8) << endl;
    cout << "Sorted Count 1 = " << SortedCount(arr, n, 1) << endl;
    cout << endl;
}