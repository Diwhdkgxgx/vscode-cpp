#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    srand((int)time(0));
    int sum, i, j, n, h, L, a, b, z;
    
    cin >> n >> sum;
    int shu[n][n];

    // 生成随机矩阵
    for ( i = 0; i < n ; i++)
    {
        for ( j = 0; j < n ; j++)
        {
            shu[i][j] = rand() % 2;
        }
    }
    
    // 大循环
    for ( i = 0; i < sum; i++)
    {
        for ( a = 0; a < n ; a++)
        {
            for ( b = 0; b < n ; b++)
            {
                if (shu[a][b] == 1)
                {
                    for ( z = 0; z < n ; z++)
                    {
                        // 这里好像有点问题
                    }
                    shu[a][z] += shu[b][z];
                }
            } 
        }

        for ( a = 0; a < n ; a++)
        {
            for ( b = 0; b < n; b++)
            {
                if (shu[a][b] != 0)
                {
                    shu[a][b] = 1; 
                }
            }
            
        }
    }

    // 输出
    for ( a = 0; a < n ; a++)
    {
        for ( b = 0; b < n ; b++)
        {
            cout << shu[a][b] << " ";
        }
        cout << endl;
    }

    return 0;
}