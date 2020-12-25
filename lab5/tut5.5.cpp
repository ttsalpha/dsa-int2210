#include <iostream>
#include <cmath>

using namespace std;

int swap(int a, int v)
{
    if (v == 0)
        return a;
    int tmp = (int)log10(a);
    tmp = (int)pow(10, tmp);
    int b = (a % tmp) * 10 + a/tmp;
    cout << b << endl;
    return swap(b, v - 1);
}

int main()
{
    int n = 6;
    int arr[] = {1, 2, 3, 4, 5, 6};
    int A = 0;
    for (int i = 0; i < n; i++)
    {
        A *= 10;
        A += arr[i];
    }
    int v = 3;
    cout << swap(A, v);
}