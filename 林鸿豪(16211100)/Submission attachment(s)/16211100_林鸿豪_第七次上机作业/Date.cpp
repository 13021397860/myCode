#include <iostream>
#include "MyException.h"
using namespace std;
#include <iomanip>
#include "Date.h"

bool Date::isLeapYear()const
{
	if (year%400==0)	return true;
	else if (year%4==0&&year%100!=0)	return true;
	return false;
}
bool Date::checklegal() const
{
	if (year<=0)	 return false;
	if (isLeapYear())
	{
		if (month==2&&day==29)	return true;
		else return true;
	}
	if (month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		if (day<=0||day>31)	return false;
		else return true;
	}
	else if (month==4||month==6||month==9||month==11)
	{
		if (day<=0||day>30)	return false;
		else return true;
	}
	else if (month==2)
	{
		if (day<=0||day>28)	return false;
	    return true;
	}
	else if (month<=0||month>12)    return false;
	return true;
}



void Date::nextDay()
{
    day++;
	if (!checklegal())
    {
        day=1;
        month++;
    }
	if (!checklegal())
    {
        year++;
        month=1;
    }
}
Date::Date()
{
    setDate(2017,1,1);
}
Date::Date(int y,int m,int d)
{
    year=y;
    month=m;
    day=d;
    if (!checklegal())
    {
        throw(MyException("Date Error!"));
    }
}
Date::Date(const Date &d)
{
    setDate(d.year,d.month,d.day);
}

ostream& operator<<(ostream& os,const Date& p)
{
    os<<p.year<<"-"
    <<p.month<<"-"<<p.day<<"\n";
}


Date& Date::operator ++()
{
    this->nextDay();
    return *this;
}
Date Date::operator ++ (int)
{
    Date tmp =*this;
    ++(*this);
    return tmp;
}
