#include "Date.h"
#include "MyException.h"
#include <iostream>
using namespace std;
int months[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
Date::Date(const int y,const int m,const int d)
{
    setdate(y,m,d);
    cout<<"Build the object!"<<"\n";
}
Date::Date(const Date &da)
{
   year=da.year;
    month=da.month;
   day=da.day;
}

Date::~Date()
{
  cout<<"Destruct the object!"<<"\n";
}

int Date::getyear() const
{
    return year;
}

int Date::getmonth() const
{
    return month;
}

int Date::getday() const
{
    return day;
}

bool Date::setdate(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
    if(!checkdate()) throw MyException(DATE_INVALID);
}
bool Date::checkdate()
{
    bool rt=true;
    if(year<=1)
    {
        rt=false;
        year=1900;
    }
    if(month<1||month>12)
    {
        rt=false;
        month=1;
    }
    if(day<1||day>months[dayscontrols()][month-1])
    {
        rt=false;
        day=1;
    }
    return rt;
}
bool Date::isLeapYear() const
{
    if(year%4!=0||(year%100==0&&year%400!=0))
	{
	    return false;
    }
	else
    {
        return true;
    }
}
int Date::dayscontrols()
{
    if(isLeapYear())
    {
        dayscontrol=1;
        return dayscontrol;
    }
    else
    {
        dayscontrol=0;
        return dayscontrol;
    }
}

void Date::nextDay()
{
    if(day==months[dayscontrols()][month-1])
    {
        day=1;
        month++;
    }
    else
    {
        day++;
    }
    if(month>12)
    {
        month=1;
        year++;
    }
}

Date& Date::operator ++()
{
	nextDay();
	return *this;
}

Date Date::operator ++(int)
{
	Date d(*this);
	nextDay();
	return d;
}

ostream&  operator <<(ostream& output, const Date& c)
{
    output<<c.year<<"-"<<c.month<<"-"<<c.day<<"\n";
  return output;
}


void Date::print() const
{
    cout<<year<<"/"<<month<<"/"<<day<<"/"<<"\n";
}
