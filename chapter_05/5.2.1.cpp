// 2.1	模拟画图功能
// （1）问题描述
// 模拟计算机的画图功能，能够模拟画圆和长方形的功能。程序主要功能如下：
// ① 提供一个如下的主菜单。
// *******************************
// 1.  Circle (圆)
// 2.  Rectangle (长方形)
// 0.  Exit (退出)
// *******************************
// ② 不断接受用户的选择（整数），直至用户选择0为止。如果用户输入了系统尚未支持的选择（比如3），则给出相应的提示信息，并继续选择。
// ③ 如果用户选择了圆或长方形，则进一步提示用户输入两个点，分别称为起点和终点，如下图所示。坐标仅考虑正整数的情况。要求终点的坐标大于起点的坐标，否则给出相关的提示信息并返回主菜单。
 
// 图1. 显示屏的坐标系与起点、终点位置
// ④ 模拟画出圆和长方形。画圆时，要计算startPoint和endPoint所构成的正方形的内切圆的圆心和半径。若startPoint和endPoint所构成的不是正方形，则给出相关的提示信息并返回主菜单。
// （2）问题要求
// ① 定义一个Point结构体，用来表示显示屏上的点；
// ② 实现以下函数（图2），使得主程序（图3）输出图4中的结果。


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