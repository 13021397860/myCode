#include "date.h"
#include <iostream>
#include "MyException.h"
using namespace std;
date::date(int m, int d, int y)
{
    setDate(m,d,y);
}

date::date(const date& d)
{
    month = d.month;
    day = d.day;
    year = d.year;
}

date::~date()
{

}


void date::setDate(int m,int d,int y)
{
    year = y;
    day = d;
    month = m;
}

void date::setYear( int y )
{
    year = y;
}

void date::setDay( int d )
{
    day = d;
}

void date::setMonth(int m)
{
    month = m;
}

int date::getMonth()const
{
    return month;
}

int date::getDay()const
{
    return day;
}

int date::getYear()const
{
    return year;
}

bool date::isLeapYear()
{
    if(year%400 == 0)
    {
        return true;
    }
    else if(year%100 == 0)
    {
        return  false;
    }
    else if(year%4 == 0)
    {
        return true;
    }
    else {
        return false;
    }
}

void date::nextDay()
{
    int judge1,judge2;
    judge1 = isLeapYear();
    if(judge1)
    {
        if(day == judgeMonth(month))
            judge2 = 1;
        else judge2 = 0;
    }
    else
    {
        if(day == judgeMonth(month))
            judge2 = 1;
        else judge2 = 0;
    }
    if(judge2)
    {
        day = 1;
        if(month == 12)
        {
            month = 1;
            year++;
        }
        else
        {
            month++;
        }
    }
    else
    {
        day++;
    }
}

int date::judgeMonth(int m)
{
    int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(isLeapYear())
    {
        day[1] = 29;
    }
    return day[m-1];
}

bool date::judgeInput()
{
    if(day<1||day>31||month<1||month>12||day>judgeMonth(month))
    {
        throw MyException(0);
        return false;
    }
    else
    {
        return true;
    }
}

date& operator++(date& c)
{
    c.nextDay();
    return c;
}
date operator++(date& c,int)
{
    date d(c);
    c.nextDay();
    return d;
}
