//Tran The Son 18021105 DSA
#include <iostream>
#include <cmath>
using namespace std;

int log(int a)
{
    int count = 0;
    while (a > 0)
    {
        count++;
        a /= 10;
    }
    return count / 2;
}

int check(int n1, int n2)
{
    if (log(n1) > log(n2))
        return log(n1);
    else
        return log(n2);
}

int karatsuba(int n1, int n2)
{
    if (n1 < 100 || n2 < 100)
        return n1 * n2;

    int x = pow(10, check(n1, n2));

    int a = n1 / x;
    //cout << a << endl;
    int b = n1 % x;
    //cout << b << endl;
    int c = n2 / x;
    //cout << c << endl;
    int d = n2 % x;
    //cout << d << endl;

    int t1 = karatsuba(a, c);
    int t2 = karatsuba(b, d);
    int t3 = karatsuba((a + b), (c + d));
    int t4 = t3 - t2 - t1;
    return t1 * 10000 + t2 + t4 * 100;
}

int main()
{
    int n1, n2;
    cout << "The input is two integers greater than 0\n";
    cin >> n1 >> n2;
    cout << karatsuba(n1, n2);
    return 0;
}