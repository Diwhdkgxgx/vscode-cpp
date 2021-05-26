// 2.1	改进《实验三  面向对象初步》中的日期类
// 在《实验三  面向对象初步》中，设计了日期类Date。
// 本次实验将daysTo函数重载为减号运算符，使得t1 - t2的值为从日期t2到日期t1的天数。
// 如果t1在t2之前，则为负数，即计算t1比t2晚多少天。
// 重载大于运算符，如果t1在t2之后，则表达式t1 > t2为真；
// 重载小于运算符，如果t1在t2之前，则表达式t1 < t2为真。

#include <iomanip>
#include <iostream>
using namespace std;


class Date
{
private:
    int year;
    int month;
    int day;
    char separator;

public:
    Date(int year = 1990, int month = 1, int day = 1, char separator = '-'):
        year(year), month(month), day(day), separator(separator){ }

    Date(Date &p);

    int operator-(const Date &date2);

    bool operator>(const Date &date2);
    bool operator<(const Date &date2);
};

Date::Date(Date &p)
{
    year = p.year;
    month = p.month;
    day = p.day;
}

int Date::operator-(const Date &date2)
{
    int i;
    int months_ping[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int months_run[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Date date;
    int t = 0;
    int year1, year2, month1, month2, day1, day2;
    

    year1 = this->year;
    year2 = date2.year;
    month1 = this->month;
    month2 = date2.month;
    day1 = this->day;
    day2 = date2.day;

    int yt = year1, mt = month1, dt = day1;

    if (year1 > year2)
    {
        year1 = year2;
        year2 = yt;
        
        month1 = month2;
        month2 = mt;
        
        day1 = day2;
        day2 = dt;

        t = 1;
    }

    // 求本年一共有多少天
    if (((year2 % 4 == 0) && (year2 % 100 != 0)) || (year2 % 400 == 0))
    {
        for (i = 0; i < month2 - 1; i++)
        {
            day2 += months_run[i];
        }
    }
    else
    {
        for (i = 0; i < month2 - 1; i++)
        {
            day2 += months_ping[i];
        }
    }

    // 求过的这些年有多少天
    for (i = year1 + 1; i < year2; i++)
    {
        if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
        {
            day2 += 366;
        }
        else
        {
            day2 += 365;
        }
    }

    // 求生日那年还有多少天
    if (((year1 % 4 == 0) && (year1 % 100 != 0)) || (year1 % 400 == 0))
    {
        for (i = 0; i < month1 - 1; i++)
        {
            day1 += months_run[i];
        }
    }
    else
    {
        for (i = 0; i < month1 - 1; i++)
        {
            day1 += months_ping[i];
        }
    }

    if (((year1 % 4 == 0) && (year1 % 100 != 0)) || (year1 % 400 == 0))
    {
        day2 += 366 - day1;
    }
    else
    {
        day2 += 365 - day1;
    }

    if (t == 0)
    {
        return day2;
    }
    else
    {
        return ~day2 + 1;
    }

}

bool Date::operator>(const Date &date2)
{
    if (this->year < date2.year)
    {
        return false;
    }
    else if (this->year > date2.year)
    {
        return true;
    }
    else
    {
        if (this->month < date2.month)
        {
            return false;
        }
        else if (this->month > date2.month)
        {
            return true;
        }
        else
        {
            if (this->day > date2.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        } 
    } 
}

bool Date::operator<(const Date &date2)
{
    if (this->year > date2.year)
    {
        return false;
    }
    else if (this->year < date2.year)
    {
        return true;
    }
    else
    {
        if (this->month > date2.month)
        {
            return false;
        }
        else if (this->month < date2.month)
        {
            return true;
        }
        else
        {
            if (this->day < date2.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        } 
    } 
}


int main()
{
    Date t1(1969, 8, 11);
    Date t2(2010, 4, 15);

    Date t3(1969, 8, 11);
    Date t4(1949, 10, 1);

    cout << t1 - t2 << endl;
    cout << t3 - t4 << endl;

    cout << (t1 > t2) << endl;
    cout << (t1 < t2) << endl;
    
    cout << (t3 > t4) << endl;
    cout << (t3 < t4) << endl;

    return 0;
}