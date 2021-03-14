// 游戏的规定走法是：
// （1）任意一个将牌可以移入相邻的空格；
// （2）任意一个将牌可相隔1个或2个其他的将牌跳入空格。
// 游戏要达到的目标是使所有白将牌都处在黑将牌的左边（左边有无空格均可），我们称为目标格局。
// WWWWBBEBB

#include <iostream>
#include <math.h>
using namespace std;

// B 0 E 1 W 2

int i, j, k;

void inputGeju(int ge[][11], int n)
{
    char a[10];
    for (i = 0; i < n; i++)
    {
        cin >> ge[i][0];
        cin >> a;

        for (j = 0; j < (2 * ge[i][0] + 2); j++)
        {
            if (a[j] == 'B')
            {
                ge[i][j + 1] = 0;
            }
            else if (a[j] == 'E')
            {
                ge[i][10] = j + 1; // 记录E的位置,放在第10位上
                ge[i][j + 1] = 1;
            }
            else if (a[j] == 'W')
            {
                ge[i][j + 1] = 2;
            }
        }
    }
    cout << endl;
}

void judgeGeju(int ge[][11], int n)
{
    void sortResult(int ge[][11], int result[][20], int d);
    void outputResult(int ge[][11], int result[][20], int d, int n, int count, int i);
    int result[50][20]; // 得到后续格局并储存
    int sum = 0;
    int k = 0;
    int t = 0;
    int d = 0;     // 后续格局计数器
    int count = 0; // 输出计数器
    int e;
    for (i = 0; i < n; i++)
    {
        count++;
        sum = 0;
        // 先判断是否为目标格局
        for (j = 1; j < ge[i][0] + 2; j++)
        {
            sum += ge[i][j];
        }
        if (sum < 2 * ge[i][0]) // 小于全是2的情况
        {
            ge[i][9] = 0; // 不是目标格局
        }
        else
        {
            ge[i][9] = 1; // 是目标格局， 第9位变为1
            // 输出result
            outputResult(ge, result, d, n, count, i);
            continue; // 判断完毕，结束本次循环
        }
        // 不是目标格局
        e = ge[i][10]; // 记录E的位次。
        int q;         // 计数器
        for (q = 1; q < 4; q++)
        {
            // E的右边交换
            if (e + q < 2 * ge[i][0] + 2)
            {
                t = ge[i][e + q];
                ge[i][e] = t;
                ge[i][e + q] = 1;
                for (j = 1; j < 2 * ge[i][0] + 2; j++)
                {
                    result[d][0] = i; // 第0位记录是哪个中间格局的后续格局
                    result[d][j] = ge[i][j];
                }
                d++;
                // 复原
                ge[i][e + q] = t;
                ge[i][e] = 1;
            }
            // E的左边交换
            if (e - q > 0)
            {
                t = ge[i][e - q];
                ge[i][e] = t;
                ge[i][e - q] = 1;
                for (j = 1; j < 2 * ge[i][0] + 2; j++)
                {
                    result[d][0] = i;
                    result[d][j] = ge[i][j];
                }
                d++;
                // 复原
                ge[i][e - q] = t;
                ge[i][e] = 1;
            }
        }

        // 给result去重排序。
        sortResult(ge, result, d);
        // 输出result
        outputResult(ge, result, d, n, count, i);
        
        d = 0;
    }
}

void sortResult(int ge[][11], int result[][20], int d)
{
    // 给result去重排序。
    // 先把每一个result相加，从小到大排列
    int ii;
    int w;
    for (ii = 0; ii < d; ii++)
    {
        w = result[ii][0]; // 获取此时是哪一个中间格局
        int sum;
        result[ii][10] = 0;
        for (j = 1; j < 2 * ge[w][0] + 2; j++)
        {
            result[ii][10] += pow(10, (2 * ge[w][0] + 2 - j)) * result[ii][j]; // 将所有数的相加结果放置到第10位
        }
    }

    // 根据result[][10]的大小，从小到大排序（冒泡）
    int ttt[100] = {0};
    for (ii = 0; ii < d - 1; ii++)
    {
        for (j = 0; j < d - 1 - ii; j++)
        {
            w = result[i][0];
            if (result[j][10] > result[j + 1][10])
            {
                // 两列结果交换
                // 先交换sum
                ttt[10] = result[j][10];
                result[j][10] = result[j + 1][10];
                result[j + 1][10] = ttt[10];
                // 再一次交换数值
                for (k = 1; k < 2 * ge[w][0] + 2; k++)
                {
                    ttt[k] = result[j][k];
                    result[j][k] = result[j + 1][k];
                    result[j + 1][k] = ttt[k];
                }
            }
        }
    }
}

void outputResult(int ge[][11], int result[][20], int d, int n, int count, int i)
{

    // 输出结果
    cout << "结果_" << count << endl;
    // 判断是否为目标格局
    if (ge[i][9] == 1) // 是目标格局
    {
        cout << "目标格局" << endl;
    }
    else
    {
        for (k = 0; k < d; k++)
        {
            for (j = 1; j < 2 * ge[i][0] + 2; j++)
            {
                if (result[k][j] == 0)
                {
                    cout << 'B';
                }
                else if (result[k][j] == 1)
                {
                    cout << 'E';
                }
                else if (result[k][j] == 2)
                {
                    cout << 'W';
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}

int main()
{

    int n;
    cin >> n;

    int ge_ju[n][11];

    inputGeju(ge_ju, n);

    judgeGeju(ge_ju, n);

    return 0;
}

/*测试样例
3
3 BBWBEWW
4 WWWWBBEBB
4 BBWWBEWWB
*/