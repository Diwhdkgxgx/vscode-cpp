// 2.2	使用改进后的日期类，修改《实验四  对象作为数据成员》中的雇员类（Employee）
// （1）修改getDaysWorked，使其调用日期类中重载的减号运算符。
// （2）添加一个静态成员函数，调用日期类中重载的“>”运算符，通过比较雇佣日期，在雇员对象数组中，找出工作年限最长的雇员。该函数的说明如下：
// /*
// *参数employees[]是雇员对象的数组；n是雇员对象数组的元素个数
// *返回值：工作年限最长的雇员对象的引用
// */
// static const Employee& getMostFaith(const Employee employees[], int n);
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
    Date(int year = 1990, int month = 1, int day = 1, char separator = '-') : year(year), month(month), day(day), separator(separator) {}

    // Date(Date &p);

    int operator-(const Date &date2);

    bool operator>(const Date &date2);
    bool operator<(const Date &date2);

    void setDate(int year, int month, int day);
    void setYear(int year);
    int getYear();
    void setMonth(int month);
    int getMonth();
    void setDay(int day);
    int getDay();

    void setSeparator(char separator);

    void printFullYear() const;
    void printStandardYear() const;

    int fullYearsTo(Date &date);
};

// Date::Date(Date &p)
// {
//     year = p.year;
//     month = p.month;
//     day = p.day;
// }

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
    int i;
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
    int i;
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

void Date::printFullYear() const
{
    cout << year;
    cout << separator;
    // printf("%c", separator);
    cout << setfill('0') << setw(2) << month;
    cout << separator;
    cout << setfill('0') << setw(2) << day;
}

void Date::printStandardYear() const
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

class Employee
{
private:
    string firstName;
    string lastName;
    Date birthDate;
    Date hireDate;

public:
    Employee(string firstName, string lastName, Date &birthday, Date &hireday) : firstName(firstName), lastName(lastName), birthDate(birthday), hireDate(hireday) {}

    // Employee(string firstName, string lastName, Date &birthday, Date &hireday);
    void print() const;

    int getAge(Date &date);
    int getYearsWorked(Date &date);
    int getDaysWorked(Date &date) const; // 后加const

    Date getHireDate() const
    {
        return hireDate;
    }

    static const Employee &getMostFaith(const Employee employees[], int n)
    {
        int i, longest = 0;

        Date d1;

        d1.setDate(employees[0].getHireDate().getYear(),
                   employees[0].getHireDate().getMonth(),
                   employees[0].getHireDate().getDay());

        for (i = 0; i < n; i++)
        {
            if (employees[i].getHireDate() < d1 )
            {
                d1.setDate(employees[i].getHireDate().getYear(),
                           employees[i].getHireDate().getMonth(),
                           employees[i].getHireDate().getDay());

                longest = i;
            }
        }

        return employees[longest];
    }

    
};

// Employee::Employee(string firstName, string lastName, Date &birthday, Date &hireday) :
//     firstName(firstName), lastName(lastName), birthDate(birthday), hireDate(hireday){ }

void Employee::print() const
{
    cout << lastName << ", ";
    cout << firstName << " Hired:";
    hireDate.printFullYear();
    cout << " birthday: ";
    
    birthDate.printFullYear();
}

int Employee::getAge(Date &date) 
{
    return birthDate.fullYearsTo(date);
}

int Employee::getYearsWorked(Date &date)
{
    return hireDate.fullYearsTo(date);
}

int Employee::getDaysWorked(Date &date) const
{
    return date - this->hireDate;
}

// Employee::Employee &getMostFaith(const Employee employees[], int n)
// {
//     int i, longest;

//     Date d1;

//     d1.setDate(employees[0].getHireDate().getYear(),
//                employees[0].getHireDate().getMonth(),
//                employees[0].getHireDate().getDay());

//     for (i = 0; i < n; i++)
//     {
//         if (employees[i].getHireDate() - d1 < 0)
//         {
//             d1.setDate(employees[i].getHireDate().getYear(),
//                        employees[i].getHireDate().getMonth(),
//                        employees[i].getHireDate().getDay());

//             longest = i;
//         }
//     }

//     return const (&employees[longest]);

//     // 不可用因为today未知，且未传入
//     // Date today(2021, 5, 19);
//     // int j = 0;
//     // for (i = 0; i < n; i++)
//     // {
//     //     if (employees[j].getDaysWorked(today) > employees[i].getDaysWorked(today))
//     //     {
//     //         j = i;
//     //     }
//     // }

// }

int main()
{
    Date birth(1969, 8, 11);

    Date today(2021, 5, 19);

    Date hire1(1998, 4, 1);
    Date hire2(1999, 8, 15);
    Date hire3(2010, 4, 30);
    Date hire4(2010, 4, 1);
    Date hire5(2021, 12, 31);

    Employee e1("man1", "blue", birth, hire1);
    Employee e2("man2", "blue", birth, hire2);
    Employee e3("man3", "blue", birth, hire3);
    Employee e4("man4", "blue", birth, hire4);
    Employee e5("man5", "blue", birth, hire5);

    Employee employees[] = {e1, e2, e3, e4, e5};

    const Employee &employee = Employee::getMostFaith(employees, 5);

    employee.print();
    cout << endl;
    return 0;
}