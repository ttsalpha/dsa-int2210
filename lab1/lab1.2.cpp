//Tran The Son 18021105 DSA
//input A B C D from point.txt | check intersect AB and CD
#include <iostream>
#include <fstream>

using namespace std;

struct Point
{
    double x, y;
    Point() {}
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    //Point(const Point& other) {}
};

struct Line
{
    Point start;
    Point end;
    Line(Point _start, Point _end)
    {
        start = _start;
        end = _end;
    }
};

void check(Line L1, Line L2)
{
    double a1 = (L1.end.y - L1.start.y) / (L1.end.x - L1.start.x);
    double a2 = (L2.end.y - L2.start.y) / (L2.end.x - L2.start.x);

    double b1 = L1.end.y - a1 * L1.start.x;
    double b2 = L2.end.y - a2 * L2.start.x;

    if (a1 == a2 && b1 == b2)
        cout << "two overlap line"; //test 0 0 1 0 2 0 3 0
    else if (a1 == a2 && b1 != b2)
        cout << "two parallel line"; //test 0 0 1 0 0 1 1 1
    else
        cout << "two intersect line"; //test 1 2 3 1 0 0 3 3
}

int main()
{
    double x1, x2, y1, y2, x3, y3, x4, y4;
    ifstream inFile("point.txt");
    inFile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    Point A(x1, y1), B(x2, y2);
    Point C(x3, y4), D(x4, y4);
    Line L1(A, B), L2(C, D);

    check(L1, L2);
    return 0;
}