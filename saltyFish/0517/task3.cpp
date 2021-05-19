#include <math.h>
#include <stdio.h>
void fun(int n)
{
    int i, k;
    if (n <= 0)
        printf("输入的数字错误");
    k = sqrt(n);
    for (i = 2; i <= k; i++)
        if (n % i == 0)
            break;
    if (i > k)
        printf("%d是素数", n);
    else
        printf("%d不是素数", n);
}

void main()
{
    int n;
    printf("请输入需要判断的素数:");
    scanf("%d", &n);
    fun(n);
}