// BBBWWWE
// BBBBWWWWE
// 游戏的规定走法是：
// （1）任意一个将牌可以移入相邻的空格；
// （2）任意一个将牌可相隔1个或2个其他的将牌跳入空格。
// 游戏要达到的目标是使所有白将牌都处在黑将牌的左边（左边有无空格均可），我们称为目标格局。
// WWWWBBEBB

#include <iostream>
using namespace std;

// B 1 E 2 W 3

int i;
int main()
{
    void inputGeju(int hua_kuai[], char ge[][10],int n);

    int n;
    cin >> n;

    int hua_kuai_number[n];
    char ge_ju[n][10];

    inputGeju(hua_kuai_number, ge_ju, n);

    for (i = 0; i < n; i++)
    {
        cout << hua_kuai_number[i];
        cout << " " << ge_ju[i] << endl;
    }

    return 0;
}

void inputGeju(int hua_kuai[], char ge[][10],int n)
{
    
    for ( i = 0; i < n; i++)
    {
        cin >> hua_kuai[i];
        cin >> ge[i];
    }
}

