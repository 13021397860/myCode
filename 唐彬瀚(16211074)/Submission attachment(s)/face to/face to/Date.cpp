#include <iostream>
#include "Date.h"
using namespace std;
Date::Date()
{
	year = 2000;
	day = 29;
	month = 2;
}
Date::Date(const Date &t)
{
	year = t.year;
	day = t.day;
	month = t.month;
}
Date::~Date()
{
	
}
void Date::setDate(const int m,const  int d,const int y)
{
	month=m;
	day=d;
	year=y;
}
int Date::get_day() const
{
	return day;
}
int Date::get_month() const
{
	return month;
}
int Date::get_year() const
{
	return year;
}
bool Date::isLeapYear(const int y)
{
	if((y % 100 != 0 && y % 4 == 0) || (y % 100 == 0 && y % 400 == 0))
	{
		return 1;
	}
	else 
		return 0;
}
void Date::nextDay()
{
	if(month != 2 && month != 12 && day != 30){
		if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month ==12)
		{
			if(day == 30)
			{
				day = 31;
			}
			else
				day++;
		}
		else if(day == 30)
		{
			day = 1;
			month++;
		}
	}
	if(isLeapYear(year) == 1 && month == 2 && day < 29)
	{
		day++;
	}
	else if(isLeapYear(year) == 1 && month == 2 && day == 29)
	{
		day = 1;
		month++;
	}
	if(isLeapYear(year) == 0 && month == 2 && day < 28)
	{
		day++;
	}
	else if(isLeapYear(year) == 0 && month == 2 && day == 28)
	{
		day = 1;
		month++;
	}
	if(month == 12 && day == 31)
	{
		year++;
		month = 1;
		day = 1;
	}
}
ostream & operator << (ostream &output,Date &d)
{
	output<<d.get_year()<<"-"<<d.get_month()<<"-"<<d.get_day();
	return output;
}
Date &Date::operator ++()
{
	nextDay();
	return *this;
}
Date Date::operator ++(int)
{
	Date temp=*this;
	nextDay();
	return temp;
}
