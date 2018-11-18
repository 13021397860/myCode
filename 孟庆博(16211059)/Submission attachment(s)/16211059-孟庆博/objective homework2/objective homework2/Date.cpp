#include "stdafx.h"
#include "Date.h"
#include<iostream>
#include <iomanip>
using namespace std;


Date::Date()
{
}
Date::Date(Date &a)
{
	day = a.day;
	month = a.month;
	year = a.year;
}
bool Date::isLeapYear()
{
	if (year % 100)
	{
		if (year % 4)
			return false;
		else
			return true;
	}
	else
	{
		if (year % 400)
			return false;
		else
			return true;
	}
}
/*void Date::print()const
{
	cout << year << setw(2) << month << setw(3) << day << setw(2)<<endl;
}*/
bool Date::setDate(const int &y,const int &m,const int &d)
{	
	day = d;
	month = m;
	year = y;
	if (!checkDate())
		return 0;
	return 1;
}
bool Date::checkDate()
{
	if (isLeapYear() == 1)
	{
		days[2] = 29;
	}
	if (month < 1 || month>12)
	{
		days[2] = 28;
		return false;
	}
	if (day<1 || day>days[month])
	{
		days[2] = 28;
		return false;
	}
	days[2] = 28;
	return true;
}
int Date::getDate(char option)const
{
	if (option == 'y')
	{
		return year;
	}
	else if (option == 'm')
	{
		return month;
	}
	else if (option == 'd')
	{
		return day;
	}
}
void Date::nextDay()
{
	day++;
	if (Date::isLeapYear() == 1)
	{
		days[2] = 29;
	}
	if (day > days[month])
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
	days[2] = 28;
}
Date& Date::operator++(int)
{
	nextDay();
	return *this;
}
Date Date::operator++()
{
	Date a(*this);
	nextDay();
	return a;
}
Date::~Date()
{
}

ostream & operator<<(ostream &output, Date &c)
{
	output << c.year << "-" << c.month << "-" << c.day;
	return output;
}
