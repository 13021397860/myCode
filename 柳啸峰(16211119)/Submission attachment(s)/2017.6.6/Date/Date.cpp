#include "Date.h"
#include <iostream>
#include "MyException.h" 
using namespace std;
Date::Date()
{
    year=month=day=0;
}
Date::Date(int y,int m,int d)
{
   setTime(y, m, d);
}
Date::Date(const Date &t)
{
    year=t.year;
    month=t.month;
    day=t.day;
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
void Date::setTime(int y, int m, int d)
{
    year=y;
    month=(m>0&&m<13)?m:0;
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
        day=(d>0&&d<32)?d:0;
    }
    else if(m==2)
    {
        if(isLeapYear())
        {
        	day=(d>0&&d<30)?d:0;
		}
            
        else
            day=(d>0&&d<29)?d:0;
    }
    else
    {
        day=(d>0&&d<31)?d:0;
    }
}
bool Date::isLeapYear()const 
{
    if(year%4!=0)
        return false;
    else
    {
        if(year%100==0)
            return false;
        else
            return true;
    }
}
void Date::nextDay()
{
    if(day==31)
    {
        if(month!=12)
        {
            month+=1;
            day=1;
        }
        else
        {
            year+=1;
            month=1;
            day=1;
        }
    }
    else if(day==30)
    {
        if(month==4||month==6||month==9||month==11)
        {
            day=1;
            month+=1;
        }
        else
            day+=1;
    }
    else if(day==29)
    {
        if(month==2)
        {
            month+=1;
            day=1;
        }
        else
            day+=1;
    }
    else
        day+=1;
}
/*void Date::print()const
{
    cout<<"明天是"<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
}*/
Date::~Date()
{

}


