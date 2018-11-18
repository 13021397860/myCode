#include "Date.h"
#include"MyException.h"
#include<iostream>
using namespace std;
int MonthArray[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
int MonthArray1[13]= {0,31,29,31,30,31,30,31,31,30,31,30,31};
Date::Date()
{
    month=1;
    day=1;
    year=2000;
    //ctor
}
Date::Date(int y,int m,int d)
{
    Date::setDate(y,m,d);
}
Date::Date(const Date &c)
{
    month=c.month;
    day=c.day;
    year=c.year;
}
Date::~Date()
{
    //dtor
}
/*void Date::showDate()
{
    cout<<year<<'/'<<month<<'/'<<day<<"\n";
}
void Date::print()
{
    cout<<year<<'/'<<month<<'/'<<day<<"\n";
}*/
bool Date::isLeapYear()
{
    if(year%400==0)
    {
        return 1;
    }
    if(year%100!=0&&year%4==0)
        return 1;
    return 0;
}

void Date::setDate(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
    if(isLeapYear()==0)
    {
        if(y<=0||m<1||m>12||MonthArray[m]<day)
        {
            throw MyException(1);
            //    cout<<"the data is not right,the date has been reset,please check your input"<<"\n";
            //    year=2000;
            //    month=1;
            //  day=1;
        }

    }
    else if(isLeapYear()==1)
    {
        if(y<=0||m<1||m>12||MonthArray1[m]<day)
        {
            throw MyException(1);
            //   cout<<"the data is not right,the date has been reset,please check your input"<<"\n";
            //    year=2000;
            //    month=1;
            //   day=1;
        }
    }
}
int Date::getDay()
{
    return day;
}
int Date::getMonth()
{
    return month;
}
int Date::getYear()
{
    return year;
}
void Date::nextDay()
{
    if(isLeapYear()==0)
    {
        if(MonthArray[month]==day&&month==12)
        {
            year++;
            month=1;
            day=1;

        }
        else if(MonthArray[month]==day&&month!=12)
        {
            month++;
            day=1;
        }
        else
        {
            day++;
        }
    }
    else
    {
        if(MonthArray1[month]==day&&month==12)
        {
            year++;
            month=1;
            day=1;

        }
        else if(MonthArray1[month]==day&&month!=12)
        {
            month++;
            day=1;
        }
        else
        {
            day++;
        }
    }
}
Date& Date::operator ++ ()
{
    //前置++
    this->nextDay();
    return *this;
}
Date Date::operator ++ (int)
{
    //后置
    //期望使用方式 a++
    Date tmp = *this;
    this->nextDay();
    return tmp;
}
