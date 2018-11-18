#include "Date.h"
#include<iostream>
using namespace std;
int rn[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int pn[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
Date::Date()
{
    year=1900;
    month=1;
    day=1;
    //ctor
}

Date::Date(const int y, const int m, const int d)
{
    setTime(y,m,d);
    //ctor
}

Date::~Date()
{
    //dtor
}

Date::Date(const Date & t)
{
    year=t.year;
    month=t.month;
    day=t.day;
}
bool Date::check()
{
    if(year<1)
        return false;
    if(month<1 || month>12)
        return false;
    if(isLeapYear()){
        if(day<1 || day>rn[month])
            return false;
    }
    else{
        if(day<1 || day>pn[month])
            return false;
    }
    return true;
}
void Date::setTime(const int a, const int b, const int c)
{
    year=a;
    month=b;
    day=c;
    if(!check()){
        year=1900;
        month=1;
        day=1;
        MyException except("date");
        throw except;
    }
    return;
}

bool Date::isLeapYear()
{
    if((year%4==0 && year%100!=0) || year%400==0)
        return true;
    return false;
}

void Date::print() const
{
    cout<<year<<"."<<month<<"."<<day<<endl;
    return;
}

void Date::nextDay()
{
    if(month==12&&day==31){
        year++;
        month=day=1;
    }
    else if(isLeapYear()&&day==rn[month]){
        day=1;
        month++;
    }
    else if(!isLeapYear()&&day==pn[month]){
        day=1;
        month++;
    }
    else{
        day++;
    }
    return;
}

ostream &operator<<(ostream &output, const Date &d)
{
    output<<d.year<<"-"<<d.month<<"-"<<d.day;
    return output;
}

Date& Date::operator++()
{
    nextDay();
    return (*this);
}

Date Date::operator++(int)
{
    Date tmp=*this;
    nextDay();
    return tmp;
}
