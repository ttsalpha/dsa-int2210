#include <iostream>

using namespace std;

void findSub(int a[], int l[], int b[], int n, int index)
{
    if (index == 0)
        return;
    l[n + 1] = 1;
    for (int i = n; i >= 0; i--)
    {
        //Chọn trong các chỉ số j sao cho a[j]>a[i] ra j_max với l[j_max] lớn nhất
        int j_max = n + 1;
        for (int j = i + 1; j <= n + 1; j++)
        {
            if (a[j] > a[i] && l[j] > l[j_max])
                j_max = j;
        }
        l[i] = l[j_max] + 1; //Lưu độ dài dãy con tăng dài nhất bắt đầu tại a[i]
        b[i] = j_max;        //Phần tử dứng liên sau a[i] trong dãy con tăng dài nhất là a[j_max]
    }
    index--;
    findSub(a, l, b, n, index);
}

int main()
{
    int n;
    cin >> n;
    int a[n + 2], l[n + 2], b[n];
    a[0] = -2147483648;
    a[n + 1] = 2147483647;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
    }
    int index = n;
    findSub(a, l, b, n, index);

    //truy vết theo mảng b[n]
    int i = b[0];
    while (i != n + 1)
    {
        cout << a[i] << " ";
        i = b[i];
    }
}
