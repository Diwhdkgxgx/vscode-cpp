#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 计算两矩阵相乘，某行某列的结果
long long cal(long long **R, long long **copy_R, int n, int hang, int lie)
{
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += copy_R[hang][i] * R[i][lie];
    }
    return ans;
}

// 矩阵输出函数
void print(long long **copy_R, int n)
{
    for ( int i = 0; i < n ; i++)
    {
        for ( int j = 0; j < n ; j++)
        {
            cout << copy_R[i][j] << " ";
        }
        cout << endl;
    } 
}

int main()
{
    srand((int)time(0));
    int i, j, n;
    int mi, m;

    // cin >> n >> mi;
    cout << "输入矩阵的行列数n：";
    cin >> n;

    cout << "输入求几次幂：";
    cin >> mi;
    mi = mi - 1;

    long long *R[n];
    long long *copy_R[n];
    long long new_R[n][n];

    // 随机生成矩阵
    for ( i = 0; i < n ; i++)
    {
        R[i] = new long long [n];  
        copy_R[i] = new long long [n]; 
        for ( j = 0; j < n ; j++)
        {
            R[i][j] = rand() % 2;
            copy_R[i][j] = R[i][j];
        }
    }

    cout << "随机生成的矩阵为：" << endl;
    print(copy_R, n);
    cout << "-----------------------" << endl;


    int hang, lie;
    for ( m = 0; m < mi; m++)
    {
        for ( hang = 0; hang < n ; hang++)
        {
            for ( lie = 0; lie < n ; lie++)
            {
                new_R[hang][lie] = cal(R, copy_R, n, hang, lie);
            }
        }

        for ( i = 0; i < n ; i++)
        {
            for ( j = 0; j < n ; j++)
            {
                copy_R[i][j] = new_R[i][j];
            }
        }
    }
    

    // 输出
    cout << "结果为：" << endl;
    print(copy_R, n);

    return 0;
}
