#include <iostream>
#include "Date.h"
using namespace std;

Date::Date()
{
	year=2000;
	month=1;
	day=1;
}

Date::Date(const int x,const int y,const int z)
{
	if(!isLegal(x,y,z))
		throw MyException();
	setDate(x,y,z);
}

Date::Date(const Date &t)
{
	if(!isLegal(t.year,t.month,t.day))
		throw MyException();
	setDate(t.year,t.month,t.day);
}

Date::~Date()
{
}

int Date::get_year()const
{
	return year;	
}

int Date::get_month()const
{
	return month;	
}

int Date::get_day()const
{
	return day;	
}

void Date::setDate(const int y,const int m,const int d)
{
	year=(y>0)?y:2000;
	month=(m>0&&m<13)?m:1;
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		day=((d>0)&&(d<32))?d:1;
	if(month==4||month==6||month==9||month==11)
		day=((d>0)&&(d<31))?d:1;
	if(month==2&&isLeapYear())
		day=((d>0)&&(d<30))?d:1;
	if(month==2&&!isLeapYear())
		day=((d>0)&&(d<29))?d:1;	
}

bool Date::isLeapYear()const
{
	if(year%4==0)
	{
		if(year%100==0&&year%400!=0)
			return 0;
		return 1;
	}
	return 0;
}

void Date::nextDay()
{
	day++;
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		if(day>31)
		{
			day-=31;
			month++;
		}
	if(month==4||month==6||month==9||month==11)
		if(day>30)
		{
			day-=30;
			month++;
		}
	if(month==2&&isLeapYear())
		if(day>29)
		{
			day-=29;
			month++;
		}
	if(month==2&&!isLeapYear())
		if(day>28)
		{
			day-=28;
			month++;
		}
	if(month>12)
	{
		month-=12;
		year++;
	}
}

ostream& operator << (ostream& output,Date &x)
{
	output<<x.get_year()<<" "<<x.get_month()<<" "<<x.get_day();
	return output;
}

bool Date::operator ==(Date &x)
{
	return (x.get_day()==this->get_day())&&(x.get_month()==this->get_month())&&(x.get_year()==this->get_year());
} 

Date& Date::operator ++()
{
	this->nextDay();
	return *this;
} 

Date Date::operator ++(int x)
{
	Date tmp=*this;
	this->nextDay();
	return tmp;
}

bool Date::isLegal(const int y,const int m,const int d)
{
	if(y<1||m>12||m<1||d<1||d>31)
		return 0;
	if(m==2)
	{
		if(d>29)
			return 0;
		if(m%4!=0||(m%100==0&&m%400!=0))
			if(d>28)
				return 0;
	}
	if((m%2==0&&m<=7)||(m%2==1&&m>=8))
	{
		if(d>30)
			return 0;
	}
	return 1;
}
