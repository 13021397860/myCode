#include <iostream>
#include "Myexception.h"
#include "Date.h"
using namespace std;

Date::Date()
{
    day=1;
    month=1;
    year=2000;
}

Date::Date(int _month,int _day,int _year)
{
    day=_day;
    month=_month;
    year=_year;
    if(!CheckDate())
        throw MyException(DATE_INVALID);
}

Date::Date(const Date& a)
{
    day=a.day;
    month=a.month;
    year=a.year;
    if(!CheckDate())
        cout<<"wrong date! we have set the date right."<<endl;
}

Date::~Date()
{
    //cout <<"Destruct the object"<<endl;
}

void Date::MaxDay()
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
        maxday=31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxday=30;
        break;
    case 2:
        if (isLeapYear())
            maxday=29;
        else
            maxday=28;
    }
}

bool Date::CheckDate()
{
    MaxDay();
    if (day<1||day>maxday)
    {
        day=1;
        return false;
    }
    if (month<1||month>12)
    {
        month=1;
        return false;
    }
    return true;
}

void Date::setDate(const int m,const int d,const int y)
{
        day=d;
        month=m;
        year=y;
}

int Date::getday() const
{
    return day;
}

int Date::getmonth() const
{
    return month;
}

int Date::getyear() const
{
    return year;
}

bool Date::isLeapYear()
{
    if ((year%4==0&&year%100!=0)||(year%400==0)) return true;
    else
        return false;
}

void Date::nextDay()
{
    Date::MaxDay();
    if (day<maxday)
    {
        day++;
    }
    else
    {
        day=1;
        month++;
        if (month>12)
        {
            month=1;
            year++;
        }
    }
}

ostream& operator<<(ostream& output, const Date& date)
{
    output<<date.year<<"-"<<date.month<<"-"<<date.day;
}

Date& Date::operator++()
{
    this->nextDay();
    return *this;
}

Date Date::operator++(int)
{
    Date date(*this);
    this->nextDay();
    return date;
}
