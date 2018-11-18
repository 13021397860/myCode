

#include "Date.hpp"
#include<iostream>
using namespace std;
Date::Date()
{
    year=1990;
    month=1;
    day=1;
    setdate(year, month, day);
}
Date::Date(const Date &date1)
{
    year=date1.year;
    month=date1.month;
    day=date1.day;
}
Date::~Date()
{
}
void Date::sety(int y)
{
    year=y;
}
void Date::setm(int m)
{
    month=m;
}
void Date::setd(int d)
{
    day=d;
}
int Date::gety() const
{
    return year;
}
int Date::getd() const
{
    return day;
}
int Date::getm() const 
{
    return month;
}
bool Date::isLeapYear(int y)
{
    if((y%4==0&&y%100!=0)||y%400==0)
        return true;
    else
        return false;
}
int Date::maxDay(int y,int m,int d)
{
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        return 31;
    else if(m==4||m==6||m==9||m==11)
        return 30;
    else if(isLeapYear(y))
        return 29;
    else
        return 28;
}
bool Date::check(int y,int m,int d)
{
    if(m>0&&m<=12)
    {
        if(d>0&&d<=maxDay(y,m,d))
            return true;
        else
        {
            //throw 1;
            return false;
        }
    }
    else
    {
        //throw 2;
        return false;
    }
}
bool Date::setdate(int y,int m,int d)
{
    if(check(y,m,d))
    {
        year=(y>0)?y:1990;
        month=check(y,m,d)?m:1;
        day=check(y,m,d)?d:1;
        return true;
    }
    else
    {
        return false;
    }
}
void Date::nextDay(int &y,int &m,int &d)
{
    if(d==maxDay(y,m,d))
    {
        if(m==12)
        {
            y+=1;
            m=1;
            d=1;
        }
        else
        {
            m+=1;
            d=1;
        }
    }
    else
        d+=1;
    year=y;
    month=m;
    day=d;
}
Date::Date(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
}
ostream  &operator <<(ostream &output, const Date &date)
{
    output<<date.year<<"-"<<date.month<<"-"<<date.day<<endl;
    return output;
}
Date& Date::operator ++()
{
    nextDay(year, month, day);
    return *this;
}
Date Date::operator ++(int)
{
    Date temp(year,month,day);
    nextDay(year, month, day);
    return temp;
}
