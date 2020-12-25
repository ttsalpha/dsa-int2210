//Tran The Son 18021105 DSA
//hello -> olleh | save to rev.txt
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string A;
    getline(cin, A);

    ofstream outFile("rev.txt");
    for (int i = A.size() - 1; i >= 0; i--)
    {
        outFile << A[i];
    }
}