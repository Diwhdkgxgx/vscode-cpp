// // 月份天数计算，从键盘输入年份和月份，计算该月份的天数并输出。
// #include <stdio.h>
// int main()
// {
//     int y, m;
//     printf("输入年份，月份: \n");
//     scanf("% d, % d", &y, &m);
//     switch (m)
//     {
//     case 1:
//     case 3:
//     case 5:
//     case 7:
//     case 8:
//     case 10:
//     case 12:
//         printf("该月有31天\n");
//         break;
//     case 4:
//     case 6:
//     case 9:
//     case 11:
//         printf("该月有30天\n");
//         break;
//     case 2:
//         if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
//             printf("该月有29天");
//         else
//             printf("该月有28天");
//     }
//     return 0;
// }

// 质数判断，从键盘输入一个正整数n，判断n是否为质数。
#include<stdio.h>
int main()
{
	int a,b;
	scanf("%d",&a);
		if(a==2)
		{
			printf("是质数\n");
		}
		if(a>2)
		{
			for(b=2;b<a;b++)
			{
				if(a%b==0)
				{
					printf("不是质数\n");
					break;
				}
			}
			if(a==b)
			{
				printf("是质数\n");
			}
		}
		return 0;
}
}