#include "Date.h"

Date::Date( int y, int m, int d )
{
	setDate(y,m,d);
} 

Date::Date(const Date &D)
{
	setDate(D.year,D.month,D.day);
}

Date::~Date()
{
	//cout<<"Destruct the object"<<endl;
}

void Date::setDate(const int y,const int m,const int d)
{
	year = y;
	month = m;
	day = d;	
	if(!checkDate()){
		throw MyException(INVALID_DATE);
	}
}

int Date::maxDay() const
{
	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 2:
			if(isLeapYear())
				return 29;
			else
			{
				return 28;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
		default:
			return 0;
	}
}

bool Date::checkDate() const
{
	if(year<=0 || month<=0 || month>12 || day<=0 || day>maxDay())
	{
		return false;
	}	
	return true;	
}

bool Date::isLeapYear() const
{
	if(year%4==0 && year%100!=0)
	{
		return true;
	}
	if(year%400==0)
	{
		return true;
	}
	return false;	
}

void Date::nextDay()
{
	day+=1;
	if(!checkDate())
	{
		month++;
		if(!checkDate())
		{
			year++;
		}
	} 	
}

Date& Date::operator++()
{
	this->nextDay();
	return *this;
}

Date Date::operator++(int)
{
	Date d(*this);
	this->nextDay();
	return d;
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

/*void Date::print() const
{ 
   cout << year << '/' << month << '/' << day; 
}*/ 
