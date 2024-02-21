#include <iostream>
#include <cassert>
using namespace std;

struct Element {
    int key;
    char value;
};

bool CheckSorted(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }

    return true;
}

void SwapRef(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void Print(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void PrintElement(Element* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i].key << " ";
        cout << arr[i].value << " ";
    }
    cout << endl;
}

int main()
{
    {
        // 3개 sorting
        for (int k = 0; k < 3; k++)
            for (int j = 0; j < 3; j++)
                for (int i = 0; i < 3; i++) {
                    int arr[3] = {i, j, k};
                    int size = sizeof(arr) / sizeof(arr[0]);

                    for (int e = 0; e < size; e++)
                    {
                        cout << arr[e] << " " << flush;
                    }

                    cout << " -> " << flush;

                    if (arr[0] > arr[1])
                        swap(arr[0], arr[1]);

                    if (arr[1] > arr[2])
                        swap(arr[1], arr[2]);

                    if (arr[0] > arr[1])
                        swap(arr[0], arr[1]);

                    for (int e = 0; e < size; e++)
                    {
                        cout << arr[e] << " " << flush;
                    }
                    

                    cout << boolalpha;
                    cout << CheckSorted(arr, size);
                    cout << endl;
                }
    }

    {
        // 가장 작은 수 찾기
        {
            int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
            int size = sizeof(arr) / sizeof(arr[0]);

            assert(size > 0);

            int min_number = arr[0];
            for (int i = 1; i < size; i++)
            {
                min_number = arr[i] < min_number ? arr[i] : min_number;
                // min_number = std::min(arr[i], min_number);
            }

            cout << "Minimum number is " << min_number << endl;
        }

        // 가장 작은 수의 인덱스 찾기
        {
            int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
            int size = sizeof(arr) / sizeof(arr[0]);

            assert(size > 0);

            int min_index = 0;

            for (int i = 1; i < size; i++)
            {
                min_index = arr[min_index] < arr[i] ? min_index : i;
            }
            
            cout << "The index of min is " << min_index << endl;
            cout << "Minimum number is " << arr[min_index] << endl;
        }
    }

    {
        // Selection Sort
        {
            int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9};
            int size = sizeof(arr) / sizeof(arr[0]);

            Print(arr, size);

            int min_index = 0;

            for (int i = 0; i < size - 1; i++)
            {
                min_index = i;
                for (int j = i + 1; j < size; j++)
                {
                    min_index = arr[min_index] < arr[j] ? min_index : j;
                }
                swap(arr[min_index], arr[i]);

                Print(arr, size);

                cout << boolalpha;
                cout << CheckSorted(arr, size);
                cout << endl;
            }
        }
    }

    {
        // 안정성 확인 (unstable)
        Element arr[] = {{2, 'a'}, {2, 'b'}, {1, 'c'}};
        int size = sizeof(arr) / sizeof(arr[0]);

        PrintElement(arr, size);

        int min_index;
        for (int i = 0; i < size - 1; i++)
        {
            min_index = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j].key < arr[min_index].key)
                    min_index = j;
            }
            swap(arr[min_index], arr[i]);

            PrintElement(arr, size);
        }
        
    }
}