#include "Date.h"
#include <cstdio>
#include "Exception.h"
#include <bits/stdc++.h>
int daymonth[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
Date::Date(int y,int m,int d)
{
    set(y,m,d);
    try
    {
        if(!check())
    {
        printf("日期不合法\n");
        set(1,1,1);
        throw(Illegal_Date_Exception());
    }
    }
    catch(Exception &x)
    {
        cout<<x.what()<<endl;
        system("pause");
    }
}
Date::Date(const Date& x)
{
    set(x.year,x.month,x.day);
}
Date::~Date()
{
//    printf("析构函数被调用\n");
}
int Date::getYear()const
{
    return year;
}
int Date::getMonth()const
{
    return month;
}
int Date::getDay()const
{
    return day;
}
void Date::setYear(const int &y)
{
    year=y;
    if(!check())
        year=1;
}
void Date::setMonth(const int &m)
{
    month=m;
    if(!check())
        month=1;

}
void Date::setDay(const int &d)
{
    day=d;
    if(!check())
        day=1;
}
void Date::set(const int &y,const int &m,const int &d)
{
    year=y;month=m;day=d;
    try
    {if(!check())
    {
//        printf("The date is illegal\n");

        year=month=day=1;throw(Illegal_Date_Exception());

    }

    }
    catch(Exception &x)
    {
        cout<<x.what()<<endl;
        system("pause");
    }
}
bool Date::isLeapYear()
{
    if(year<0)
        year++;
    bool flag=(year%4==0&&(year%100!=0||year%400==0));
    if(year<=0)
        year--;
    return flag;
}
void Date::nextDay()
{
    day++;
    int st=0;
    if(isLeapYear())
        st=1;
    if(day>daymonth[st][month])
    {
        month++;
        day=1;
    }
    if(month>12)
    {
        year++;
        if(year==0)
            year++;
        month=1;
    }
}
bool Date::check()
{
    int st=0;
    if(year==0)
        return false;
    if(isLeapYear())
        st=1;
    return month>0&&month<13&&day>0&&day<=daymonth[st][month];
}
Date& Date::operator++()
{
    nextDay();
    return *this;
}
Date& Date::operator++(int)
{
    Date *tem;
    tem=new(Date);
    *tem=*this;
    nextDay();
    return *tem;
}
Date& Date::operator+(int x)
{
    Date *tem;
    tem=new(Date);
    *tem=*this;
    while(x--)
    {
        (*tem)++;
    }
    return *tem;
}
