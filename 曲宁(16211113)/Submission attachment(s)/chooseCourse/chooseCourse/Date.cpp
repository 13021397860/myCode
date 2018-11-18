#include<iostream>
#include<string>
#include "Date.h"
using namespace std;

const int Date::days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

Date::Date(int y,int m,int d)
{
    setDate(y,m,d);
}

Date::Date()
{
    month=2;
    day=1;
    year=1998;
}

Date::Date(const Date &t)
{
    month=t.month;
    day=t.day;
    year=t.year;
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

bool Date::isLeapYear(int testYear)
{
    if(testYear%400==0||(testYear%100!=0&&testYear%4==0))
        return true;
    else
        return false;
}


void Date::nextDay()
{
    if(day<days[month]) day++;
    if(day==days[month])
    {
        day=1;
        if(month<12) {month++;}
        else if(month==12) {month==1;year++;}
    }
}

void Date::setDate(int y,int m,int d)
{
    year=(y>=0)?y:0;
    month=(m>=1&&m<=12)?m:1;
    if(month==2&&isLeapYear(year))
        day=(d>=1&&d<=29)?d:1;
    else
        day=(d>=1&&d<=days[month])?d:1;
}

Date &Date::operator++()
{
    helpIncrement();
    return *this;
}

Date Date::operator++(int )
{
    Date temp = *this;
    helpIncrement();
    return temp;
}

const Date &Date::operator+=(int additionDays)
{
    for(int i=0;i<additionDays;i++)
        helpIncrement();
    return *this;
}

bool Date::endOfMonth(int testDay)const
{
    if(month==2&&isLeapYear(year))
        return testDay==29;
    else
        return testDay==days[month];
}

void Date::helpIncrement()
{
    if(!endOfMonth(day))
        day++;
    else
        if(month<12)
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

ostream &operator<<(ostream &output,const Date &d)
{
    output<<d.year<<"-"<<d.month<<"-"<<d.day<<endl;
    return output;
}
Date::~Date()
{
    //dtor
}
