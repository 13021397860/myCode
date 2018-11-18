#include"date.h"
#include<iostream>
using namespace std;

ostream & operator<<(ostream & out, const Date & A)
{
    out << A.getyear() <<"-"<< A.getmonth() <<"-"<< A.getday();
    return out;
}

Date::Date()
{
	year=2000;
	month=1;
	day=1;
}

Date::Date(int y, int m, int d)
{
    setyear(y);
	setmonth(m);
	setday(d);
}

Date::Date(const Date &d)
{
	year = d.year;
	month = d.month;
	day = d.day;
}

Date &Date::operator++()
{
	nextday();
	return *this;
}

Date Date::operator++(int)
{
	Date temp(*this);
	nextday();
	return temp;
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

void Date::setyear(int y)
{
	if(y>0)
	year=y;
	else
	cout<<"Illegal Input!"<<endl;
}

void Date::setmonth(int m)
{
	if(m>=0&&m<=12)
	month=m;
	else
	cout<<"Illegal Input!"<<endl;
}

void Date::setday(int d)
{
	if(d>=0&&d<=28)
	day=d;
	else if(d==29&&month!=2)
	day=d;
	else if(d==29&&month==2)
	{
		if(year%4==0&&year%100!=0||year%400==0)
		{
			day=d;
		}
		else
		cout<<"Illegal Input!"<<endl;
	}
	else if(d==31)
	{
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		{
			day=d;
		}
		else
		cout<<"Illegal Input!"<<endl;
	}
	else
	cout<<"Illegal Input!"<<endl;
}

bool Date::isLeapYear(int y)
{
	if(year%4==0&&year%100!=0||year%400)
	{ 
		cout<<"yes"<<endl;
		return true;
	} 
	else 
	{
		cout<<"no"<<endl;
		return false;
	}
}

void Date::nextday()
{
	if(day==31)
	{
		day=1;
		if(month==12)
		{
			year+=1;
			month=1;
		}
		else
		{
			month+=1;
		}
	}
	else if(day==30&&(month==4||month==6||month==9||month==11))
	{
		day=1;
		month+=1;
	}
	else if(day==29&&month==2)
	{
		day=1;
		month+=1;
	}
	else if(day==28&&month==2)
	{
		if(year%4==0&&year%100!=0||year%400==0)
		{
			day+=1;
		}
		else
		{
			day=1;
			month+=1;
		}
	}
	else
	{
		day+=1;
	}
}

Date::~Date()
{
    
}
