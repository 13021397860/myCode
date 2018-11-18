#include "Date.h"
#include <iostream>
#include <iomanip>
using namespace std;

Date::Date()
{
    year = 2017;
    month = 1;
    day = 1;
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

void Date::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

bool Date::isLeapYear(int y) const
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ? true : false;
}

bool Date::isLegalYear(int y)
{
	return (y >= 1900 && y <= 2100) ? true : false;
}

bool Date::isLegalMonth(int m)
{
	return (m >= 1 && m <= 12) ? true : false;
}

bool Date::isLegalDay(int y, int m, int d)
{
	switch(m)
	{
		case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return (d >= 1 && d <= 31) ? true : false;
        case 4:
        case 6:
        case 9:
        case 11:
            return (d >= 1 && d <= 30) ? true : false;
        case 2:
            if(isLeapYear(y))
                return (d >= 1 && d <= 29) ? true : false;
			else
                return (d >= 1 && d <= 28) ? true : false;	
        default: 
            return false;
	}
}

bool Date::isLegalDate()
{
	bool valid = true; 
	if(!isLegalYear(year))
	{
		year = 2017;
		valid = false;
	}
	if(!isLegalMonth(month))
	{
		month = 1;
		valid = false;
	}
	if(!isLegalDay(year, month, day))
	{
		day = 1;
		valid = false;
	}
	return valid;
}

void Date::printDate() const
{
	cout<<getYear()<<"-"<<setfill('0')<<setw(2)<<getMonth()<<"-"<<setfill('0')<<setw(2)<<getDay()<<"\n";
}

void Date::nextDay()
{
	day++;
	if(!isLegalDay(year, month, day))
	{
		month++;
		day = 1;
		if(!isLegalMonth(month))
		{
			year++;
			month = 1;
			if(!isLegalYear(year))
			exit(1);
		}
	}
}

Date::~Date()
{
    
}
//÷ÿ‘ÿ 
ostream& operator <<(ostream& os,const Date& data)
{
	os<<data.year<<"-"<<data.month<<"-"<<data.day<<endl;
	return os;
}

istream& operator >>(istream& is,Date& data)
{
	is>>data.year>>data.month>>data.day;
	return is;
}

Date Date::operator++( ) //«∞÷√
{
	nextDay(); 
	return *this;
}
Date Date::operator++( int ) //∫Û÷√
{ 
	Date temp(*this);
	nextDay(); 
	return temp;
}
