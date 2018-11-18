#include "date.h"
#include <iostream>
#include <iomanip>
using namespace std;

Date::Date()
{
	year=1;
	month=1;
	day=1;
}

Date::Date(int y, int m, int d)
{
    setDate(y, m, d);
}

Date::Date(const Date &d)
{
	year = d.year;
	month = d.month;
	day = d.day;
}

int Date::getYear() const 
{return year;
}

int Date::getMonth() const
{return month;
}

int Date::getDay() const
{return day;
}

bool Date::isLeapYear()
{
	if((year%4==0&&year%100!=0)||year%400==0)
	return 1;
	
	else
	return 0;
}

bool Date::checkDate()
{
	bool flag=1;
	
	    if(year<1||month>12||month<=0||day<=0||day>31)
		flag=0;
		
		else if(month==4||month==6||month==9||month==11)
		{
			if(day==31)
			flag=0;
		}
		
		else if(month==2)
		{
			if(isLeapYear())
			{
				if(day>29)
				flag=0;
			}
			
			else
			{
				if(day>28)
				flag=0;	
			}
		}
		
		return flag;
}


void Date::setDate(int y, int m, int d)
{			
	year=y;
	month=m;
	day=d;
	if (cin.fail())
	{
        cin.clear();
		cin.ignore();
    };
	if(!checkDate())
	{
		cout<<"不合法的日期，系统将其重置为初始日期！"<<endl;
		
		year=1;
		month=1;
		day=1;	
	}
}

void Date::nextDay()
{
	day++;
	
	if(!checkDate())
	{
		month++;
		day=1;
		
		if(!checkDate())
		{
			year++;
			month=1;
		}
	}
}

Date& Date::operator++()
{
	nextDay();
	return *this;
}

Date Date::operator++(int) 
{
	Date d=*this;
	nextDay();
	return d;
}

ostream& operator<<(ostream &output,const Date &d)
{
	output<<d.getYear()<<"-"<<d.getMonth()<<"-"<<d.getDay();
	return output;
}

istream& operator>>(istream& input,Date &e)
{
	int y,m,d;
	input>>y>>m>>d;
	e.setDate(y,m,d);
	return input;
}


Date::~Date()
{
    
}


