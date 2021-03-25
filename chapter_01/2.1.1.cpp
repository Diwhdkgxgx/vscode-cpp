

#include <iostream>
using namespace std;
int result(int num);
void printSquare(int a[][9]);
void printStar(int a[][9],int n);
void vedic(int a[][9]);
int main()
{
    int a[9][9];
    vedic(a);
    printSquare(a);
    for (int i = 1; i < 10; i++)
    {
        cout << endl << "-------------" << i << "----------" << endl;
        printStar(a, i);
    }
    return 0;
}
void vedic(int a[][9])
{
    int i = 0, j = 0;
    for (i; i < 9; i++)
    {
        for (j=0; j < 9; j++)
            a[i][j] = result((i+1)*(j+1));
    }
}
void printSquare(int a[][9])
{
    cout << "   | ";
    for (int j = 0; j < 9; j++)
        cout << " " << j << " ";
    cout << endl << "---|-----------------------------" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << " " << i + 1 << " | ";
        for (int j = 0; j < 9;j++)
            cout << " " << a[i][j] << " ";
        cout << endl;
    }
        
}void printStar(int a[][9],int n)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j] == n)
                cout << " * ";
            else
                cout << "   ";
        }
        cout << endl;
    }
    
}
int result(int num)
{
    int i=num;
    int sum = 0;
    while (i > 0)
    {
        sum += i % 10;
        i = i / 10;
    }
    if (sum >= 10)
    {
        result(sum);
    }
    else
    {
        return sum;
    }
}
