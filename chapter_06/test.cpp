#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string.h>
using namespace std;

int ramdon(int max)
{
    int a;
    srand((int)time(0));
    // srand(static_cast<unsigned>(time(NULL)));
    a = rand() % max; // max = 3   0 1 2
    return a;
}

int main()
{
    string a;
    int i = 3;
    string b = "jjjj";

    std::string s = std::to_string(i);
    a = b + "0" + s;
    cout << a << endl;
    // int k;
    // char names[100];
    // for (char ch = 'A', i = 0; ch <= 'Z'; ch++)
    // {
    //     names[i] = ch;
    //     cout << ch << endl;
    //     i++;
    //     k = i;
    // }
    // for (char ch = 'a'; ch <= 'z'; ch++)
    // {
    //     names[i] = ch;
    //     i++;
    //     k = i;
    // }
    // for (char ch = '0'; ch <= '9'; ch++)
    // {
    //     names[i] = ch;
    //     i++;
    //     k = i;
    // }

    // for (i = 0; i < k; i++)
    // {
    //     cout << names[i] << endl;
    // }

    // int ramdon(int max)
    // {
    //     int a;
    //     srand((int)time(0));
    //     // srand(static_cast<unsigned>(time(NULL)));
    //     a = rand() % max; // max = 3   0 1 2
    //     return a;
    // }

    int cdd;
    // srand((int)time(0));
    srand(static_cast<unsigned>(time(NULL)));
    

    for (i = 0; i < 5; i++)
    {
        cdd = rand() % 4;
        cout << cdd << endl;
    }

    return 0;
}

int uuu() //主函数
{
    int A[10], i, j;         //整型数组和变量声明
    srand((int)time(0));     //设置系统时间为随机种子
    for (i = 0; i < 10; i++) //产生10个随机数
    {
        A[i] = 1 + rand() % 10; //得到随机数(范围在1-10之间)
        for (j = 0; j < i; j++) //判断和前面的数是否重复
            if (A[i] == A[j])
            {
                i--;
                break;
            } //如果重复,重新产生随机数
    }
    printf("10个1－10的随机数):\n");
    for (i = 0; i < 10; i++)
        printf("%d", A[i]); //显示10个随机数
    system("PAUSE");        //屏幕暂停,以便看到显示结果
    return 0;               //结束程序
}
