#include <iostream>
#include <string>

using namespace std;

void Reverse(string s, int begin)
{
    if (begin != s.size())
    {
        Reverse(s, begin + 1);
        cout << s[begin];
    }
}

int main()
{
    string s;
    getline(cin, s);
    int begin = 0;
    Reverse(s, begin);
}