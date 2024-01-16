#include <iostream>
using namespace std;

void MySwapValue(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;

    // 구조체, 컨테이너 사용 가능
}

void MySwapPtr(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void MySwapRef(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

bool CheckSorted(int x, int y)
{
    return (x <= y);
}

int main()
{
    {
        // swap
        int a = 3;
        int b = 2;

        cout << a << " " << b << endl;

        // MySwapValue(a, b);
        std::swap(a, b);

        MySwapPtr(&a, &b);

        MySwapRef(a, b);

        cout << a << " " << b << endl;
    }

    {
        // sorting
        int arr[2];

        for (int j = 0; j < 5; j++)
            for (int i = 0; i < 5; i++) {
                arr[0] = i;
                arr[1] = j;

                if (arr[0] > arr[1])
                    swap(arr[0], arr[1]);

                cout << boolalpha;
                cout << arr[0] << " " << arr[1] << " "
                     << CheckSorted(arr[0], arr[1]) << endl;
            }
    }

    return 0;
}