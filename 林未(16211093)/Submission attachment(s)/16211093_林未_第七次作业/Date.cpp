#include "Date.h"
#include "DateException.h" 
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

Date::Date(const Date& d)
{
	year = d.year;
	month = d.month;
	day = d.day;
}

Date& Date::setDate(const int y, const int m, const int d)
{
	if(!isLegalDate(y, m, d))
		throw DateException();
	else
	{
		year = y;
		month = m;
		day = d;
	}
	return *this;
}

bool Date::isLeapYear(const int y) const
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ? true : false;
}

bool Date::isLegalYear(const int y) const
{
	return (y >= 1900 && y <= 2100) ? true : false;
}

bool Date::isLegalMonth(const int m) const
{
	return (m >= 1 && m <= 12) ? true : false;
}

bool Date::isLegalDay(const int y, const int m, const int d) const
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

bool Date::isLegalDate(const int y, const int m, const int d)
{
	bool valid = true; 
	if(!isLegalYear(y) || !isLegalMonth(m) || !isLegalDay(y, m, d))
		valid = false;
	return valid;
}

Date& Date::operator++()
{
    nextDay();
    return *this;	
}
 
Date Date::operator++(int)
{
	Date studDate(*this);	
    nextDay();
    return studDate;	
}

ostream& operator<<(ostream& output, const Date& studDate)
{
	output << studDate.year << "-" << studDate.month
		   << "-" << studDate.day;
	return output;
}

/*void Date::printDate() const
{
	cout<<getYear()<<" - "<<setfill('0')<<setw(2)
	<<getMonth()<<" - "<<setfill('0')<<setw(2)<<getDay()<<"\n"<<endl;
}*/

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
