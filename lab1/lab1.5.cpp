//Tran The Son 18021105 DSA
//sort array numbers
//test 2 5 8 0 5 3 23 7 7 53 2 33 
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void sort(vector<double> &A)
{
    for (int i = 0; i < A.size() - 1; i++)
        for (int j = i; j < A.size() - 1; j++)
            if (A[i] > A[j])
            {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
}

int main()
{
    vector<double> A(0, 0);
    ifstream inFile("numbers.txt");
    int tmp;
    while (!inFile.eof())
    {
        inFile >> tmp;
        A.push_back(tmp);
    }

    sort(A);

    ofstream outFile("numbers.txt");
    for (int i = 0; i < A.size() - 1; i++)
    {
        outFile << A[i] << " ";
    }

    inFile.close();
    outFile.close();
}