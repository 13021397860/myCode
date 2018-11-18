#include <iostream>
#include "date.h"
#include "myException.h"
using namespace std;

date::date(int y,int m,int d)
{
    if(y==0||m==0||d==0)
        throw myException();
    year=y;
    month=m;
    day=d;
}
date::date()
{
    year=1900;
    month=1;
    day=1;
}
date::date(const date &other)
{
    year=other.year;
    month=other.month;
    day=other.day;
}
date::~date()
{
    //delete
}
bool date::checkDate()//1 is right, 0 is wrong
{
    bool rt=true;
    if(year<0)
    {
        year=1;
        rt=false;
    }
    if(month<=0||month>12)
    {
        month=1;
        rt=false;
    }
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        if(day<=0||day>31)
        {
            day=1;
            rt=false;
        }
    }
    else if(month==2)
    {
        if(day<=0||day>28+isLeapYear())
        {
            day=1;
            rt=false;
        }
    }
    else
    {
        if(day<=0||day>30)
        {
            day=1;
            rt=false;
        }
    }
    if(!rt)
        throw myException();
    return rt;
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
    if(year%400==0)
        return true;
    else if(year%4==0)
        return true;
    else
        return false;
}
void date::nextDay()
{
    day++;
    try
    {
        checkDate();
    }
    catch(myException)
    {
        month++;
        try
        {
            checkDate();
        }
        catch(myException)
        {
            year++;
        }
    }
    /*
    if(!checkDate())
    {
        month++;
        if(!checkDate())
        {
            year++;
        }
    }
    */
}
bool date::setDate(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
    return checkDate();
}
bool date::setYear(int y)
{
    year=y;
    return checkDate();
}
bool date::setMonth(int m)
{
    month=m;
    return checkDate();
}
bool date::setDay(int d)
{
    day=d;
    return checkDate();
}
date &date::operator+(const int n)
{
    for(int i=1;i<=n;i++)
        this->nextDay();
    return *this;
}
ostream &operator<<(ostream &cout,const date &d)
{
    cout<<d.year<<"-"<<d.month<<"-"<<d.day<<endl;
}
istream &operator>>(istream &cin,date &d)
{
    cin>>d.year>>d.month>>d.day;
    try
    {
        d.checkDate();
    }
    catch(myException ex)
    {
        cout<<"Error: "<<ex.dateException();
        cout<<"The date has been set to 1-1;"<<endl;
    }
}
date &date::operator++()
{
    this->nextDay();
    return *this;
}
date date::operator++(int)
{
    date out(*this);
    this->nextDay();
    return out;
}
