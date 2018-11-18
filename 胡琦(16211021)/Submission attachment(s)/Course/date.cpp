#include<iostream>
#include<cstdio>
#include "date.h"
using namespace std;

date::date(int y, int m, int d)
{
    setDate(y,m,d);
}

date::date(date &t)
{
    year=t.year;
    month=t.month;
    day=t.day;
}
date::~date()
{
    //dtor
}

bool date::isLeapYear()
{
    if((year%4==0&&year%100!=0)||year%400==0)
        return true;
    return false;
}

int date::maxDay()
{
    switch(month)
    {
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10 :
        case 12 :
           return 31;
        case 4 :
        case 6 :
        case 9 :
        case 11 :
            return 30;
        case 2 :
            if(isLeapYear())
                return 29;
            else
                return 28;
        default :
            return 0;
    }
}

bool date::check()
{
    legal=1;
    if(year<1)
    {
        year=1;
        legal=0;
    }
    if(month<1||month>12)
    {
        month=1;
        legal=0;
    }
    if(day<1||day>maxDay())
    {
        day=1;
        legal=0;
    }
    return legal;
}

void date::setDate(const int y, const int m, const int d)
{
    year=y;
    month=m;
    day=d;
}

void date::nextDay()
{
    day++;
    if(!check())
    {
        month++;
        if(!check())
            year++;
    }
}
void date::print()
{
    if(legal==1)
    {
        cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
    }
}

date& date::operator++()
{
    this->nextDay();
    return *this;
}

const date date::operator++(int)
{
    date d(*this);
    this->nextDay();
    return d;
}

ostream& operator<<(ostream& output, const date& d)
{
    output<<d.year<<"-"<<d.month<<"-"<<d.day;
    return output;
}

istream& operator>>(istream& input, date &d)
{
	int year, month, day;
	cout<<"(格式: 年 月 日): ";
	input>>year>>month>>day;
	d.setDate(year,month,day);
	return input;
}
