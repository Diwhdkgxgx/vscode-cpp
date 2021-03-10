// In ancient Indian mathematics, a Vedic square is a variation on a typical 9×9 multiplication table.
// The entry in each cell is the digital root of the product of the column and row headings.
// Vedic Square是一个9×9的表，与九九乘法表类似。只是表的每个格不是行列序号的乘积，而是乘积的数字根。下图是Vedic Square。
// 
// （2）Vedic Star
//  By replacing a specific number by asterisk whereas the others by space within the Vedic square, you can find some distinct shapes each with some form of reflection symmetry.
// （3）Output
// You are to print the Vedic square first, and then the shapes of every specific number. An example of the shape of number 1 is as follows.

#include <iostream>
#include <iomanip>
// #include <stdio.h>
using namespace std;

int main()
{
    int root_number(int);
    void change_star(int a[100], int n, int m);
    void output_star(int a[100], int n);

    int a[10];
    int i, k = 0, j;

    // 获取1-9数组
    for (i = 0; i < 9; i++)
    {
        a[i] = i + 1;
    }

    int result[100], result2[100];
     
    // 获取根
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            result[k] = root_number(a[i] * a[j]);
            result2[k] = root_number(a[i] * a[j]);
            k++;
        }
    }

    // 格式输出9x9方阵
    cout << "   ";      // printf("   "); 
    cout << "|";        // putchar('|');
    
    for ( i = 0; i < 9; i++)
    {
        cout << setw(2) << a[i] <<" ";  // printf("%2.d ", a[i]);
    }
    cout << endl;       // putchar('\n');

    for ( i = 0; i < 3; i++)
    {
        cout << "-";    // printf("-");
    }   
    cout << "|";        // putchar('|');
    for ( i = 0; i < 28; i++)
    { 
        cout << "-";    // printf("-");
    }
    cout << endl;       // putchar('\n');

    cout << setw(2) << a[0] <<" ";              // printf("%2.d ", a[0]);

    int d = 1; 
    cout << "|";  // putchar('|');

    for (i = 0, k = 0; i < 81; i++)
    {   
        cout << setw(2) << result[i] <<" ";     // printf("%2.d ", result[i]);
        k++;
        if (k % 9 == 0 && k != 81)
        {
            cout << endl;                       // putchar('\n');
            cout << setw(2) << a[d] << " ";     // printf("%2.d ", a[d]);
            cout << "|";                        // putchar('|');
            d++;
        }

    } 
    cout << endl;  // putchar('\n');

    // 输出星星图
    for ( i = 1; i < 10; i++)
    {
        // printf("------------%d------------\n", i);
        cout << "------------" << i << "------------\n";
        change_star(result2, 81, i);
        output_star(result2, 81);

        for ( j = 0; j < 81; j++)
        {
            result2[j] = result[j];
        }
    }

    return 0;
}

// 获取某数字数字根 n：待求数字根函数
int root_number(int n)
{
    if (n > 0 && n < 10)
    {
        return n;
    }
    else
    {
        int shi, ge, result;
        
        while (n >= 10)
        {
            shi = n / 10;
            ge = n % 10;
            n = shi + ge;
        }
        result = shi + ge;
        return result;
    }
}

// 将某数字转换为*，其余变为空格  数组a：要转换的数组 n：待处理个数 m：变为*的数字
void change_star(int a[100], int n, int m)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == m)
        {
            a[i] = 42;
        }
        else
        {
            a[i] = 0;
        }
    }
}

// 输出星星图 数组a：要转换的数组 n：待处理个数
void output_star(int a[100], int n)
{
    int i, k;
    for (i = 0, k = 0; i < n; i++)
    {
        // printf("%2.c ", a[i]);
        cout << setw(2) << char(a[i]) << " ";
        k++;

        if (k % 9 == 0)
        {
            // putchar('\n');
            cout << endl;
        }
    }
    // putchar('\n');
}