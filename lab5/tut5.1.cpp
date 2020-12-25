#include <iostream>

int find(int arr[], int n)
{
    if (n == 0)
        return -1;
    if (n == 1)
        return arr[0];
    int max = find(arr, n - 1);
    if (max < arr[n - 1])
        return arr[n - 1];
    return find(arr, n - 1);
}

int main()
{
    int arr[] = {3, 7, 9, 6, 5, 3, 10, 0};
    std::cout << find(arr, 8);
}