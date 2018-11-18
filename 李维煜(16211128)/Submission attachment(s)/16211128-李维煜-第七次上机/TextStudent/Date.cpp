#include<iostream>
#include "Date.h"
using namespace std;

ostream &operator<<(ostream &output,const Date &date)
{
    output<<date.year<<"-"<<date.month<<"-"<<date.day;
    return output;
}

Date &Date::operator++()//Ç°ÖÃ
{
    Date::nextDay();
    return *this;
}

Date Date::operator++(int)//ºóÖÃ
{
    Date a=*this;
    Date::nextDay();
    return a;
}

Date::Date( int y, int m, int d )
{
        if(d<=0)
        {
            throw MyException();
        }
        else if(m<=0)
        {
            throw MyException();
        }
        else if(y<=0)
        {
            throw MyException();
        }//ctor
    month=m;
    day=d;
    year=y;
}
int Date::DateGetDay()
{
	return day;
}
int Date::DateGetMonth()
{
	return month;
}
int Date::DateGetYear()
{
	return year;
}
void Date::DateSet( int y, int m, int d)
{
    year=y;
    month=m;
    day=d;
    Date::checkDate();
}
bool Date::isLeapYear()
{
    if (year%4==0||year%400==0)
    {
        return true;
    }
    else
        return false;
}
void Date::checkDate()
{
        if(( month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day>31))
    {
        month++;
        day=1;
        if(month>12)
        {
            year++;
            month=1;
        }
    }
    else if(month==2)
    {
        if(Date::isLeapYear()&&day>29)
        {
            month++;
            day=1;
        }
        else if(day>28)
        {
            month++;
            day=1;
        }
    }
    else
    {
        if(day>30)
        {
            day=1;
            month++;
            if(month>12)
            {
                year++;
                month=1;
            }
        }
    }
}
void Date::nextDay()
{
    day=day+1;
    Date::checkDate();
}
Date::Date()
{
    month=1;
    day=1;
    year=1;
}
Date::Date(const Date &another)
{
    month=another.month;
    day=another.day;
    year=another.year;
}
Date::~Date()
{
    //dtor
}
