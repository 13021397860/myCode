#include "Date.h"
#include "MyException.h"
#include<iostream>
using namespace std;
int _month[2][13]= {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
Date::Date(const int y,const int m,const int d)
{
    //ctor
    year=y;
    month=m;
    day=d;
    if(!testValid())
    {
        year=1970;
        month=1;
        day=1;
    }
}

Date::Date(const Date &t)
{
    year=t.year;
    month=t.month;
    day=t.day;
}

Date::~Date()
{
    //dtor
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

bool Date::setDate(const int y,const int m,const int d)
{
    year=y;
    month=m;
    day=d;
    if(testValid())
    {
        return true;
    }
    else
    {
        MyException ex;
        ex.InvalidDate();
        throw ex;
        return false;
    }
}

/*bool Date::setYear(const int y)
{
    year=y;
    if(testValid())
    {
        return true;
    }
    else
    {
        MyException ex;
        ex.InvalidDate();
        throw ex;
        year=1970;
        month=1;
        day=1;
        return false;
    }
}

bool Date::setMonth(const int m)
{
    month=m;
    if(testValid())
    {
        return true;
    }
    else
    {
        MyException ex;
        ex.InvalidDate();
        throw ex;
        year=1970;
        month=1;
        day=1;
        return false;
    }
}

bool Date::setDay(const int d)
{
    day=d;
    if(testValid())
    {
        return true;
    }
    else
    {
        MyException ex;
        ex.InvalidDate();
        throw ex;
        year=1970;
        month=1;
        day=1;
        return false;
    }
}
*/
bool Date::isLeapYear() const
{
    if(year%4!=0)
    {
        return false;
    }
    else if(year%100==0&&year%400!=0)
    {
        return false;
    }
    return true;
}


void Date::nextDay()
{
    int type=isLeapYear();
    if(day+1<=_month[type][month])
    {
        day++;
    }
    else
    {
        if(month!=12)
        {
            month++;
            day=1;
        }
        else
        {
            year++;
            month=1;
            day=1;
        }
    }
}

Date& Date::operator++()
{
    nextDay();
    return *this;
}

Date Date::operator++(int k)
{
    Date tmp=*this;
    nextDay();
    return tmp;
}

/*void Date::print() const
{
    cout<<year<<'.'<<month<<'.'<<day<<"\n";
}*/

ostream & operator <<(ostream &os,const Date& d)
{
    os<<d.year<<'-'<<d.month<<'-'<<d.day;
    return os;
}

bool Date::testValid() const
{
    int type=isLeapYear();
    if(year>0&&month>0&&month<=12&&day>0)
    {
        if(day<=_month[type][month])
        {
            return true;
        }
    }
    return false;
}

