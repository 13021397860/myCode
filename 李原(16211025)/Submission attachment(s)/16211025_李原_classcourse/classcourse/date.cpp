#include<iostream>
#include "date.h"
using namespace std;
Date::Date(int y,int m,int d)
{
	year=y;month=m;day=d;
} 
Date::~Date()
{
	
}
Date::Date(Date &D)
{
	year=D.year;
	month=D.month;
	day=D.day;
}
/*---------------------------------*/
void Date::datecpy(const Date &D)
{
	year=D.year;
	month=D.month;
	day=D.day;
}

bool Date::isLeapYear()const
{
	if(year==0)return 0;
	else if(year%4!=0)return 0;
	else if(year%100!=0)return 1;
	else if(year%400==0)return 1;
	else return 0;
}
bool Date::isYear()const
{
	if(year<=0)return 0;
	else
	{
		if(month==2&&day==29)
		{
			if(isLeapYear())
			{
				return 1;
			}
			else return 0;
		}
		else return 1;
	}
}
bool Date::isMonth()const
{
	if(month<=0||month>12)return 0;
	else
	{
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)return 1;
		else if(month==4||month==6||month==9||month==11)
		{
			if(day==31)return 0;
			else return 1;
		}
		else
		{
			if(day>29)return 0;
			else if(day<=28)return 1;
			else if(isLeapYear())return 1;
			else return 0;
		}
	}
}
bool Date::isDay()const
{
	if(day<=0||day>31)return 0;
	else if(day==31)
	{
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==10||month==12)
		return 1;
		else return 0;
	}
	else if(day<=28)return 1;
	else if(month!=2)return 1;
	else if(day==30)return 0;
	else if(isLeapYear())return 1;
	else return 0;
}
bool Date::isAll()const
{
	if(isYear()&&isMonth()&&isDay())return 1;
	else
	{
		return 0;
	}
}
/*---------------------------------------------*/
bool Date::setYear(int y)
{
	int tempy=year;
	year=y;
	if(isYear())
	{
		return 1;
	}
	else 
	{
		year=tempy;
		return 0;
	}
}
bool Date::setMonth(int m)
{
	int tempm=month;
	month=m;
	if(isMonth())
	{
		return 1;
	}
	else 
	{
		month=tempm;
		return 0;
	}
}
bool Date::setDay(int d)
{
	int tempd=day;
	day=d;
	if(isDay())
	{
		return 1;
	}
	else 
	{
		day=tempd;return 0;
	}
}
bool Date::setAll(int y,int m,int d)
{
	int tempy=year;
	int tempm=month;
	int tempd=day;
	
	year=y;
	month=m;
	day=d;
	if(isAll())
	{
		return 1;
	}
	else 
	{
		year=tempy;
		month=tempm;
		day=tempd;
		return 0;
	}
}
/*--------------------------------------------*/

void Date::nextDay()
{
	if(day<28)
	{
		day++;
	}
	else if(day==28)
	{
		if(month!=2)
		{
			day++;
		}
		else
		{
			if(isLeapYear())
			{
				day=29;
			}
			else 
			{
				day=1;month=3;
			}
		}
	}
	else if(day==29)
	{
		if(month==2)
		{
			day=1;month=3;
		}
		else 
		{
			day++;
		}
	}
	else if(day==30)
	{
		if(month==2||month==4||month==6||month==9||month==11)
		{
			day=1;month++;
		}
		else
		{
			day++;
		}
	}
	else if(day==31)
	{
		if(month==12)
		{
			year++;month=1;day=1;
		}
		else
		{
			month++;day=1;
		}
	}
}
/*------------------------------------*/


