#include <cstdio>
#include "Date.h"
#include "MyException.h"
static int mday[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
Date::Date():year(0),month(1),day(1)
{
    //ctor
}
Date::Date(const Date& T){
    year=T.year;
    month=T.month;
    day=T.day;
}
Date::Date(int _year,int _month,int _day):year(_year),month(_month),day(_day)
{
    if (!check()) {year=0;month=day=1; puts("Initializing~~");}
    //ctor
}
Date::~Date()
{
    //dtor
}
bool Date::setTime(int _year=0,int _month=1,int _day=1)
{
    int y1=year,m1=month,d1=day;
    year=_year;
    month=_month;
    day=_day;
    if (!check())
    {
        year=y1;
        month=m1;
        day=d1;
        throw MyException(DATE_INVALID);
    }
    return 1;
}
bool Date::setYear(int _year)
{
    int y1=year;
    year=_year;
    if (!check()) {year=y1;return 0;}
    return 1;
}
bool Date::setMonth(int _month)
{
    int m1=month;
    month=_month;
    if (!check()) {month=m1;return 0;}
    return 1;
}
bool Date::setDay(int _day)
{
    int d1=day;
    day=_day;
    if (!check()) {day=d1;return 0;}
    return 1;
}
int Date::getYear()const{return year;}
int Date::getMonth()const{return month;}
int Date::getDay()const{return day;}
bool Date::isLeapYear()const
{
    return year%100==0?year%400==0:year%4==0;
}
void Date::nextDay()
{
    day++;
    if (isLeapYear()) mday[2]=29;
    else mday[2]=28;
    if (day>mday[month])
    {
        month++;
        day=1;
    }
    if (month>12)
    {
        year++;
        month=1;
    }
}
ostream &operator <<(ostream&out,const Date &A)
{
    out<<A.year<<"-"<<A.month<<"-"<<A.day;
    return out;
}
istream &operator >>(istream&in,Date &A)
{
    puts("日期(年 月 日):");
    int y,m,d;
    in>>y>>m>>d;
    A.setTime(y,m,d);
    return in;
}
Date& Date::operator++()
{
    nextDay();
    return (*this);
}
Date Date::operator++(int)
{
    Date old(*this);
    nextDay();
    return old;
}
Date Date::operator+(int _number)
{
    while (_number--) nextDay();
    return (*this);
}
Date Date::operator+=(int _number)
{
    while (_number--) nextDay();
    return (*this);
}
bool Date::check()
{
    if (isLeapYear()) mday[2]=29;
    else mday[2]=28;
    if (month>12||month<1) return 0;
    if (day>mday[month]||day<1) return 0;
    return 1;
}
