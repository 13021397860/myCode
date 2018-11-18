#include <iostream>
#include "Date.h"
#include "MyException.h"

using namespace std;

Date::Date(const int y,const int m,const int d)
{
    year = y;
    month = m;
    day = d;
    if(!checkDate())
        throw MyException("错误的日期数据！");
        /*cout<<"Wrong date"<<endl;*/
}

Date::Date(const Date &t)
{
    year = t.year;
    month = t.month;
    day = t.day;
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

void Date::setDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
    if(!checkDate())
        cout<<"Wrong date"<<endl;
}

bool Date::checkDate()
{
    if(year<=0)
    {
        year = 1;
        return false;
    }
    else if(month<=0 || month>=13)
    {
        month = 1;
        return false;
    }
    else if(day<=0 || day>maxDay())
    {
        day = 1;
        return false;
    }
    else
        return true;
}

int Date::maxDay() const
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
        if(isLeapYear())
            return 29;
        else
            return 28;
    default:
        return 0;
    }
}

bool Date::isLeapYear() const
{
    if((year%4 == 0 && year%100 != 0) || year%400 == 0)
        return true;
    else
        return false;
}

void Date::nextDay()
{
    day++;
    if(!checkDate())
    {
        month++;
        if(!checkDate())
        {
            year++;
        }
    }
}

//void Date::print() const
//{
   // cout<<year<<"."<<month<<"."<<day<<endl;
//}

ostream& operator<<(ostream& output, const Date& d)
{
    output<<d.year<<"-"<<d.month<<"-"<<d.day;
    return output;
}

Date& Date::operator++()
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

Date::~Date()
{
    //dtor
}

