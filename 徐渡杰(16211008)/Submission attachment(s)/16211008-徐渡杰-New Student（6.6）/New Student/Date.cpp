#include "Date.h"
#include<iostream>
#include<cstdio>
using namespace std;
Date::Date(int y,int m,int d)
{
    setDate(y,m,d);//ctor
}
Date::Date(const Date &date)
{
    year=date.year;
    month=date.month;
    day=date.day;
}

Date::~Date()
{
    //dtor
}

void Date::setDate(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
    isStandard();
}

void Date::isStandard()
{
    int LMonth_day[]={31,29,31,30,31,30,31,31,30,31,30,31};
    int NMonth_day[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(year<0)
    {
        year=0;
    }
    if(month>12||month<=0)
    {
        month=1;
    }
    if(isLeapYear())
    {
        if(day<=0||day>LMonth_day[month-1])
            day=1;
    }
    else
    {
        if(day<=0||day>NMonth_day[month-1])
            day=1;
    }
}

void Date::nextDay()
{
    int LMonth_day[]={31,29,31,30,31,30,31,31,30,31,30,31};
    int NMonth_day[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(isLeapYear())
    {
        day++;
        if(day>LMonth_day[month-1])
        {
            day-=LMonth_day[month-1];
            month++;
        }
        if(month>12)
        {
            month-=12;
            year++;
        }
    }
    else
    {
        day++;
        if(day>NMonth_day[month-1])
        {
            day-=NMonth_day[month-1];
            month++;
        }
        if(month>12)
        {
            month-=12;
            year++;
        }
    }
}

Date::getDate_y()const
{
    return year;
}

Date::getDate_m()const
{
    return month;
}

Date::getDate_d()const
{
    return day;
}

Date &Date::operator++()
{
    nextDay();
    return *this;
}

Date Date::operator++(int)
{
    Date date=*this;
    nextDay();
    return date;
}

/*void Date::print()const
{
    printf("date of birth:");
    printf("%04d-%02d-%02d\n",year,month,day);
}*/
