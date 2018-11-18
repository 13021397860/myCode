#include "date.h"
#include <iostream>
#include<cstdio>
using namespace std;

Date::Date(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
	if(!checkDate(year,month,day))//��������Ƿ�Ϸ���������Ϸ����������֤���õ�����ֵ�Ϸ�
    {
        throw MyException(DATE_INVALID);
    }
}

Date::Date(const Date &D)
{
	year=D.year;
	month=D.month;
	day=D.day; 
} 

bool Date::checkDate(int year,int month,int day)
{
	bool flag=true; //�����Ƿ�Ϸ���ȱʡ�Ϸ�
    //�겻���κ�����

    //��Ӧ����1~12֮��
    if ((month<1)||(month>12))
    {
        month=1;    //���¸�Ϊ�Ϸ�����
        flag=false;
    }
    //��Ӧ�����ض��µ����ڷ�Χ֮�ڣ�����1�ͱ����������֮��
    if ((day<1)||(day>maxday()))
    {
        day=1;
        flag=false;
    }
    return flag;
}

bool Date::isLeapYear()
{
	if(year%4==0)
	{
		if(year%100==0)
		{
			if(year%400==0)
			return 1;
			else return 0;
		}
		else return 1;
	} 
	else return 0; 
}

int Date::maxday()
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
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			{
				if(isLeapYear())
				return 29;
				else return 28;
			}
	}
}

bool Date::check()
{
	if(1<=year)
	{
		if(1<=month&&month<=12)
		{
			if(1<=day&&day<=maxday())
			return 1;
			else 
			{
				day=1;
				return 0;
			}

		} 
		else
			{
				month=1;
				return 0;
			}
	}
	else 
	{ 
		year=2000; 
		return 0;
	} 
	return 0;
}

ostream &operator <<(ostream&out,const Date &D)
{
    out<<D.year<<"-"<<D.month<<"-"<<D.day;
    return out;
}
Date& Date::operator++()
{
    nextDay();
    return (*this);
}
Date& Date::operator++(int)
{
    Date old(*this);
    nextDay();
    return old;
}
void Date::setYear(int y)
{
	year=y;
}

void Date::setMonth(int m)
{
	month=m;
}

void Date::setDay(int d)
{
	day=d; 
}
bool Date::setBirthday(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
	if(check())
	return 1;
	else {MyException a=DATE_INVALID;throw a;return 0;} 
}

int Date::getYear()const
{
	return year;
	return 0; 
}

int Date::getMonth()const
{
	
	return month;
	return 0; 
}

int Date::getDay()const
{
	return day;
	return 0; 
}

void Date::nextDay()
{
	day++;
	if(check());
	else
	{
		month++;
		if(check());
		else
		year ++;
	}
}
