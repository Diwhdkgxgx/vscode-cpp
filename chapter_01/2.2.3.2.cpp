#include <iostream>
using namespace std;
int isGoal(char *a, int n);
void behind(char a[], int n);
void change(char a[], int i, int j);
void sort(char result[][20], int k, int l);

int main()
{
    int n;
    cin >> n;
    char block[5][20];
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        for (int j = 0; j < 2 * (num) + 1; j++)
            cin >> block[i][j];
            
        if (isGoal(block[i], num))
            cout << "目标格局\n";
        else
            behind(block[i], num);
    }
    return 0;
}

int isGoal(char *a, int n)
{
    int MaxB = 100;
    int MinW = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'W')
            MinW = i;
        else if (a[i] == 'B')
            if (i < MaxB)
                MaxB = i;
    }
    if (MaxB > MinW)
        return 1;
    else
        return 0;
}
void change(char a[], int i, int j)
{
    char b = a[i];
    a[i] = a[j];
    a[j] = b;
}
void sort(char result[][20], int k, int l)
{
    char str[20];
    for (int i = k - 1; i > 0; i--)
        for (int j = 0; j < i - 1; j++)
            if (strcmp(result[j + 1], result[j]) < 0)
            {
                strcpy_s(str, result[j]);
                strcpy_s(result[j], result[j + 1]);
                strcpy_s(result[j + 1], str);
            }
}
void behind(char a[], int num)
{
    char result[10][20];
    char middle[20];
    int k = 0;
    strcpy_s(middle, a);
    int index = 0;
    int length = strlen(middle);
    for (int i = 0; i < length; i++)
    {
        if (middle[i] == 'E')
        {
            index = i;
            break;
        }
    }
    for (int i = 0; i < 10; i++)
        strcpy_s(result[i], middle);
    for (int i = 1; i < 4; i++)
    {
        if (index + i < length)
        {
            change(result[k], index, index + i);
            k++;
        }
        if (index - i >= 0)
        {
            change(result[k], index, index - i);
            k++;
        }
    }
    sort(result, k, length);
    for (int i = 0; i < k; i++)
        cout << result[i] << endl;
}