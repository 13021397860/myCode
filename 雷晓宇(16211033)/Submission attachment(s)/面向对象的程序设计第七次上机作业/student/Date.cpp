#include "Date.h"
#include "MyException.h"
#include<iostream>

Date::Date(int y,int m,int d)
{
    setDate(y,m,d);
}
Date::Date(Date &a)
{
	year=a.year;
	month=a.month;
	day=a.day;
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
bool Date::judge()
{
	if ( year < 1 || month < 1 || month > 12)
    {
    	return false;
	}
	if ( year % 400 ==0 || ( year % 4 ==0 && year % 100 != 0))
	{
		if (( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month ==12 ) && ( day < 1 || day >31))
		{
			return false;
		}
		else if ( month ==2 && (day < 1 || day > 29) )
		{
			return false;
		}
		else if ( day < 1|| day > 30)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else 
	{
		if (( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month ==12 ) && ( day < 1 || day >31))
		{
			return false;
		}
		else if ( month ==2 && (day < 1 || day > 28) )
		{
			return false;
		}
		else if ( day < 1|| day > 30)
		{
			return false;
		}
		else 
		{
			return true;
		}
	}
}
void Date::setDate(int y,int m,int d)
{
    year = y;
    month = m;
    day = d;
    if (judge()==false)
    {
    	throw MyException(DATE_INVALID);
	}
}
bool Date::isLeapYear()
{
    if ( year % 400 ==0 || ( year % 4 ==0 && year % 100 != 0))
    {
    	std::cout<<"True"<<"\n";
        return true;
    }
    else
    {
    	std::cout<<"False"<<"\n";
        return false;
    }
}
ostream& operator<<(ostream& output,const Date& p){
	output<<p.year<<"-"<<p.month<<"-"<<p.day;
    return output;
}
Date& Date::operator ++(){
	if ( this->month == 12 && this->day == 31)
	{
	    this->year+=1;
	    this->month = 1;
	    this->day = 1;
	}
	else if ( this->day == 31)
    {
        this->month+=1;
        this->day = 1;
    }
    else if ( this->day == 30)
    {
        if ( this->month == 4 && this->month == 6 && this->month == 9 && this->month == 11 )
        {
            this->month+=1;
            this->day = 1;
        }
        else
        {
            this->day++;
        }
    }
    else if ( this->month == 2 && this->day == 29 && ( this->year % 400 ==0 || ( this->year % 4 ==0 && this->year % 100 != 0)))
    {
        this->month++;
        this->day = 1;
    }
    else if ( this->month == 2 && this->day == 28 && ( this->year % 400 ==0 || ( this->year % 4 ==0 && this->year % 100 != 0)))
    {
        this->day++;
    }
    else if ( this->month == 2 && this->day == 28 && !( this->year % 400 ==0 || ( this->year % 4 ==0 && this->year % 100 != 0)))
    {
        this->month++;
        this->day = 1;
    }
    else
    {
    	this->day++;
	}
    return *this;
}
Date Date::operator ++(int){
    Date tmp(*this);
    if ( this->month == 12 && this->day == 31)
	{
	    this->year+=1;
	    this->month = 1;
	    this->day = 1;
	}
	else if ( this->day == 31)
    {
        this->month+=1;
        this->day = 1;
    }
    else if ( this->day == 30)
    {
        if ( this->month == 4 && this->month == 6 && this->month == 9 && this->month == 11 )
        {
            this->month+=1;
            this->day = 1;
        }
        else
        {
            this->day++;
        }
    }
    else if ( this->month == 2 && this->day == 29 && ( this->year % 400 ==0 || ( this->year % 4 ==0 && this->year % 100 != 0)))
    {
        this->month++;
        this->day = 1;
    }
    else if ( this->month == 2 && this->day == 28 && ( this->year % 400 ==0 || ( this->year % 4 ==0 && this->year % 100 != 0)))
    {
        this->day++;
    }
    else if ( this->month == 2 && this->day == 28 && !( this->year % 400 ==0 || ( this->year % 4 ==0 && this->year % 100 != 0)))
    {
        this->month++;
        this->day = 1;
    }
    else
    {
    	this->day++;
	}
    return tmp;
}
void Date::nextDay()
{
    if ( month == 12 && day == 31)
    {
        year++;
        month = 1;
        day = 1;
    }
    else if ( day == 31)
    {
        month++;
        day = 1;
    }
    else if ( day == 30)
    {
        if ( month == 4 && month == 6 && month == 9 && month == 11 )
        {
            month++;
            day = 1;
        }
        else
        {
            day++;
        }
    }
    else if ( month == 2 && day == 29 && ( year % 400 ==0 || ( year % 4 ==0 && year % 100 != 0)))
    {
        month++;
        day = 1;
    }
    else if ( month == 2 && day == 28 && ( year % 400 ==0 || ( year % 4 ==0 && year % 100 != 0)))
    {
        day++;
    }
    else if ( month == 2 && day == 28 && !( year % 400 ==0 || ( year % 4 ==0 && year % 100 != 0)))
    {
        month++;
        day = 1;
    }
    else
    {
    	day++;
	}
}

Date::~Date()
{
    //dtor
}
