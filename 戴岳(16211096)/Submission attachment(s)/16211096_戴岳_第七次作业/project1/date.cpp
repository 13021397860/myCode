#include "date.h"
#include <iostream>
#include <iomanip>
using namespace std;

Date::Date()
{
    year=2000;
    month=1;
    day=1;
}

Date::Date(int y,int m,int d)
{
    setTime(y,m,d);
}

Date::Date(const Date& a)
{
    year=a.year;
    month=a.month;
    day=a.day;
}

void Date::setTime(int y,int m,int d)
{
    if(y>0&&m>0&&m<13&&d>0&&d<daysOfMonth(y,m)+1)
    {
        year=y;
        month=m;
        day=d;
    }
    else
    {
        cout<<"Illegal date! please re-enter the correct date."<<endl;
        day=0;
    }

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

bool Date::isLeapYear(int y) const
{
    return ((y%4==0&&y%100!=0)||y%400==0);
}

int Date::daysOfMonth(int y,int m) const
{
    if(m==2){
        if(isLeapYear(y)){
            return 29;
        }
   else{
            return 28;
      }
}
    else if(m==4||m==6||m==9||m==11){
            return 30;
    }
    else{
            return 31;
    }
}
void Date::nextDay()
{
    if(day+1>daysOfMonth(year,month)){
        day=1;
        month++;
        if(month>12)
        {
            month=1;
            year++;
        }
    }
    else
    {
        day++;
    }
}

void Date::print() const
{
    cout<<right<<setfill('0')<<setw(4)<<year<<"-"<<setfill('0')<<setw(2)<<month<<"-"<<setfill('0')<<setw(2)<<day;
}

ostream& operator<<(ostream& output, const Date& c)
{
    output<<c.getYear()<<"-"<<c.getMonth()<<"-"<<c.getDay();
    return output;
}


Date& Date::operator++()
{
    nextDay();
    return (*this);
}

Date Date::operator++(int)
{
    Date a=*this;
    nextDay();
    return a;
}

Date::~Date()
{
    //dtor
}
