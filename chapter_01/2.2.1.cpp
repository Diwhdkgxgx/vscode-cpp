// 2.1	打印温度柱状图
// （1）问题描述
// 下图是某城市15天的气温变化曲线。其中标注为A的地方称为峰点，标记为B的地方称为谷点，而标记为C的地方称为崮。要求编写1个函数输入15天的气温，然后通过3个函数分别实现下述功能：
// （1）打印每天温度的柱状图（仅考虑温度为正值的情况）。
// （2）打印所有峰点的位置（该月的第几天）及峰值。如果没有，则打印没有峰值。
// （3）打印最长的崮的长度。只使用一重循环即可求出。

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

int i;

// 输入n个温度
void inputTemps(int temp[], int n)
{
    cout << "Please input the tempratures:\n";
    for (i = 0; i < n; i++)
    {
        cin >> temp[i];
    }
    cout << endl;
}

// 显示柱状图
void displayTemps(int temp[], int n)
{
    cout << "显示柱状图如下:\n";
    for (i = 0; i < n; i++)
    {
        cout << std::left << setw(8) << i + 1;
        for (size_t j = 0; j < temp[i]; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
}

// 显示月间温度中的所有峰值
void displayPeaks(int temp[], int n)
{
    int max(int a, int b);
    int max_day[30];
    int k = 0;
    for (i = 0; i < n - 2; i++)
    {
        if (temp[i + 1] > temp[i])
        {
            if (temp[i + 1] > temp[i + 2])
            {
                // i + 1 那天便是峰值， i+2才是那天真实的日期
                max_day[k] = i + 1;
                k++;
            }
            else
            {
                ;
            }
        }
        else
        {
            ;
        }
    }

    cout << "显示峰值如下:\n";
    for (i = 0; i < k; i++)
    {
        cout << "Max at day " << std::right << setw(2) << max_day[i] + 1 << " is " << temp[max_day[i]] << "\n";
    }
}

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// 显示月间持续最久的温度
void displayFlat(int temp[], int n)
{
    int long_day[30] = {1};
    int d = 0, k = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (temp[i + 1] == temp[i])
        {
            long_day[d]++;
            if (long_day[0] < long_day[d])
            {
                long_day[0] = long_day[d];
            }
        }
        else
        {
            d++;
            long_day[d]++;
        }
    }

    cout << "显示崮的长度如下：\n";
    cout << "The length of the longest flat is " << long_day[0];
    cout << endl;
}

// 显示带有零下温度的柱状图
void displayMinusTemps(int temp[], int n)
{
    int m = 0;
    int a, j, k;

    for (i = 0; i < n; i++)
    {
        if (temp[i] < 0)
        {
            if (temp[i + 1] < 0)
            {
                m = max(fabs(temp[i]), fabs(temp[i + 1]));
            }
            else
            {
                m = fabs(temp[i]);
            }
        }
        else
        {
            if (m != 0)
            {
                m = m;
            }
        }
    }

    cout << "显示柱状图如下:\n";

    for (i = 0; i < n; i++)
    {
        // cout << setw(3) << temp[i] << " ";
        cout << setw(3) << i + 1 << "     ";
        if (temp[i] >= 0)
        {
            for (j = 0; j < m; j++)
            {
                cout << " ";
            }
            cout << "|";
            for (k = 0; k < temp[i]; k++)
            {
                cout << "*";
            }
        }
        else
        {

            for (j = 0; j < m - fabs(temp[i]); j++)
            {
                cout << " ";
            }
            for (k = 0; k < fabs(temp[i]); k++)
            {
                cout << "*";
            }
            cout << "|";
        }
        cout << "\n";
    }
}

// 求出现次数最多的温度，和次数
void displayCountMaxTemps(int temp[], int n)
{
    bool cmp(int a, int b);
    int count[n][2];
    int d = 0;
    int k = 0;
    sort(temp, temp + n, cmp);

    for (i = 0; i < n; i++)
    {
        if (temp[i] == temp[i + 1])
        {
            k++;
        }
        else
        {
            k++;
            count[d][1] = k;       // 保存出现多少次
            count[d][0] = temp[i]; // 保存是谁出现这么多次，可以用二维数组啊傻瓜
            d++;
            k = 0;
        }
    }

    int b[30][2];
    b[0][1] = 0;
    k = 0;

    for (i = 0; i < d; i++)
    {
        if (count[i][1] > b[0][1])
        {
            b[0][1] = count[i][1];
            b[0][0] = count[i][0];
            k = 0;
        }
        else if (count[i][1] == b[0][1])
        {
            k++;
            b[k][1] = count[i][1];
            b[k][0] = count[i][0];
            
        }
    }
    
    // if (k == 0)
    // {
    //     k = 1;
    // }
    
    //11 12 13 11 11 11 11 10 9 13 13 11 16 14 15
    cout << endl;
    for (i = 0; i < k + 1; i++)
    {
        cout << "出现最多的温度为：" << b[i][0] << " 出现的次数为：" << b[i][1] << "\n";
    }
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int temps[30];
    int m = 15;
    inputTemps(temps, m);
    // displayTemps(temps, m);
    // displayPeaks(temps, m);
    // displayFlat(temps, m);

    displayMinusTemps(temps, m);
    displayCountMaxTemps(temps, m);

    return 0;
}

//11 12 13 -11 11 11 11 10 -9 -13 13 11 16 14 -15