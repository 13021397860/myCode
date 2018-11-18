#include "Date.h"
#include <iostream>
#include "MyExpection.h"
using namespace std;

int a[2][12]={31,29,31,30,31,30,31,31,30,31,30,31,
			31,28,31,30,31,30,31,31,30,31,30,31	};
			
Date::Date(int y,int m,int d)
{
    setDate(y,m,d);
}

Date::Date()
{
	year=month=day=1;
}

void Date::setDate(int y,int m,int d)
{
    year=(y>=0&&y<10000)?y:1999;
    month=(m>0&&m<=12)?m:4;
    day=(d>0&&d<=31)?d:30;
}

int Date::getyear()const
{
    return year;
}

int Date::getmonth()const
{
    return month;
}

int Date::getday()const
{
    return day;
}

ostream& operator<<(ostream &output,const Date &s)
{
	output<<s.year<<"-"<<s.month<<"-"<<s.day;
	return output;
}

bool Date::isLeapYear(int year)//只干自己的事 
{
    if(year%400==0||(year<400&&year%4==0&&year%100!=0)||(year%4==0&&year%100!=0))
    {
        return true;
    }
    else
        return false;
}

Date &Date::operator++()
{
	nextDay();
	return *this;
}

Date Date::operator++(int)
{
	Date d(*this);
	nextDay();
	return d;
}

void Date::nextDay()
{
	if(month!=2)
	{
		if(day<a[1][month-1])
		{
			day++;
		}
		else 
		{
			if(month!=12)
			{
				month++;
				day=1;
			}
			else 
			{
				year++;
				month=1;
				day=1;
			}
		}
	}
	else
	{
		if(isLeapYear(year)==1)
		{
			if(day<a[0][1])
			{
				day++;
			}
			else 
			{
				month++;
				day=1;
			}
		}
		else 
		{
			if(day<a[1][1])
			{
				day++;
			}
			else 
			{
				month++;
				day=1;
			}
		}
	}
}

bool Date::panduan()
{
	if(isLeapYear(year))
	{
		cout<<"This year is Leapyear!"<<endl;
	}
	else 
		cout<<"This year is not Leapyear!"<<endl;
 } 
