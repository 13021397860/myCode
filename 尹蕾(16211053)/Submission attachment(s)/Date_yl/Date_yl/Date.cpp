#include "Date.h"
#include <iostream>
using namespace std;
Date::Date(int y,int m,int d)
{
    setDate(y,m,d);
    //ctor
}
Date::Date(const Date &d2)
{
    setDate(d2.year,d2.month,d2.day);
}
Date::~Date()
{
    //dtor
}
bool Date::isLeapYear()const
{
    if((year%4==0&&year%100!=0)||(year%400==0&&year%100==0))
        return true;
    else
        return false;
}
bool Date::dateCheck()
{
    bool t=true;
    if(year<1||month<1||month>12||day<1||day>maxday())
    {
        t=false;
        year=1;
        month=1;
        day=1;
    }
    return t;
}
void Date::setDate(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
    if(!dateCheck())
    {
        throw Exception(DATE_INVALID);
    }
}

void Date::setDate(const Date & date)
{
    year=date.year;
    month=date.month;
    day=date.day;
}

int Date::getYear()const
{
    return year;
}
int Date::getMonth()const
{
    return month;
}
int Date::getDay()const
{
    return day;
}

ostream& operator<<(ostream &output, const Date &d)
{
    output<<d.getYear()<<"-"<<d.getMonth()<<"-"<<d.getDay();
    return output;
}

Date& Date::operator++()
{
    nextDay();
    return *this;
}

Date Date::operator++(int)
{
    Date d=*this;
    nextDay();
    return d;
}

int Date::maxday()const
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if(isLeapYear()) return 29;
        else return 28;
    default:
        return 0;
    }
}

void Date::nextDay()
{
    day++;
    if(day>maxday())
    {
        day=1;
        month++;
    }
    if(month>12)
    {
        month=1;
        year++;
    }
}
