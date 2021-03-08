// In ancient Indian mathematics, a Vedic square is a variation on a typical 9×9 multiplication table. 
// The entry in each cell is the digital root of the product of the column and row headings.
// Vedic Square是一个9×9的表，与九九乘法表类似。只是表的每个格不是行列序号的乘积，而是乘积的数字根。下图是Vedic Square。

// （2）Vedic Star
//  By replacing a specific number by asterisk whereas the others by space within the Vedic square, you can find some distinct shapes each with some form of reflection symmetry.
// （3）Output
// You are to print the Vedic square first, and then the shapes of every specific number. An example of the shape of number 1 is as follows.

#include <iostream>
using namespace std;

int main()
{
    int a[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        a[i] = i + 1;
    }

    int root_number(int);
    int d;
    cin >> d;
    int dd;
    dd = root_number(d);

    cout << dd << endl;
    return 0;
}

int root_number(int n)
{
    if (n > 0  && n < 10)
    {
        return n;
    }
    else
    {
        int shi, ge, result;
        shi = n / 10;
        ge = n % 10;
        n = shi + ge;
        result = shi + ge;
        return result;
    }
}