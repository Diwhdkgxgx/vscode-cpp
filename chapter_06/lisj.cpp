#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int cal(int **R, int **copy_R, int n, int hang, int lie)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += copy_R[hang][i] * R[i][lie];
    }
    return ans;
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

    int *R[n];
    int *copy_R[n];
    int new_R[n][n];


    for ( i = 0; i < n ; i++)
    {
        R[i] = new int [n];  
        copy_R[i] = new int [n]; 
        for ( j = 0; j < n ; j++)
        {
            R[i][j] = rand() % 2;
            copy_R[i][j] = R[i][j];
        }
    }


    cout << "随机生成的矩阵为：" << endl;
    for (i = 0; i < n; i++)
    {
        for ( j = 0; j < n ; j++)
        {
            cout << copy_R[i][j] << " ";
        }
        cout << endl;
    }
    cout <<"-----------------------"<< endl;
  

    int hang, lie;
    for ( m = 0; m < mi; m++)
    {
        // 每一次R的相乘
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
        
    
        // copy_R[0][1] * R[1][0]
        // copy_R[0][2] * R[2][0]
        // copy_R[0][3] * R[3][0]
        // 
        // copy_R[0][0] * R[1][1]
        // copy_R[0][1] * R[2][1]
        // copy_R[0][2] * R[3][1]
        // copy_R[0][3] * R[4][1]
    }
    

    // 输出
    cout << "结果为：" << endl;
    for (i = 0; i < n; i++)
    {
        for ( j = 0; j < n ; j++)
        {
            cout << copy_R[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
