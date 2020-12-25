#include <iostream>
using namespace std;

void sort(int arr[], int size, int node)
{
    const int max = 10;
    int output[size];
    int count[max];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < size; i++)
        count[(arr[i] / node) % 10]++;

    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / node) % 10] - 1] = arr[i];
        count[(arr[i] / node) % 10]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];

    for (int node = 1; max / node > 0; node *= 10)
        sort(arr, size, node);
}

int main()
{
    int arr[] = {24, 756, 34, 23, 7, 443, 232, 442};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
