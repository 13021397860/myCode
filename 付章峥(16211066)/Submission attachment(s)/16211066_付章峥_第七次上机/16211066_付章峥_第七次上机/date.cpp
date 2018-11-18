#include "date.h"
#include "myexception.h"
#include<iostream>
using namespace std;

//Date constructor
Date::Date(const int m,const int d,const int y)//ctor
{
    Date::setDate(m,d,y);//set the data
}//end constructor Date

//copy constructor
Date::Date(Date &date0)
{
    year = date0.year;//copy year

    month = date0.month;//copy month

    day = date0.day;//copy day
}//end copy

//check Leap Year
bool Date::isLeapYear()
{
    return (!(year%400))||(year%100&&(!(year%4)));//1=y%400 0=y%100 1=y%4
}//end function isLeapYear

//set values of month,day,year
void Date::setDate(const int m,const int d,const int y)
{
    year = y;//validate year

    month = m;//validate month

    day = d;//validate day

    //Date::checkDate();//check the date
}//end set

//set maxDate
int Date::maxDay()
{
    switch(month)
    {
        case 1://months have 31 days
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;//end these situations
        case 4://months have 30 days
        case 6:
        case 9:
        case 11:
            return 30;//end these situations
        case 2://February
            return 28+Date::isLeapYear();//end this situation
        default://other illegal situations
            return 1;//end others
    }
}//end function maxDate

//check the date
void Date::checkDate()
{
    year = (year>0) ? year : 2000;//check year

    month = (month>=1&&month<=12) ? month :1;//check month

    day = (day>0&&day<=maxDay()) ? day : 1 ;//check day
}//end function checkDate

//return month value
int Date::getMonth()
{
    return month;
}//end function getMonth

//return day value
int Date::getDay()
{
    return day;
}//end function getDay

//return year value
int Date::getYear()
{
    return year;
}//end function getYear

//add to next day
void Date::nextDay()
{
    day++;
    if(day>maxDay())//check next day
    {
        day = 1;month++;//the last day in the month
    }
    if(month>12)//check next month
    {
        month = 1;year++;//the last month in the year
    }
}//end function nextDay

ostream &operator<<(ostream &opt,const Date &a)
{
    opt << a.year << "-"
        << a.month <<"-"
        << a.day;
    return opt;
}

istream &operator>>(istream &ipt,const Date &a)
{
    ipt>>a.month>>a.day>>a.year;
    return ipt;
}

Date Date::operator++(int)
{
    Date a(*this);
    this->nextDay();
    return a;
}

Date& Date::operator++()
{
    this->nextDay();
    return *this;
}

Date Date::operator+(int a)
{
    while(a--)
    this->nextDay();
    return *this;
}

Date::~Date()//dtor
{

}
