#include "Date.h"
#include<iostream>
std::ostream&operator<<(std::ostream& o,const Date& a)
{
        o<<a.getYear()<<"-"<<a.getMonth()<<"-"<<a.getDay();
        return o;
}
std::istream&operator<<(std::istream& i,Date &a)
{
    int y1,m1,d1;
    i>>y1>>m1>>d1;
    a.setDate(y1,m1,d1);
    return i;
}
Date::Date()
{
}
Date::Date(int y=2000,int m=1,int d=1)
{  
	setDate(y,m,d);
}

Date::Date(const Date &D)
{
    year=D.year;
    month=D.month;
    day=D.day;
}
Date::~Date()
{
}
void Date::setDate(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
}
bool Date::judgement()const
{
    if(year<1||month<1||month>12||day<1||day>31) return false;
    if(isLeapYear()&&month==2&&day>29) return false;
    if(!isLeapYear()&&month==2&&day>28) return false;
    if((month==4||month==6||month==9||month==11)&&day>30) return false;
    return true;
}
void Date::nextDay()
{
    day++;
    if(judgement())
        return;
    else
    {
        day=1;
        month++;
        if(judgement())
            return;
        else
        {
            month=1;year++;
        }
    }
}
Date Date::operator ++ (int)
{
    Date before=*this;
    nextDay();
    return before;
}
Date& Date::operator++()
{
    nextDay();
    return *this;
}
