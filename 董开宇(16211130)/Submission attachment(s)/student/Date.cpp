#include <iostream>
#include "Date.h"
#include "MyException.h"
using namespace std;

const int days[ 12 ] =  { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int m, int d, int y)
{
    year=y;
    month=m;
    day=d;
    if(!isLeagal())
    {
        throw MyException();
    }
}

Date::Date(const Date &da)
{
    year=da.year;
    month=da.month;
    day=da.day;
}

void Date::setDay( int d )
{
    if ( month == 2 && isLeapYear() )
        day = (( d <= 29 && d >= 1 ) ? d : 1);
    else
        day = (( d <= monthDays() && d >= 1 ) ? d : 1);
}

void Date::setMonth( int m )
{
    if(month >= 1 && month <= 12)
    {
        month = m;
    }
    else
        month = 1;
}

void Date::setYear( int y )
{
    year = y;
}

int Date::getDay()const
{
    return day;
}

int Date::getMonth()const
{
    return month;
}

int Date::getYear()const
{
    return year;
}

bool Date::isLeapYear()const
{
    return ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) );
}

bool Date::isLeagal()const
{
    if( year >= 1 && month >= 1 && month <= 12 && day >= 1 && day <= days[ month -1 ] + isLeapYear() )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Date::nextDay()
{
    setDay( day + 1 );
    if ( day == 1 )
    {
        setMonth( month + 1 );
        if ( month == 1 )
        {
            setYear( year + 1 );
        }
    }
}

Date& Date::operator++()
{
    nextDay();
    return *this;
}

Date Date::operator++(int)
{
    Date d=*this;
    nextDay();
    return d;
}

ostream& operator<<(ostream &output, const Date &d)
{
    output<<d.year<<"-"<<d.month<<"-"<<d.day;
    return output;
}

void Date::print()const
{
   cout << month << '-' << day << '-' << year << '\n';
}

int Date::monthDays()
{
   return (month == 2 && isLeapYear()) ? 29 : days[ month - 1 ];
}
