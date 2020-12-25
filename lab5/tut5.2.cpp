#include <iostream>

int multi(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    if (a == 1)
        return b;
    return multi(a - 1, b) + b;
}

int divide(int a, int b)
{
    if (b == 0)
        return -1;
    if (a < b)
        return 0;
    return divide(a - b, b) + 1;
}

int main()
{
    int x = 35, y = 5, z = 6;
    // std::cout << multi(y, z);
    std::cout << divide(x, y);
}