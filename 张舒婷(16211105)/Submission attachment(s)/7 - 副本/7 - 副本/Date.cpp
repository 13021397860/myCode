#include "Date.h"
#include "MyException.h"
#include<iostream>
using namespace std;

Date::Date()
{
    year=1900;
    month=1;
    day=1;
}
Date::Date(int y,int m,int d)
{
    setDate(y,m,d);
}

Date::~Date()
{
    //dtor
}

Date::Date(Date const &d)
{
    setDate(d.year,d.month,d.day);
}

void Date::setDate(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;

    if(!checkdate())
    {
        throw MyException(DATE_INVALID);
    }
}

bool Date::checkdate()
{
    bool g=true;
    if((month>12)||(month<1))
    {
        g=false;
    }
    if(day>maxday())
    {
        g=false;
    }

    return g;
}

int Date::maxday() const
{
    switch(month){
    case(1):
    case(3):
    case(5):
    case(7):
    case(8):
    case(10):
    case(12):
        return 31;
    case(4):
    case(6):
    case(9):
    case(11):
        return 30;
    case(2):{if(isLeapYear()) return 29;else return 28;}
    }
}
bool Date::isLeapYear() const
{
    if(year%400==0||(year%4==0&&year%100!=0))
        return true;
    else
        return false;
}

Date &Date::operator++()
{
    nextDay();
    return *this;
}

Date Date::operator++(int)
{
    Date d(*this);
    nextDay();
    return d;
}
/*void Date::print() const
{
    cout<<year<<"-"<<month<<"-"<<day<<"\n";
}*/

ostream& operator<<(ostream& output,const Date&d)
{
    output<<d.year<<"-"<<d.month<<"-"<<d.day<<"\n";
    return output;
}

void Date::nextDay()
{
    day++;
    if(!checkdate())
    {
        month++;
        if(!checkdate())
            year++;
    }
    cout<<year<<"-"<<month<<"-"<<day<<"\n";
}
