#include<iostream>
#include "Date.h"
#include "MyException.h"
using namespace std;
Date::Date(int m, int d, int y)
{
    setDate(m,d,y);
}
Date::~Date()
{

}
Date::Date(const Date &d)
{
    year=d.getYear();
    month=d.getMonth();
    day=d.getDay();
}
void Date::setDate(int m, int d, int y)
{
    month=m;
    day=d;
    year=y;
}
int Date::islegal(int m, int d, int y)
{
    bool flag=1;
    if(m<1||m>12)
        flag=0;
    if(d<1||d>31)
        flag=0;
    if(y<1)
        flag=0;
    if(!isLeapYear(y))
        if(m==2&&d>28)
            {flag=0;}
    else if(isLeapYear(y))
        if(m==2&&d>29)
            {flag=0;}
    if((m==4||m==6||m==9||m==11)&&(d>30))
        {flag=0;}
    if(flag==0)
        throw MyException(DATE_INVALID);
    else
        return 1;
}
int Date::getMonth()const
{
    return month;
}
int Date::getDay()const
{
    return day;
}
int Date::getYear()const
{
    return year;
}
bool Date::isLeapYear(int y)
{
    if(y%400==0||(y%400!=0&&y%100!=0&&y%4==0))
        return true;
    return false;
}
void Date::nextDay()
{
    if((month==4||month==6||month==9||month==11)&&(day==30))
    {
        month++;
        day=1;
    }
    else if((month==1||month==3||month==5||month==7||month==8||month==10)&&(day==31))
    {
        month++;
        day=1;
    }
    else if(month==12&&day==31)
    {
        year++;
        month=1;
        day=1;
    }
    else if(isLeapYear(year)&&month==2&&day==29)
    {
        month++;
        day=1;
    }
    else if((!isLeapYear(year))&&month==2&&day==28)
    {
        month++;
        day=1;
    }
    else
        day++;
}
