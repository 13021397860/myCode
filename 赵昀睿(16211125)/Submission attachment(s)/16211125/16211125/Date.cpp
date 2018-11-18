#include "Date.h"
#include <iostream>

using namespace std;

static int monthDay[ 13 ] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date()
{
    month = 1;
    day = 1;
    year = 1997;
}

Date::Date( int m, int d, int y )
{
    month = m;
    day = d;
    year = y;
   /* if( !isLeagal() )
    {
        month = 1;
        day = 1;
        year = 1997;
    }*/
}

Date::Date( const Date &anoDate )
{
    month = anoDate.month;
    day = anoDate.day;
    year = anoDate.year;
}

Date::~Date()
{
    //dtor
}
//
void Date::setDate( int m, int d, int y )
{
    month = m;
    day = d;
    year = y;
    if( !isLeagal() )
    {
        throw IllegalDate();
    }
}

Date Date::getDate()const
{
    return *this;
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

bool Date::isLeapYear()const
{
    if( year % 400 == 0 )
    {
        return 1;
    }
    else if( year % 4 == 0 && year % 100 != 0 )
    {
        return 1;
    }
    else return 0;
}

void Date::nextDay()
{
    if( month !=2 && day < monthDay [ month ] )
    {
        day ++;
    }
    else if( month == 2 && day < monthDay[ month ] + isLeapYear() )
    {
        day ++;
    }
    else if( month < 12 )
    {
        month ++;
        day = 1;
    }
    else
    {
        year ++;
        month = 1;
        day = 1;
    }
}

bool Date::isLeagal()const
{
    if( year >= 1 && month >= 1 && month <= 12 && day >= 1 && day <= monthDay[ month ] + isLeapYear() )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//
ostream& operator<<( ostream &os, const Date &d )
{
    os<<d.getYear() << "-" << d.getMonth() << "-" << d.getDay();
    return os;
}

Date& Date::operator++()
{
    this -> nextDay();
    return *this;
}

Date Date::operator++( int )
{
    Date prior = *this;
    this -> nextDay();
    return prior;
}
