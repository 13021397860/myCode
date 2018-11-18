#include<iostream>
#include"Date.h"
using namespace std;

Date::Date(int y,int m,int d)
{
    setDate(y,m,d);
}

Date::~Date()
{
    cout<<"is destroyed"<<endl;
}

Date::Date(const Date &t1)
{
    year=t1.year;
    month=t1.month;
    day=t1.day;
}
int Date::mxDay()
{
    switch(month)
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
        if(isLeapYear())    return 29;
        else    return 28;
    default:
        cout<<"mxDayError"<<endl;
    }
}

void Date::setDate(int y,int m,int d)
{
    year=y;
    if(year<=0)
    {
        year=1;
        cout<<"wrongYear"<<endl;
    }
    month=m;
    if(month<=0||month>=13)
    {
        month=1;
        cout<<"wrongMonth"<<endl;
    }
    day=d;
    if(day<=0||day>mxDay())
    {
        day=1;
        cout<<"wrongDay"<<endl;
    }
}


int Date::getYear() const
{
    return year;
}
int Date::getMonth() const
{
    return month;
}
int Date::getDay() const
{
    return day;
}


bool Date::isLeapYear() const
{
    if((year%4==0&&year%100!=0)||year%400==0)   return true;
    return false;
}

void Date::nextDay()
{
    day++;
    if(day>mxDay())
    {
        month++;
        day=1;
        if(month>12)
        {
            year++;
            month=1;
        }
    }
}

Date &Date::operator++()
{
    nextDay();
    return *this;
}

Date Date::operator++(int)
{
    Date before=*this;
    nextDay();
    return before;
}

ostream &operator<<(ostream &output, const Date &d)
{
    output<<d.year<<"-"<<d.month<<"-"<<d.day<<endl;
    return output;
}
