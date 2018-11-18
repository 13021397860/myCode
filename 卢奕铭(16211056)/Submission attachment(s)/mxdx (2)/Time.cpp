#include <iostream>
#include "Time.h"
#include "MyException.h"
using namespace std;


Time::Time()
{
	year = month = day = 1;
}

Time::Time(int y, int m, int d)
{
    Time::setTime(y, m, d);
}

Time::Time(const Time &t)
{
    year = t.year;
    month = t.month;
    day = t.day;
}

Time Time::operator++(int n){
    Time s = *this;
    nextDay();
    return s;
}

Time Time::operator++(){
    nextDay();
    return *this;
}

Time::~Time()
{
}

void Time::setTime(int y, int m, int d)
{
	year=y;
	month=m;
	day=d;
	if(!checkTime())
        throw MyException(RANGE_ERROR);
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

void Time::print()const
{
	cout << year << "." << month << "." << day << "\n";
}

ostream& operator<< (ostream& outs,const Time& p)
{
	int a,b,c;
	a=p.getYear();
	b=p.getMonth();
	c=p.getDay();
	outs<<a<<" - "<<b<<" - "<<c;
	return outs;
}
void Time::nextDay()
{
	day++;
	if(!Time::checkTime())
    {
        month++;
        if(!Time::checkTime())
            year++;
    }
    return;
}
