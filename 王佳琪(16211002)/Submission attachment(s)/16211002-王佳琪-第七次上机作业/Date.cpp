#include<iostream>
#include "Date.h"
using namespace std;

ostream& operator<< (ostream& os, const Date& c)  
{  
    os << c.year << "-" << c.month << "-"<<c.day;  
    return os;  
}

Date::Date()
{
    year=2000;
    month=day=1;
}

Date::Date(const Date &data){
year=data.year;
month=data.month;
day=data.day;
}

Date::~Date(){}

Date& Date::operator++ ()
{
	this->nextDay();
	return *this;
}

Date Date::operator++ (int )
{
	Date tmp = *this;
	this->nextDay();
	return tmp;
}

//istream& operator>> (istream& is, Date&c)

void Date::setDate(int y, int m, int d)
{
    year=y;
    month=m;
    day=d;
    if(wrongDate(year,month,day))
    {
        cout<<"wrong date!"<<endl;
            year=2000;
            month=1;
            day=1;
    }
    else{
        year=y;
        month=m;
        day=d;
    }
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

bool Date::isLeapYear()
{
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0) return 1;
            else return 0;
        }
        else return 1;
    }
    else return 0;
}

/*
void Date::print()
{
    cout<<year<<'/'<<month<<'/'<<day<<endl;
}
*/

void Date::nextDay()
{
    if(( month == 1|| month == 3 || month == 5 || month == 7||month == 8||month == 10)&&day ==31){
        month++;
        day=1;
    }
    else if((month == 4|| month == 6||month == 9||month ==11) && day ==30){
        month++;
        day=1;
    }
    else if(month == 12 && day ==31){
        year++;
        month=1;
        day=1;
    }
    else if(month == 2 && day ==28){
        if(isLeapYear())
        day++;
        else{
            month=3;
            day=1;
        }
    }
    else if(month == 2 && day == 29){
        month=3;
        day=1;
    }
    else{
        day++;
    }
}

bool Date::wrongDate(int y,int m,int d)
{
	year = y; month = m; day = d;
	if(year<=0||month<=0||month>12||day<=0||day>31) return 1;
    else if(( month == 1|| month == 3 || month == 5 || month == 7||month == 8||month == 10)&&day > 31) return 1;
    else if((month == 4|| month == 6||month == 9||month ==11) && day >30) return 1;
    else if(month==2&&day >= 29&&!isLeapYear()) return 1;
    else if(month==2&&day > 29&&isLeapYear()) return 1;
    return 0;
}



