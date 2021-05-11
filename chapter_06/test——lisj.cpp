#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define mod 1000000007
using namespace std;

const int N = 36;

struct matrix
{
    int x[N][N];
};

matrix Matrix_Multiply(matrix a, matrix b, int n, int m, int t) //实现矩阵乘法，输入两个矩阵必须合法， 前者 n 行 m 列，后者 m 行 t 列
{
    matrix c;
    int i, j, k;
    for (i = 0; i <= N; ++i)
        c.x[i][0] = c.x[0][i] = 0;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= t; ++j)
        {
            int sum = 0;
            for (k = 1; k <= m; ++k)
                sum += a.x[i][k] * b.x[k][j] % mod;
            c.x[i][j] = sum;
        }
    return c;
}

matrix mul2(matrix a, matrix b, int n) //两个 n 阶矩阵相乘时， 也可以用这个
{
    matrix c;
    int i, j, k;
    for (i = 0; i <= n; ++i)
        c.x[i][0] = c.x[0][i] = 0;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
        {
            int sum = 0;
            for (k = 1; k <= n; ++k)
                sum += a.x[i][k] * b.x[k][j];
            c.x[i][j] = sum;
        }
    return c;
}

matrix Matrix_fastpower(matrix a, int n, int m) //矩阵 a , 阶数 n , 指数 m
{
    matrix c;
    int i, j, k;
    for (i = 0; i <= n; ++i)
        for (j = 0; j <= n; ++j)
        {
            c.x[i][j] = 0;
            if (i == j)
                c.x[i][j] = 1;
        }
    if (m == 0)
        return c;
    if (m == 1)
        return a;
    while (m)
    {
        if (m & 1)
            c = mul2(a, c, n);
        a = mul2(a, a, n);
        m >>= 1;
    }
    return c;
}

matrix a, b, ans;

int main()
{
    int n, m, t, i, j, k, num;
    printf("1.矩阵乘法\n2.矩阵(方阵)快速幂\n请选择操作序号：\n");
    while (~scanf("%d", &num))
    {
        memset(a.x, 0, sizeof a.x);
        memset(b.x, 0, sizeof b.x);
        memset(ans.x, 0, sizeof ans.x);
        if (num == 1)
        {
            printf("请输入矩阵a行列及对应元素:\n");
            scanf("%d%d", &n, &m);
            for (i = 1; i <= n; ++i)
                for (j = 1; j <= m; ++j)
                    scanf("%d", &a.x[i][j]);
            printf("请输入矩阵b行列及对应元素:\n");
            scanf("%d%d", &m, &t);
            for (i = 1; i <= m; ++i)
                for (j = 1; j <= t; ++j)
                    scanf("%d", &b.x[i][j]);
            ans = Matrix_Multiply(a, b, n, m, t);
            printf("结果为：\n");
            for (i = 1; i <= n; ++i)
            {
                int flag = 0;
                for (j = 1; j <= t; ++j)
                {
                    if (flag)
                        printf(" %d", ans.x[i][j]);
                    else
                        printf("%d", ans.x[i][j]);
                    flag = 1;
                }
                printf("\n");
            }
        }
        if (num == 2)
        {
            printf("请输入矩阵阶数、目标幂次及矩阵:\n");
            scanf("%d%d", &n, &m);
            for (i = 1; i <= n; ++i)
                for (j = 1; j <= n; ++j)
                    scanf("%d", &a.x[i][j]);
            if (n != 1)
            {
                ans = Matrix_fastpower(a, n, m);
                printf("结果为：\n");
                for (i = 1; i <= n; ++i)
                {
                    int flag = 0;
                    for (j = 1; j <= n; ++j)
                    {
                        if (flag)
                            printf(" %d", ans.x[i][j]);
                        else
                            printf("%d", ans.x[i][j]);
                        flag = 1;
                    }
                    printf("\n");
                }
            }
            else
            {
                int tp = a.x[1][1];
                int anss = 1;
                for (i = 1; i <= m; ++i)
                    anss *= tp;
                printf("结果为：\n");
                printf("%d\n", anss);
            }
        }
        printf("\n1.矩阵乘法\n2.矩阵(方阵)快速幂\n请选择操作序号：\n");
    }
    return 0;
}
