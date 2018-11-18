#include "date.h"
#include<iostream>
#include "Exception.h"
using namespace std;
Date::Date(const int y,const int m,const int d)
{
    month=m;
    day=d;
    year=y;
    //ctor
    if(!check())
    {
        throw Exception(Date_Invalid);
    }
}
Date::Date()
{
    month=1;
    day=1;
    year=2000;
}
Date::Date(const Date &t)
{
    year=t.year;
    month=t.month;
    day=t.day;
}
Date::~Date()
{
    //dtor
}

/*void Date::print()const
{
    cout<<month<<'/'<<day<<'/'<<year<<endl;
}*/
ostream& operator<<(ostream& output,Date& x)
{
    output<<x.month<<'/'<<x.day<<'/'<<x.year<<endl;
    return output;
}
istream& operator>>(istream& input,Date& x)
{
    input>>x.year>>x.month>>x.day;
    return input;
}
bool Date::isLeapYear()const
{
    if(year%4!=0||(year%100==0&&year%400!=0))
        return false;
    else
        return true;
}
bool Date::check()
{
    int monthday[2][12]= {31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
    if(year<0||month<=0||month>12||day<=0)
        return false;
    if(isLeapYear())
    {
        if(day>monthday[1][month-1])
            return false;
    }
    else
    {
        if(day>monthday[0][month-1])
            return false;
    }
    return true;
}
Date &Date::operator ++()
{
    nextDay();
    return *this;
}
Date &Date::operator ++(int)
{
    Date d(*this);
    nextDay();
    return d;
}
Date &Date::operator+(int x)
{
    while(x--)
        nextDay();
    return *this;
}
void Date::nextDay()
{
    day++;
    int monthday[2][12]= {31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
    if(day>monthday[isLeapYear()][month-1])
    {
        day=1;
        month++;
    }
    if(month>12)
    {
        year++;
        month=1;
    }
}
bool Date::setDate(int y,int m,int d)
{
    int a=year,b=month,c=day;
    year=y;
    month=m;
    day=d;
    if(check())
        return true;
    else
    {
        year=a;
        month=b;
        day=c;
        return false;
    }
}
