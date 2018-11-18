#include "Date.h"
#include <iostream>
#include <cstdio>
#include "MyException.h"
using namespace std;
Date::Date(int y,int m,int d)
{
    setDate(d,m,y);
}
Date::~Date()
{
    //dtor
}
void Date::setDate(int d,int m,int y)
{
    Date::day=d;
    Date::month=m;
    Date::year=y;
    if(check()==0)
    {
        throw MyException(DATE_INVALID);
    }
}
void Date::print() const
{
    if(check())
    cout<<Date::year<<"."<<Date::month<<"."<<Date::day<<endl;
}
void Date::nextDay()
{
    if(check())
    {if(Date::month==2)
    {
        if(Date::LeapYear())
        {
            if(day==29) {day=1;month++;}
            else day++;
        }
        else
        {
            if(day==28) {day=1;month++;}
            else day++;
        }

    }
    else if(Date::month==1 or Date::month==3 or Date::month==5  or Date::month==7 or Date::month==8 or Date::month==10)
    {
        if(Date::day==31) {Date::month++;Date::day=1;}
        else {Date::day++;}
    }
    else if(Date::month==4 or Date::month==6 or Date::month==9  or Date::month==11)
    {
        if(Date::day==30) {Date::month++;Date::day=1;}
        else {Date::day++;}
    }
    else if(Date::month==12)
    {
        if(Date::day==31) {Date::year++;Date::day=1;Date::month=1;}
        else{Date::day++;}
    }
}
}
bool Date::LeapYear() const
{
 if(year%4==0)
 {
     if(year%100==0 && year%400==0) return 1;
     if(year%100!=0) return 1;
 }
 return 0;
}
bool Date::check() const
{
    if(year>0)
    {
        if(month==1 or month==3 or month==5 or month==7 or month==8 or month==10 or month==12)
        {
            if(day>0 && day<=31) return 1;
        }
        if(month==4 or month==6 or month==9 or month==11)
        {
            if(day>0 && day<=30) return 1;
        }
        if(month==2 && Date::LeapYear())
        {
            if(day>0 && day<=29) return 1;
        }
        if(month==2 && ~Date::LeapYear())
        {
            if(day>0 && day<=28) return 1;
        }
    }
    return 0;
}

Date::Date(Date &date)
{
    year=date.year;
    month=date.month;
    day=date.day;
}
std::ostream& operator << (ostream& out, const Date& c)
{
    out<<c.getYear()<<"-"<<c.getMonth()<<"-"<<c.getDay()<<endl;
    return out;
}

