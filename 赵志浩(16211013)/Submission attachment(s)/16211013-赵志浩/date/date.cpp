#include "date.h"
#include <iostream>
#include <cstdio>
using namespace std;
const int date::calendar[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
date::date(int m,int d,int y)
{
    //ctor
    month=m;
    day=d;
    year=y;
}
date::date(const date& a)
{
    month=a.month;
    day=a.day;
    year=a.year;
}
date::~date()
{
    //dtor
}
string date::toString() const
{
    char tmp[50];
    string ans;
    sprintf(tmp,"%d/%d/%d",this->month,this->day,this->year);
    ans =tmp;
    return ans;
}
int date::getYear() const
{
    return year;
}
int date::getMonth() const
{
    return month;
}
int date::getDay() const
{
    return day;
}
bool date::isLeapYear() const
{
    if(year%100==0)
        return !(year%400);
    return !(year%4);
}
bool date::yearLegal(int y) const
{
    return y>0;
}
bool date::monthLegal(int m) const
{
    return (m>=1)&&(m<=12);
}
bool date::yearLegal() const
{
    return year>0;
}
bool date::monthLegal() const
{
    return (month>=1)&&(month<=12);
}
bool date::dayLegal(int d,int m,int y) const
{
    if(d<0)   return false;
    bool yearflag;
    if(y%100==0)
        yearflag=!(y%400);
    else yearflag=!(y%4);
    if(m==2)
        return yearflag?d<=29:d<=28;
    else
        return d<=calendar[m];
}
bool date::dayLegal() const
{
    if(day<0)   return false;
    bool yearflag;
    if(year%100==0)
        yearflag=!(year%400);
    else yearflag=!(year%4);
    if(month==2)
        return yearflag?day<=29:day<=28;
    else
        return day<=calendar[month];
}
bool date::setdate(int m,int d,int y)
{
    if(yearLegal(y)&&monthLegal(m)&&dayLegal(d,m,y))
    {
        month=m;
        day=d;
        year=y;
        return true;
    }
    else
    {
        //cout<<"wrong input\n";
        return false;
    }
}
void date::nextDay()
{
    ++day;
    if(!dayLegal())
    {
        day=1;
        ++month;
    }
    if(!monthLegal())
    {
        month=1;
        ++year;
    }
}
