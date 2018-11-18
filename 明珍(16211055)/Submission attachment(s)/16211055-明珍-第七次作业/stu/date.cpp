#include "date.h"
#include <iostream>
#include"MyException.h"
using namespace std;


istream& operator >> (istream& is,Date& date) {
	int year;
	int mon;
	int d;
	char del;
	is >> year >> del>>mon>>del>>d;

	date.setDate(year, mon, d);
	if (!date.check()) {


	}
	return is;
}

ostream& operator<<(ostream&os, const Date&date) {

	os << date.year << "-" << date.month << "-" << date.day << endl;
	return os;
}

Date& Date::operator++() {
	static int monday[2][12] = { 31,28,31,30,31,30,31,31,31,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31 };//定义一个二维数组，将闰年和平年的个个月天数存入
	int allDay;
	if (isLeapyear())
	{
		allDay = monday[0][month - 1];//month之所以减一是因为数组是从零开始，这一点容易忽略

	}
	else
	{
		allDay = monday[1][month - 1];
	}

	if (day < allDay)
	{
		++day;
		return *this;
	}

	if (month < 12) {
		++month;
		day = 0;
		return *this;
	}

	++year;
	month = 0;
	day = 0;
	return *this;

}
Date Date::operator++(int) {
	Date bak = *this;

	static int monday[2][12] = { 31,28,31,30,31,30,31,31,31,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31 };//定义一个二维数组，将闰年和平年的个个月天数存入
	int allDay;
	if (isLeapyear())
	{
		allDay = monday[0][month - 1];//month之所以减一是因为数组是从零开始，这一点容易忽略

	}
	else
	{
		allDay = monday[1][month - 1];
	}

	if (day < allDay)
	{
		++day;
		return bak;
	}

	if (month < 12) {
		++month;
		day = 0;
		return bak;
	}

	++year;
	month = 0;
	day = 0;
	return bak;
}

Date::Date(int y,int m,int d)
{
   year=y;
   month=m;
   day=d;
   //ctor
}

Date::Date(const Date &q)//因为是拷贝构造函数
{
    year=q.year;
    month=q.month;
    day=q.day;
}
Date::~Date()
{
    //dtor//程序自带的析构函数，当输出这句话的时候说明第一个变量已被销毁
}
bool Date::setDate(int y,int m,int d)
{
    int a=year;
    int b=month;
    int c=year;
    year=y;
    month=m;
    day=d;
    if(check())
        return true;
    else
    {
     year=a;month=b;day=c;
    return false;
    }
}


bool Date::isLeapyear()const//判断用bool类型最便捷
{
    if ((year%4==0&&year%100!=0)||year%400==0)
        return true;
    else
        return false;
}
bool Date::check()
{

    int monday[2][12]={31,28,31,30,31,30,31,31,31,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};//定义一个二维数组，将闰年和平年的个个月天数存入
    if (isLeapyear())
    {
        if (day>monday[0][month-1])//month之所以减一是因为数组是从零开始，这一点容易忽略
            throw MyException("非法日期格式");
    }
    else
    {
        if(day>monday[1][month-1])
             throw MyException("非法日期格式");
    }
    if (year<1||month>12||month<1||day<1)
    {
		 throw MyException("非法日期格式");
	}

    return true;
}
void Date::nextDate()
{
    int monday[2][12]={31,28,31,30,31,30,31,31,31,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
    day++;
    if (day>monday[isLeapyear()][month-1])
    {
        month ++;
        day=1;
    }
    if (month >12)
    {
        year++;
        month=1;
    }
}
