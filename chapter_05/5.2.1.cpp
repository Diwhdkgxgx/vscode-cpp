#include <iomanip>
#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

// 显示主菜单
void displayMenu()
{
    cout << "******************" << endl;
    cout << "     1.Circle" << endl;
    cout << "     2.Rectangle" << endl;
    cout << "     0.Exit" << endl;
    cout << "******************" << endl;
    cout << "Please select the shape: ";
}

// 得到用户输入的两个点
void getTwoPoints(struct Point *p1, struct Point *p2)
{
    cout << "Please input the coordinate (x, y) of the start point: ";
    cin >> p1->x >> p1->y;

    // 判断end是否大于start
    cout << "Please input the coordinate (x, y) of the end point: ";
    cin >> p2->x >> p2->y;
}

// 判断坐标是否符合要求
bool judgeEndP(struct Point *p1, struct Point *p2)
{
    if (p2->x <= p1->x || p2->y <= p1->y)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// 以（x，y）形式打印点
void printPoint(struct Point *)
{
}

// 画圆的函数
void drawCircle(struct Point *p1, struct Point *p2)
{
    // 判断坐标是否符合要求
    if (judgeEndP(p1, p2))
    {
        // 判断是否能围成圆形
        if (  (p2->x - p1->x)  == (p2->y - p1->y) )
        {
            cout << "Draw a circle at center (" << (p2->x + p1->x) / 2 << ", " << (p2->y + p1->y) / 2 << ") with radius " << (p2->x - p1->x) / 2;
        }
        else
        {
            cout << "Not a circle, Select again";
        }
        cout << endl;
    }
    else
    {
        cout << "start Point is bigger than the end point." << endl;
    }
}

// 画长方形的函数
void drawRectangle(struct Point *p1, struct Point *p2)
{
    if (judgeEndP(p1, p2))
    {
        cout << "Draw a rectangle at topleft (" << p1->x << ", " << p1->y << "), whose width is " << p2->x - p1->x << " and height is " << p2->y - p1->y;
        cout << endl;
    }
    else
    {
        cout << "start Point is bigger than the end point." << endl;
    }
}

int main()
{
    int choice;

    struct Point startP, endP;

    while (choice)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1: // 圆
            getTwoPoints(&startP, &endP);
            drawCircle(&startP, &endP);
            break;
        case 2: // 长方形
            getTwoPoints(&startP, &endP);
            drawRectangle(&startP, &endP);
            break;
        case 0:
            cout << "Good Bye!\n";
            break;
        default:
            cout << "Not supported! Please select again!\n";
            break;
        }
    }
    return 0;
}