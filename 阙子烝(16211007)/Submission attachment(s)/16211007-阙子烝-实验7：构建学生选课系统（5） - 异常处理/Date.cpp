#include <iostream>
#include "Date.h"

const int Date::mlenth[2][13]={0,31,29,31,30,31,30,31,31,30,31,30,31,0,31,28,31,30,31,30,31,31,30,31,30,31};

Date::Date(const int y,const int m,const int d)
{
	year=y;
	month=m;
	day=d;
	if(!check())
	{
		year=1900;
		month=day=1;
	}
}

Date::Date(const Date &d)
{
	year=d.year;
	month=d.month;
	day=d.day;
}

Date::~Date()
{
}

void Date::setDate(const int y,const int m,const int d)
{
	year=y;
	month=m;
	day=d;
	if(!check())
	{ 
		year=1900; 
		month=day=1;
	}
}

void Date::setDate_Force(const int y,const int m,const int d)
{
	year=y;
	month=m;
	day=d;
}

void Date::setYear(const int y)
{
	year=y;
	if(!check())
	{ 
		year=1900; 
		month=day=1;
	}
}

void Date::setMonth(const int m)
{
	month=m;
	if(!check())
	{ 
		year=1900; 
		month=day=1;
	}
}

void Date::setDay(const int d)
{
	day=d;
	if(!check())
	{ 
		year=1900; 
		month=day=1;
	}
}

int Date::getYear() const
{
	return year;	
}

int Date::getMonth() const
{
	return month;	
}

int Date::getDay() const
{
	return day;	
}

bool Date::isLeapYear()
{
	if(year%4!=0||(year%100==0&&year%400!=0))
		return false;
	else
		return true;
}

void Date::nextDay()
{
	++day;
	if(!check())
	{
		++month;
		day=1;
		if(!check())
		{
			++year;
			month=1;
		}
	}
}

bool Date::check()
{
	if(isLeapYear())
	{
		if(day>mlenth[0][month]||month>12||month<1||day<1||year<1)
			return false;
	}
	else
	{
		if(day>mlenth[1][month]||month>12||month<1||day<1||year<1)
			return false;
	}
	return true;
}

/*void Date::print()
{
	if(check()) 
		printf("%d-%d-%d\n",year,month,day);
	else
		printf("Error\n");
}*/

Date& Date::operator++()
{
	nextDay();
	return *this;
}
		
const Date Date::operator++(int)
{
	Date t(*this);
	++(*this);
	return t;
}

std::istream& operator>>(std::istream& input,Date& c)
{
	int x,y,z;
	input>>x>>y>>z;
	c.setDate(x,y,z);
	return input;
}

std::ostream& operator<<(std::ostream& output,const Date& c)
{
	output<<c.getYear()<<'-'<<c.getMonth()<<'-'<<c.getDay();
	return output;
}

const Date Date::operator+(const int &num)
{
	Date t(*this);
	int i;
	for(i=0;i<num;++i)
		t.nextDay();
	return t;
}

