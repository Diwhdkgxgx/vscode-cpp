#include <stdio.h>
int main()
{
    　　char i, j;

    　　 printf("please input the first letter of someday:\n");
    　　scanf("%c", &i);

    switch (i)
    {
        　　case 'm' :
　　　　printf("Monday\n");
        　　　　break;
        　　case 'w' :
　　　　printf("Wednesday\n");
        　　　　break;
        　　case 'f' :
　　　　printf("Friday");
        　　　　break;
        　　case 't' :
　　　　printf("请输入下一个字母\n");
        　　　　scanf("%c", &j);
        　　　　if (j == 'u')
　　　　
        {
            　　　　　　printf("Tuesday\n");
            　　　　　　break;
            　　　　
        }
        　　　　if (j == 'h')
　　　　
        {
            　　　　　　　printf("Thursday\n");
            　　　　　　 break;
            　　　　
        }
        　　case 's' :
　　　　printf("请输入下一个字母\n");
        　　　　scanf("%c", &j);
        　　　　if (j == 'a')
　　　　
        {
            　　　　　　printf("saturday\n");
            　　　　　　break;
            　　　　
        }
        　　　　if (j == 'u')
　　　　
        {
            　　　　　　 printf("sunday\n");
            　　　　　　 break;
            　　　　
        }
        　　default :
　　　　printf("error\n");
        　　　　break;

        　　
    }
    　　 return 0;
}