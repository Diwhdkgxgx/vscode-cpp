#include <iomanip>
#include <iostream>
// #include <stdio.h>
using namespace std;

int i;

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
    /* get、set方法 */
    // 设置日期，如果有非法的月或日，将其置为1
    void setDate(int year, int month, int day);
    void setYear(int year);
    int getYear();

    void setMonth(int month);
    int getMonth();

    void setDay(int day);
    int getDay();

    void setSeparator(char separator);

    /* 输出函数，请使用setfill(‘0’)和setw(2)，需要包含<iomanip>头文件 */
    void printFullYear();     // 以YYYY-MM-DD的形式打印，2011-01-08
    void printStandardYear(); // 以YY-MM-DD的形式打印，比如11-01-08

    /* 计算函数 */
    // 计算当前日期与参数日期之间相差几个整年，仅考虑参数日期比当前日期晚的情况
    int fullYearsTo(int year, int month, int day);

    /* 计算当前日期与参数日期之间相差多少天(考虑闰年)，如果参数日期在当前日期之前，返回负数。 */
    int daysTo(int year2, int month2, int day2);
};

// Date::Date(int year = 1990, int month = 1, int day = 1) : year(year), month(month), day(day) {}

Date::Date(Date &p)
{
    year = p.year;
    month = p.month;
    day = p.day;
}

void Date::setDate(int year, int month, int day)
{
    year = year;
    month = month;
    day = day;
    separator = '-';
}

void Date::setYear(int year)
{
    year = year;
}

int Date::getYear()
{
    return year;
}

void Date::setMonth(int month) // 如果month非法，设置为1
{
    int t = 0;
    // int months[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for (i = 1; i < 13; i++)
    {
        if (month == i)
        {
            t = 1;
        }
    }
    if (t == 0)
    {
        month = 1;
    }
}

int Date::getMonth()
{
    return month;
}

void setDay(int day)
{
    int t = 0;
    for (i = 1; i < 32; i++)
    {
        if (day == i)
        {
            t = 1;
        }
    }
    if (t == 0)
    {
        day = 1;
    }
}

int Date::getDay()
{
    return day;
}

void Date::setSeparator(char separator)
{
   this->separator = separator; // this->s相当于指针，区别两个seprator
}

void Date::printFullYear()
{
    cout << year;
    cout << separator;
    // printf("%c", separator);
    cout << setfill('0') << setw(2) << month;
    cout << separator;
    cout << setfill('0') << setw(2) << day << endl;
}

void Date::printStandardYear()
{
    cout << year % 100;
    cout << separator;
    cout << setfill('0') << setw(2) << month;
    cout << separator;
    cout << setfill('0') << setw(2) << day << endl;
}

int Date::fullYearsTo(int year, int month, int day)
{
    int gapyear = year - this->year;
    if (this->month > month)
    {
        gapyear = gapyear - 1;
    }
    else if (this->month == month)
    {
        if (this->day < day)
        {
            gapyear = gapyear - 1;
        }
    }
    return gapyear;
}

int Date::daysTo(int year2, int month2, int day2)
{
    int months_ping[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int months_run[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int t = 0;
    int yt = year, mt = month, dt = day;
    if (year > year2)
    {
        year = year2;
        year2 = yt;
        
        month = month2;
        month2 = mt;
        
        day = day2;
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
    for (i = year + 1; i < year2; i++)
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
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        for (i = 0; i < month - 1; i++)
        {
            day += months_run[i];
        }
    }
    else
    {
        for (i = 0; i < month - 1; i++)
        {
            day += months_ping[i];
        }
    }

    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        day2 += 366 - day;
    }
    else
    {
        day2 += 365 - day;
    }

    year = yt;
    month = mt;
    day = dt;

    if (t == 0)
    {
        return day2;
    }
    else
    {
        return ~day2 + 1;
    }
}

int main()
{
    Date birthDate(1969, 8, 11);
    birthDate.printFullYear();     // 打印：1969-08-11
    birthDate.printStandardYear(); // 打印：69-08-11
    birthDate.setSeparator('/');
    birthDate.printFullYear();                  // 打印：1969/08/11
    cout << birthDate.fullYearsTo(2010, 4, 15) << endl; // 打印：40，满四十岁
    cout << birthDate.daysTo(2010, 4, 15) << endl;      // 打印14857，活了14857天了
    // 打印-7254，共和国比我早诞生了7254天
    cout << birthDate.daysTo(1949, 10, 1) << endl;
    return 0;
}