#include <stdio.h>
#include "date.h"
inline bool date::isLegal(int _year, int _month, int _day)
{
    if (_year < 0)
        return false;
    if (_month < 1 || _month > 12)
        return false;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (!(_year % 4) && (_year % 100) || !(_year % 400))
        days[1] = 29;
    if (_day > days[_month - 1] || _day < 0)
        return false;
    return true;
}

date::date(int _year, int _month, int _day)
{
    if (isLegal(_year, _month, _day))
    {
        year = _year;
        month = _month;
        day = _day;
    }
    else
    {
        throw MyException("Date Error.");
        year = 0;
        month = 1;
        day = 1;
    }
}

date::date(const date & another_date)
{
    year = another_date.year;
    month = another_date.month;
    day = another_date.day;
}

void date::setYear(int y)
{
    if(isLegal(y, month, day))
        year = y;
    else
        printf("SetYear failed\n");
    return;
}
void date::setMonth(int m)
{
    if(isLegal(year, m, day))
        month = m;
    else
        printf("SetMonth failed\n");
    return;
}
void date::setDay(int d)
{
    if(isLegal(year, month, d))
        day = d;
    else
        printf("SetDay failed\n");
    return;
}

void date::nextDay()
{
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (!(year % 4) && (year % 100) || !(year % 400))
        days[1] = 29;
    ++day;
    if (day > days[month - 1])
    {
        ++month;
        day = 1;
    }
    if (month > 12)
    {
        ++year;
        month = 1;
    }
    return;
}

/*void date::print() const
{
    printf("%d-%d-%d\n", year, month, day);
    return;
}*/
std::ostream& operator<< (std::ostream& out, const date& A)
{
    out << A.year << '-' << A.month << '-' << A.day;
    return out;
}
std::istream& operator>> (std::istream& in, date& A)
{
    in >> A.year >> A.month >> A.day;
    return in;
}
date operator+ (date& A, int i)
{
    date B(A);
    while (i--)
        B.nextDay();
    return B;
}

