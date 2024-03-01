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

int Count(char* arr, int size, char num)
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

void InsertionSort(char* arr, int n)
{
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
}

int main()
{
    // 문제
    // - 어떤 알파벳에 몇 번 나오는지로 출력
    // - 예시) aaabbccdddeeeff -> a3b2c2d3e3f2
    // - 알파벳은 총 26글자

    // cout << int('a') << " " << int('z') << endl; // 97 122

    // char arr[] = "ababcdfdceeefda";
    // char arr[] = "a";
    char arr[] = "ababcdfdceeedag";
    int n = sizeof(arr) - 1; // 마지막 안보이는 '\0' 제외

    // 글자가 하나 이상이라고 가정
    // 글자가 없으면 if로 아예 수행을 안하도록 처리 가능
    assert(n >= 1);

    cout << arr << endl;

    // 풀이 1. 모든 알파벳에 대해서 Count()
    // 힌트 : 소문자 알파벳 'a'~'z'는 int로는 97~122에 대응
    // 단점 : 없는 알파벳도 세야 한다.

    // 표를 사용할 수도 있고 사용하지 않을 수도 있음
    int table[26] = {0};

    for (int i = 0; i < 26; i++)
    {
        // 힌트 : char(i + 97)

        // 표를 만들고 나중에 몰아서 출력하는 방법
        table[i] = Count(arr, n, char(i + 97));

        // 표를 만들지 않고 직접 출력하는 방법
        int count = Count(arr, n, char(i + 97));
        if (count > 0) {
            cout << char(i + 97) << table[i] << flush;
        }
    }

    cout << endl;

    for (int i = 0; i < 26; i++)
    {
        if (table[i] > 0) {
            cout << char(i + 97) << table[i];
        }
    }

    // 풀이 2. 정렬 후 찾기
    // 여기서는 별도의 문자열을 만드는 것이 아니라 출력이 목표
    // Table도 만들지 않음

    InsertionSort(arr, n);

    cout << arr << endl;

    char c = arr[0];
    int count = 1;

    cout << c;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == c)
        {
            count++;
        }
        else
        {
            cout << count;
            c = arr[i];
            count = 1;

            cout << c;
        }
    }

    cout << count << endl;

    return 0;
}