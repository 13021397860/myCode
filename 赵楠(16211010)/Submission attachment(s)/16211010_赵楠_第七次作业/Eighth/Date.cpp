#include "Date.h"
#include<iostream>
#include<iomanip>

using namespace std;

Date::Date(int yea,int mon,int da)
{
	setDate(yea, mon, da);
}

Date::Date(const Date&D)
{
	year=D.year;
	month=D.month;
	day=D.day;
}

Date::~Date()
{
	
} 

void Date::setDate(int y,int m,int d)
{
	year=(y<=9999)?y:2000;
	month=(m>=1&&m<=12)?m:1;
	if(m==2)
	{
		day=(month==2&&(isLeapYear())&&d>=1&&d<=29)?d:1;
		day=(month==2&&(!isLeapYear())&&d>=1&&d<=28)?d:1;
	}
	else if(month==4||month==6||month==9||month==11)
	{
		day=((month==4||month==6||month==9||month==11)&&d>=1&&d<=30)?d:1;
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		day=((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&d>=1&&d<=31)?d:1;
	}
}

void Date::setYear(int y)
{
	year=(y<=9999)?y:2000;
}

void Date::setMonth(int m)
{
	month=(m>=1&&m<=12)?m:1;
}

void Date::setDay(int d)
{
	if(month==2)
	{
		day=(month==2&&(isLeapYear())&&d>=1&&d<=29)?d:1;
		day=(month==2&&(!isLeapYear())&&d>=1&&d<=28)?d:1;
	}
	else if(month==4||month==6||month==9||month==11)
	{
		day=((month==4||month==6||month==9||month==11)&&d>=1&&d<=30)?d:1;
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		day=((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&d>=1&&d<=31)?d:1;
	}
}

int Date::getYear()const
{
	return year;
}

int Date::getMonth()const
{
	return month;
}

int Date::getDay()const
{
	return day;
}

bool Date::isLeapYear()
{
	bool i=false;
	if(year%100==0)
	{
		if(year%400==0)
		{
			i=true;
		}
	}
	else
	{
		if(year%4==0)
		{
			i=true;
		}
	}
	return i;
}

void Date::nextDay()
{
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		if(day>=1&&day<=30)
		{
			day++;
		}
		else if(day==31&&month!=12)
		{
			day=1;
			month++;
		}
		else if(day==31&&month==12)
		{
			day=1;
			month=1;
			year++;
		}
	}
	else if(month==2)
	{
		if(isLeapYear()==true)
		{
			if(day>=1&&day<=28)
			{
				day++;
			}
			else if(day==29)
			{
				day=1;
				month=3;
			}
		}
		else if(isLeapYear()==false)
		{
			if(day>=1&&day<=27)
			{
				day++;
			}
			else if(day==28)
			{
				day=1;
				month=3;
			}
		}
	}
	else
	{
		if(day>=1&&day<=29)
		{
			day++;
		}
		else if(day==30)
		{
			day=1;
			month++;
		}
	}
}

Date &Date::operator ++()
{
    //前置
    //期望使用方式 ++a
    nextDay();
    return *this;
}


Date Date::operator ++ (int)
{
    //后置
    //期望使用方式 a++
    Date tmp = *this;
    nextDay();
    return tmp;
}

ostream &operator<<(ostream &output, const Date &D)
{
	output <<D.getYear()<<"-"<<setfill('0')<<setw(2)<<D.getMonth()<<"-"<<setfill('0')<<setw(2)<<D.getDay();
	return output;
}

//void Date::print()const
//{
//	cout<<year<<"-"<<setfill('0')<<setw(2)<<month<<"-"<<setfill('0')<<setw(2)<<day<<endl;
//}

