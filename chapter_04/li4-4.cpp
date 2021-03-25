// 类的组合
#include <cmath>
#include <iostream>
// #include <math.h>

using namespace std;

class Point
{
public:
    Point(int xx = 0, int yy = 0)
    {
        x = xx;
        y = yy;
    }
    Point(Point &p); // 复制构造函数
    int getX() { return x; }
    int getY() { return y; }

private:
    int x, y;
};

Point::Point(Point &p) // 复制构造函数的实现
{
    x = p.x;
    y = p.y;
    cout << " Calling the copy constructor of Point" << endl;
}

class Line
{
private:
    Point p1, p2; // 私有对象便是两个点的实例化
    double len;

public:
    Line(Point xp1, Point xp2); // 构造函数
    
    Line(Line &l);
    double getLen() { return len; }
    // ~Line();
};

Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) // 组合类的构造函数。  p1(xp1)的意思就是 p1 = xp1。
{
    double x = static_cast<double>(p1.getX() - p2.getX());
    double y = static_cast<double>(p1.getY() - p2.getY());
    len = sqrt(x * x  + y * y );
}

Line::Line(Line &l) : p1(l.p1), p2(l.p2) // 组合类的复制构造函数  p1(l.p1) 的意思就是 p1 = l.p1
{
    len = l.len;
}

int main()
{
    Point myp1(1, 1), myp2(4, 5);
    Line line(myp1, myp2);
    
    Line line2(line);

    cout << "ih du ui: ";
    cout << line.getLen() << endl;

    cout << "xm dr 2 de ih du ui: ";
    cout << line2.getLen() << endl;

    return 0;
}