//Tran The Son 18021105 DSA
//sum of max and min
#include <iostream>

using namespace std;

int main()
{
    double a[5];
    cin >> a[0];
    double max = a[0], min = a[0];
    for (int i = 1; i < 5; i++)
    {
        cin >> a[i];
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    cout << max + min;
}