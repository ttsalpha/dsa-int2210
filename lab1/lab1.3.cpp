//Tran The Son 18021105 DSA
//sum of complex numbers from file numbers.txt
#include <iostream>
#include <fstream>

using namespace std;

struct Complex
{
    double real;
    double image;
    Complex(double _real, double _image)
    {
        real = _real;
        image = _image;
    }
};

int main()
{
    double r, i;
    Complex sum(r, i);
    ifstream inFile("complex.txt");
    while (!inFile.eof())
    {
        inFile >> r;
        inFile >> i;
        sum.real += r;
        sum.image += i;
    }
    cout << sum.real << " + " << sum.image << " i ";
    return 0;
}