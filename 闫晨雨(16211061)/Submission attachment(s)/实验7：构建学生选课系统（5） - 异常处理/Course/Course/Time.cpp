#include <iostream>
#include "Time.h"
using namespace std;


Time::Time()
{
	year = month = day = 1;
}

Time::Time(const int y, const int m, const int d)
{
    Time::setTime(y, m, d);
}

Time::Time(const Time &t)
{
    year = t.year;
    month = t.month;
    day = t.day;
}

Time::~Time()
{
}

Time& Time::operator++()
{
    Time::nextDay();
    return *this;
}

Time Time::operator++(int )
{
    Time t;
    t = *this;
    Time::nextDay();
    return t;
}


ostream& operator << (ostream& out, const Time& t)
{
    out << t.year << "-" << t.month << "-" << t.day;
    return out;
}

void Time::setTime(const int y, const int m, const int d)
{
	year = y;
	month = m;
	day = d;
	if(!Time::checkTime())
        throw MyException(DATE_INVALID);
}

bool Time::isLeapYear()const
{
	bool a;
	if(year % 400 == 0)
		a = true;
	else if(year % 100 == 0)
		a = false;
	else if(year % 4 == 0)
		a = true;
	else
		a = false;
	return a;
}

bool Time::checkTime()
{
    if(year<1)
    {
        year = 1;
        return false;
    }
    if(month < 1 || month > 12){
        month = 1;
        return false;
    }
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
                if(day > 31 || day < 1){
                    day = 1;
                    return false;
                }

                return true;
        case 4:
        case 6:
        case 9:
        case 11:
                if(day > 30 || day < 1){
                    day = 1;
                    return false;
                }
                return true;
        default:
                if(isLeapYear()){
                    if(day > 29 || day < 1){
                        day = 1;
                        return false;
                    }
                }
                else{
                    if(day > 28 || day < 1){
                        day = 1;
                        return false;
                    }
                }
                return true;
    }
}

int Time::getYear()const
{
	return year;
}

int Time::getMonth()const
{
	return month;
}

int Time::getDay()const
{
	return day;
}


void Time::nextDay()
{
	day+= 1;
	if(!Time::checkTime())
    {
        month+= 1;
        if(!Time::checkTime())
            year+= 1;
    }
    return;
}
