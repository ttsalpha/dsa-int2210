#include <iostream>
#include <fstream>

using namespace std;

static const int MAX = 500;
int array[MAX];
int length = 0; //The size of array;

int *newArray(char *filename, int &length)
{
    fstream file;
    file.open(filename);
    while (!file.eof())
    {
        file >> array[length];
        length++;
    }
    file.close();
    return array;
}

void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
}

int *insertNum(int array[], int &length, int value, int index)
{
    if (index < 0 || index > length)
        return array;
    for (int i = length - 1; i >= index; i--)
    {
        array[i + 1] = array[i];
    }
    array[index] = value;
    length++;
    return array;
}

int *removeIndex(int array[], int &length, int index)
{
    if (index < 0 || index > length)
        return array;
    for (int i = index; i < length; i++)
    {
        array[i] = array[i + 1];
    }
    length--;
    return array;
}

int findIndex(int array[], int length, int value)
{
    for (int i = 0; i < length; i++)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}

int main()
{
    newArray("input.txt", length);
    printArray(array, length);

    cout << endl
         << "After insert 12 to the array at 3: ";
    insertNum(array, length, 12, 3);
    printArray(array, length);

    cout << endl
         << "Array after remove an element at 4: ";
    removeIndex(array, length, 4);
    printArray(array, length);

    cout << endl
         << "Find the first index of 23: ";
    int tmp = findIndex(array, length, 23);
    if (tmp != -1)
        cout << tmp;
    else
        cout << "Not found ";
    return 0;
}