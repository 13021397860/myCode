#include "Date.h"
#include "MyException.h"
#include <iostream>
using namespace std;

Date& Date::operator ++ ()
{
    day += 1;
    checkDate();
    if(day==1)
    {
        month += 1;
        checkDate();
        if(month==1)
            year += 1;
    }
    return *this;
}

Date::Date(int y, int m, int d)
{
    setDate(y,m,d);
}

Date::Date(const Date &d)
{
    year=d.year;
    month=d.month;
    day=d.day;
}

void Date::checkDate()
{
    if(year<1||month<1||month>12||day<1||day>maxDay())
    {
        if(year<1)
            year=1;
        if(month<1||month>12)
            month=1;
        if(day<1||day>maxDay())
            day=1;
        MyException edate(year,month,day);
        throw edate;
    }
}

int Date::maxDay()
{
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        return 31;
    else if(month==4||month==6||month==9||month==11)
        return 30;
    else
    {
        if(isLeapYear())
            return 29;
        else if(!isLeapYear())
            return 28;
    }
    return 0;
}

void Date::setDate(int y, int m, int d)
{
    year=y;
    month=m;
    day=d;
    checkDate();
}

ostream& operator<<(ostream& os,const Date& p)
{
    os<<p.year<<"-"<<p.month<<"-"<<p.day;
    return os;
}

bool Date::isLeapYear()
{
    if(year%4!=0||(year%4==0&&year%100==0&&year%400!=0))
        return false;
    else
        return true;
}

Date::~Date()
{

}
