//  Son Tran | ttsalpha
#include <iostream>

using namespace std;

void merge(int arr[], int left, int right, int middle)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (right > left)
    {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, right, middle);
    }
}

int main()
{
    int arr[] = {24, 756, 34, 23, 7, 443, 232, 442};
    mergeSort(arr, 0, 7);
    for (int i = 0; i < 8; ++i)
        std::cout << arr[i] << " ";
    return 0;
}