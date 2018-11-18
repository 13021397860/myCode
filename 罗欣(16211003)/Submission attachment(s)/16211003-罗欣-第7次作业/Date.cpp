#include<iostream>
#include "Date.h"
using namespace std;

ostream& operator<<(ostream& cout,const Date &dd)
{
    cout<<dd.year<<'-'<<dd.month<<'-'<<dd.day<<endl;
    return cout;
}


Date::Date()
{
    year=2000;
    month=1;
    day=1;
    //ctor
}

Date::Date(const Date &data)
{
    year=data.GetYear();
    month=data.GetMonth();
    day=data.GetDay();
}

Date::~Date()
{
    //dtor
}

void Date::SetDate(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
}

bool Date::IsLegalDate()
{
    /*if(y>0)
    {
        year=y;
    }
    */
    if(year<=0)
    {
        return 0;
    }
    /*
    if(m>0 and m<13)
    {
        month=m;
    }
    */
    if(month<=0 or month>=13)
    {
        return 0;
    }
    if(day<0)
    {
        return 0;
    }
    else if(day>31 and (month==1 or month==3 or month==5 or month==7 or month==8 or month==10 or month==12))
    {
        return 0;
    }
    else if(day>30 and (month==4 or month==6 or month==9 or month==11))
    {
        return 0;
    }
    else if(day>28 and month==2 and !isLeapyear())
    {
        return 0;
    }
    else if(day>29 and month==2 and isLeapyear())
    {
        return 0;
    }
    /*
    else
    {
        day=d;
    }
    */
    return 1;
}

int Date::GetYear()const
{
    return year;
}
int Date::GetMonth()const
{
    return month;
}
int Date::GetDay()const
{
    return day;
}

bool Date::isLeapyear()
{
    if(year%4==0 and year%100!=0)
    {
        return 1;
    }
    else if(year%400==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Date::PrintIsLeapeyear()
{
    if(isLeapyear())
    {
        cout<<"A LEAP YEAR"<<endl;
    }
    else if(!isLeapyear())
    {
        cout<<"NOT A LEAP YEAR"<<endl;
    }
}

void Date::nextDay()
{
    if(day==31 and (month==1 or month==3 or month==5 or month==7 or month==8 or month==10))
    {
        day=1;
        month++;
    }
    else if(day==29 and month==2 and isLeapyear())
    {
        day=1;
        month++;
    }
    else if(day==28 and month==2 and !isLeapyear())
    {
        day=1;
        month++;
    }
    else if(day==30 and (month==4 or month==6 or month==9 or month==11))
    {
        day=1;
        month++;
    }
    else if(day==31 and month==12)
    {
        day=1;
        month=1;
        year++;
    }
    else
    {
        day++;
    }
}

void Date::PrintDate()const
{
    cout<<year<<'-'<<month<<'-'<<day<<endl;
}





Date& Date::operator++()
{
    this->nextDay();
    return *this;
}
const Date Date::operator++(int)
{
    Date tmp=*this;
    this->nextDay();
    return tmp;
}
