#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int m, int d, int y)
{
    setDate(m,d,y);
}

Date::Date()
{
    setDate(1,1,1990);
}

Date::Date(const Date &a)
{
    month = a.month;
    day = a.day;
    year = a.year;
}

Date &Date::operator++()//++Date
{
    nextday();
    return *this;
}

Date Date::operator++( int )//date++
{
    Date temp = *this;
    nextday();
    return temp;
}

const Date &Date::operator+=(int additionalDays )
{
    for(int i=0; i < additionalDays; i++) nextday();

    return *this;
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


const bool Date::isLeapYear()
{
    if(year % 4 != 0) return false;
    else if(year % 100 == 0)
    {
        if(year % 400 != 0) return false;
    }
    return true;

}

const int Date::monthDays( int m)
{
    //存储好各个月份的天数
    if(isLeapYear())
    {
        int days[13]= {0, 31,28,31,30,31,30,31,31,30,31,30,31};
        return days[m];

    }
    else
    {
        int days[13]= {0, 31,29,31,30,31,30,31,31,30,31,30,31};
        return days[m];
    }


}

const void Date::setDate(int m, int d,int y) throw(MyException)
{
        if(y < 0|| m < 0 || m > 12 || d <= 0|| d > monthDays(m))
        {
            MyException b(1);
            year = month = day =1;
            throw b;
        }
        year = (y >= 0 && y <= 9999)? y:1990;
        month = (m < 13 && m > 0) ? m:1;
        if(y < 0 || y > 9999 ||m > 12 || m < 1 ) day = 1;
        else
        {
            if(d <= 0 || d > monthDays(m))
            {
                day = 1;
                return;
            }
            else
            {
                day = d;
            }
        }
}

void Date::nextday()
{
    if(day < monthDays( month))
    {
        day++;
        return;
    }
    else
    {
        day = 1;
        if(month < 12 )
        {
            month++;
            return;
        }
        else
        {
            month = 1;
            year++;
            return;
        }
    }
}

Date::~Date()
{
    //dtor
}

ostream &operator<<(ostream &output, const Date &d)
{
    output << d.year<< "-" << d.month<<"-"<<d.day;
    return output;
}
