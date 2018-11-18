#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;


Date::Date(int mon,int da,int ye)
{
    setDate(mon,da,ye);
}

Date::Date(const Date&OtherDate)
{
    year=OtherDate.year;
    month=OtherDate.month;
    day=OtherDate.day;
}

void Date::setDate(int m,int d,int y)
{
        month=m;
        day=d;
        year=y;
}
bool Date::isLeapYear(int month,int day,int year)const
{
    if(year%4==0||year%100!=0)
    {
        return true;
    }
    else if(year%400==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Date::nextDay()
{
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            {
                if(day<31)
                {
                    day++;
                }
                else if(day==31)
                {
                    day=1;
                    month++;
                }
            }break;

        case 2:
            {
                if(isLeapYear(month,day,year)==1)
                {
                    if(day<29)
                    {
                        day++;
                    }
                    else if(day==29)
                    {
                        day=1;
                        month++;
                    }
                }
                else
                {
                    if(day<28)
                    {
                        day++;
                    }
                    else if(day==28)
                    {
                        day=1;
                        month++;
                    }
                }
            }break;

        case 12:
        {
            if(day<31)
            {
                day++;
            }
            else if(day==31)
            {
                day=1;
                month=1;
                year++;
            }
        }break;

        case 4:
        case 6:
        case 9:
        case 11:
        {
            if(day<30)
            {
                day++;
            }
            else if(day==30)
            {
                day=1;
                month++;
            }
        }break;

        default:
            break;
    }
}
int Date::getDatemonth() const
{
    return month;
}
int Date::getDateday()const
{
    return day;
}
int Date::getDateyear()const
{
    return year;
}
bool Date::legis()const
{
    if(month<=0||month>12||day<1)
    {
        return false;
    }
    else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
    {
        if(day>31)
        {
            return false;
        }
    }
    else if(month==4||month==6||month==9||month==11)
    {
        if(day>30)
        {
            return false;
        }
    }
    else if(month==2)
    {
        if(isLeapYear(month,day,year)==1)
        {
            if(day>29)
            {
                return false;
            }
        }
        else
        {
            if(day>28)
            {
                return false;
            }
        }
    }
    return true;
}
/*void Date::print()const
{
    cout<<setfill('0')<<setw(2)<<getDatemonth()<<"/"<<setw(2)<<getDateday()<<"/"<<setw(4)<<getDateyear();
    cout<<"\n";
}*/

Date Date::operator ++(int)
{
    Date test(*this);
    nextDay();
    return test;	//返回自增前的值
}

Date& Date::operator ++()
{
    nextDay();
    return *this;    //返回自增后的值
}

ostream &operator <<(ostream &output,const Date &date)
{

    output<<date.year<<"-"<<date.month<<"-"<<date.day<<endl;
    return output;
}
Date::~Date()
{
    //dtor
}
