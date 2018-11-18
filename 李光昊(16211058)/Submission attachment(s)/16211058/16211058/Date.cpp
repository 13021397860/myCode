#include "Date.h"
#include<cstdio>
#include<iostream>
#include "MyException.h"
using namespace std;

Date::Date()
{
    year=1900;
    month=1;
	day=1;
}

Date::Date(int y,int m,int d)
{
	set(y,m,d);
}

Date::Date(const Date &d)
{
	set(d.year,d.month,d.day);
}

//
ostream &operator<<(ostream &output,const Date &d)
{
	output<<d.getYear()<<"-"<<d.getMonth()<<"-"<<d.getDay();
	return output;
}

istream &operator>>(istream &input,Date &d)
{
	int ay,am,ad;
	input>>ay>>am>>ad;
	d.set(ay,am,ad);
	return input;
}
//
//
Date &Date::operator++()
{
	nextDay();
	return *this;
}

Date Date::operator++(int)
{
	Date temp=*this;
	nextDay();
	return temp;
}

Date &Date::operator+(int x)
{
	for(int i=0;i<x;i++)
	{
		++(*this);
	}
	return *this;
}
//

const int monthday[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
bool Date::set(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
	return check();
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
bool Date::isLeapYear()const
{
	if((year%4==0&&year%100!=0)||year%400==0)return true;
	else return false;
}

void Date::nextDay()
{
	int leapjudge;
	if(isLeapYear())leapjudge=1;
	else leapjudge=0;
	if(day==monthday[leapjudge][month-1])
	{
		if(month==12)
		{
			++year;
			month=1;
			day=1;
		}
		else
		{
			++month;
			day=1;
		}
	}
	else
	{
		++day;
	}
}
//

/*
void Date::print()const
{
	cout<<year<<"-"<<month<<"-"<<day;
}
*/

bool Date::check()
{
	bool judge=1;
	if(month<1)
	{
		//cout<<"Wrong month! month=1\n";
		month=1;
		judge=0;
	}
	if(month>12)
	{
		//cout<<"Wrong month! month=12\n";
		month=12;
		judge=0;
	}
	if(day<1)
	{
		//cout<<"Wrong day! day=1\n";
		day=1;
		judge=0;
	}
	int maxd=monthday[isLeapYear()?1:0][month-1];
	if(day>maxd)
	{
		//cout<<"Wrong day! day="<<maxd<<"\n";
		day=maxd;
		judge=0;
	}
	//***********
	if(judge==0)	throw MyException("日期非法！");
	//***********
	return judge;
}
//
Date::~Date()
{
	//cout<<"Date object destructor for date ";
	//print();
	//cout<<"\n";
}
