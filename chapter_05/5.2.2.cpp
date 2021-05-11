#include <iostream>
#include <iomanip>
using namespace std;

int i;

struct Sodeshui
{
    int m;
    double rate;
};

int n;
struct Sodeshui Sodeshuies[10];

//根据用户输入的规则条数，从键盘得到所有规则，存放至数组。
void inputRules(int num)
{
    // Sodeshui Sodeshuies[num];
    for (i = 0; i < num; i++)
    {
        cout << "请输入第 " << i + 1 << " 条规则：";
        cin >> Sodeshuies[i].m;
        cin >> Sodeshuies[i].rate;
    }
}

// 定义一个子函数计算所得税。 参数income表示个人收入
double computeTax(int income)
{
    // 判断收入在哪个m区间，并记录
    int mark;

    for ( i = 0; i < n; i++)
    {
        if ( income > Sodeshuies[i].m )
        {
            if ( income <= Sodeshuies[i+1].m )
            {
                mark = i;
                break;
            }
        }
    }

    if (income > Sodeshuies[n - 1].m)
    {
        mark = n - 1;
    }

    // 计算所得税 
    double all_tax = 0;
    for ( i = mark; i >= 0; i--)
    {
        all_tax += (income - Sodeshuies[i].m) * Sodeshuies[i].rate * 0.01;
        income = Sodeshuies[i].m;
    }
    return all_tax;
}

void showRules()
{
    cout << "纳税规则如下：" << endl;
    cout << "纳税线      ";
    cout << setw(6) << "税率" << endl;

    for (i = 0; i < n; i++)
    {
        cout << std::right << Sodeshuies[i].m;
        cout << std::right << setw(5) << Sodeshuies[i].rate << endl;
    }
}

int main()
{

    cout << "请输入规则的条数：";
    cin >> n;
    inputRules(n);

    showRules();
    
    int income;

    while (income != -1)
    {
        cout << "请输入您的收入：";
        cin >> income;

        cout << "您的收入是：" << income << "，应缴纳所得税：" << computeTax(income) << "元" << endl;

    }

    cout << "再见" << endl;

    return 0;
}