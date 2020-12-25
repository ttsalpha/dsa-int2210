#include <iostream>
using namespace std;

int N;

void insert(int A[], int value)
{
    N = N + 1;
    int i = N;
    A[i] = value;
    while (i > 1 && A[i / 2] > A[i])
    {
        swap(A[i / 2], A[i]);
        i = i / 2;
    }
}

void sort(int A[], int i)
{
    int min;
    int left = 2 * i;
    int right = 2 * i + 1;                                        
    if (left <= N && A[left] < A[i])
        min = left;
    else
        min = i;
    if (right <= N && A[right] < A[min])
        min = right;
    if (min != i)
    {
        swap(A[i], A[min]);
        sort(A, min);
    }
}

int pop(int A[])
{
    if (N == 0)
    {
        cout << "Queues null\n";
        return -1;
    }
    int max = A[1];
    A[1] = A[N];
    N = N - 1;
    sort(A, 1);
    return max;
}

void print(int A[])
{
    if (N <= 0)
        return;
    for (int i = 1; i <= N; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{
    N = 0;
    int A[10];

    int Input[] = {8, 4, 1, 7, 3, 6, 2};
    for (int i = 0; i < 7; i++)
    {
        insert(A, Input[i]);
    }

    for (int i = 0; i < 7; i++)
    {
        print(A);
        pop(A);
    }

    return 0;
}