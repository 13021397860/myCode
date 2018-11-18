#include<iostream>
#include "Date.h"
#include "MyException.h"

using namespace std;

/* ------ begin of Date ---------*/

Date::Date()
{
    year    = 1900;
    month   = 1;
    day     = 1;
}

Date::Date(int y, int m, int d)
{
    try
    {
        setDate(y, m, d);
    }
    catch(...)
    {
        //e.what();
    }
}

Date::Date(const Date& _copydate)
{
    year    = _copydate.year;
    month   = _copydate.month;
    day     = _copydate.day;
}

Date::~Date()
{
    //cout << "Date " << year << month << day << " has been deleted.\n";
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

void Date::setDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
    try
    {
        checkDate();
    }
    catch(MyException e)
    {
        cout << "Exception: " << e.what() << endl;
    }
}

void Date::setYear(int y)
{
    year = y;
    try
    {
        checkDate();
    }
    catch(MyException e)
    {
        cout << "Exception: " << e.what() << endl;
    }
}

void Date::setMonth(int m)
{
    month = m;
    try
    {
        checkDate();
    }
    catch(MyException e)
    {
        cout << "Exception: " << e.what() << endl;
    }
}

void Date::setDay(int d)
{
    day = d;
    try
    {
        checkDate();
    }
    catch(MyException e)
    {
        cout << "Exception: " << e.what() << endl;
    }
}

int Date::maxDay() const
{
    int dayofmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month != 2)
    {
        return dayofmonth[month - 1];
    }
    else
    {
        if(!isLeapYear()) return 28;
        else return 29;
    }
}

bool Date::checkDate()
{
    bool islegal = true;
    if(year < 1)
    {
        year = 1900;
        islegal = false;
    }
    if(month < 1 or month > 12)
    {
        month = 1;
        islegal = false;
    }
    if(day < 1 or day > maxDay())
    {
        day = 1;
        islegal = false;
    }
    if(!islegal) throw MyException("wrong date");
    return islegal;
}

bool Date::isLeapYear() const
{
    if(((year % 4 == 0) and (year % 100)) or year % 400 == 0) return true;
    else return false;
//    if(year % 4) return false;
//    else
//    {
//        if(year % 400 == 0) return true;
//        else if(year % 100 == 0) return false;
//        else return true;
//    }
}

void Date::nextDay()
{
    day++;
    if(day > maxDay())
    {
        month++;
        day = 1;
        if(month > 12)
        {
            year++;
            month = 1;
        }
    }
}
/*
void Date::print() const
{
    cout << year << "/" << month << "/" << day;
}
*/
Date& Date::operator ++ ()
{
    nextDay();
    return *this;
}

Date Date::operator ++ (int)
{
    Date _d = *this;
    nextDay();
    return _d;
}

ostream& operator << (ostream& os, const Date &_d)
{
    return os << _d.getYear() << "/" << _d.getMonth() << "/" << _d.getDay();
}

istream& operator >> (istream &is, Date &_d)
{
    int y, m, d;
    is >> y >> m >> d;
    _d.setDate(y, m, d);
    return is;
}

Date Date::operator + (int _d)
{
    Date d = *this;
    int i = 0;
    for(; i < _d; i++) d.nextDay();
    return d;
}

/* ------ end of Date ------------*/
