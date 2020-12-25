//Tran The Son 18021105 DSA
//find GCD
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    else
        return gcd(b - a, a);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}