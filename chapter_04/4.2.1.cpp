// 2.1 使用 Date 类，定义 Employee 类

// （1）问题描述
// 在《实验三 面向对象初步》中，设计了日期类 Date。本次实验将设计雇员类 Employee，并将日期类 Date 作为雇员类 Employee 的内嵌数据成员。日期类
// Date 和雇员类 Employee 的声明分别如下所示：

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int i;

class Date
{
private:
    int year;
    int month;
    int day;
    char separator;

    static int DAYS_PER_MONTH[12];
    int checkDay(int day);
    bool isLeapYear(int year);

public:
    Date(int year = 1990, int month = 1, int day = 1, char separator = '-');
    // Date(int y = 1990, int m = 1, int d = 1, char sep = '-');
    // Date(int , int, int, char );

    Date(Date &date);

    void setDate(int year, int month, int day);
    void setYear(int year);
    int getYear();
    void setMonth(int month);
    int getMonth();
    void setDay(int day);
    int getDay();

    void setSeparator(char separator);

    void printFullYear();
    void printStandardYear();

    int fullYearsTo(Date &date);

    int daysTo(Date &date);

    int getDayOfYear();
    int getLeftDaysYear();

    
};

Date::Date(int year, int month, int day, char separator) : year(year), month(month), day(day), separator(separator)
{
}

Date::Date(Date &date)
{
    year = date.year;
    month = date.month;
    day = date.day;
    separator = date.separator;    // 做这个复制构造函数的时候不要忘了separator这一项啊啊！！！！！！
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
    cout << setfill('0') << setw(2) << day;
}

void Date::printStandardYear()
{
    cout << year % 100;
    cout << separator;
    cout << setfill('0') << setw(2) << month;
    cout << separator;
    cout << setfill('0') << setw(2) << day << endl;
}

int Date::fullYearsTo(Date &date)
{
    int gapyear = date.year - this->year;
    if (this->month > date.month)
    {
        gapyear = gapyear - 1;
    }
    else if (this->month == date.month)
    {
        if (this->day < date.day)
        {
            gapyear = gapyear - 1;
        }
    }
    return gapyear;
}

int Date::daysTo(Date &date)
{
    int months_ping[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int months_run[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int t = 0;
    int yt = year, mt = month, dt = day;
    if (year > date.year)
    {
        year = date.year;
        date.year = yt;
        
        month = date.month;
        date.month = mt;
        
        day = date.day;
        date.day = dt;

        t = 1;
    }

    // 求本年一共有多少天
    if (((date.year % 4 == 0) && (date.year % 100 != 0)) || (date.year % 400 == 0))
    {
        for (i = 0; i < date.month - 1; i++)
        {
            date.day += months_run[i];
        }
    }
    else
    {
        for (i = 0; i < date.month - 1; i++)
        {
            date.day += months_ping[i];
        }
    }

    // 求过的这些年有多少天
    for (i = year + 1; i < date.year; i++)
    {
        if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
        {
            date.day += 366;
        }
        else
        {
            date.day += 365;
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
        date.day += 366 - day;
    }
    else
    {
        date.day += 365 - day;
    }

    year = yt;
    month = mt;
    day = dt;

    if (t == 0)
    {
        return date.day;
    }
    else
    {
        return ~date.day + 1;
    }
}


class Employee
{
private:
    string firstName;
    string lastName;
    Date birthDate;
    Date hireDate;

public:
    Employee(string firstName, string lastName, Date &birthday, Date &hireday) : 
        firstName(firstName), lastName(lastName), birthDate(birthday), hireDate(hireday){ }

    // Employee(string firstName, string lastName, Date &birthday, Date &hireday);
    void print();

    int getAge(Date &date);
    int getYearsWorked(Date &date);
    int getDaysWorked(Date &date);

    // ~Employee();
};

// Employee::Employee(string firstName, string lastName, Date &birthday, Date &hireday) : 
//     firstName(firstName), lastName(lastName), birthDate(birthday), hireDate(hireday){ }

void Employee::print()
{
    cout << lastName << ", ";
    cout << firstName << " Hired:";
    birthDate.printFullYear();
    cout << " birthday: ";
    hireDate.printFullYear();
}

int Employee::getAge(Date &date)
{
    return birthDate.fullYearsTo(date);
}

int Employee::getYearsWorked(Date &date)
{
    return hireDate.fullYearsTo(date);
}

int Employee::getDaysWorked(Date &date)
{
    return hireDate.daysTo(date);
}

int main()
{
    Date birth(1969, 8, 11);
    Date hire(1998, 4, 1);
    Date today(2010, 4, 30);
    Employee manager("Bob", "Blue", birth, hire);

    cout << endl;

    manager.print();
    cout << endl;

    cout << manager.getAge(today) << endl;

    cout << manager.getDaysWorked(today) << endl;

    return 0;
}