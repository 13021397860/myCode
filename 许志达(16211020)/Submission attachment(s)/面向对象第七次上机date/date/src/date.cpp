#include "date.h"
#include<iostream>
using namespace std;
date::date(int year,int month,int day)
{
    setdate(year,month,day);
}
date::date(const date &t)
{
    year=t.year;
    month=t.month;
    day=t.day;
}
date::~date()
{
    //cout<<(year>9999||month>12||day>31? "illegal": "legal")<<endl;
}
void date::setdate(int y,int m,int d)
{
	year=(y>=0&&y<=9999)?y:0;
	month=(m>=0&&m<=12)?m:1;
	day=(d>=0&&d<=31)?d:1;
}
int date::getyear()const
{
	return year;
}
int date::getmonth()const
{
	return month;
}
int date::getday()const
{
	return day;
}
bool date::isleapyear()const
{
	if(year%400==0||(year%100!=0&&year%4==0))
	{
		return true;
	}
	else
	return false;
}
date date::operator ++(int)
{
	if(day<=27)
    {
		day++;
	}
    else
    {
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        {
            if(day<=30&&day>=1)
            {
                 day++;
            }
             else if(month!=12)
             {

                 day=1;month++;
             }
            else
            {
                day=1;month=1;year++;
            }
        }
        else if(month==4||month==6||month==9||month==11)
        {
            if(day<=29&&day>=1)
            {
                 day++;
            }
            else
            {
                day=1;month++;
            }
        }
        else
        {
            if(year%400==0||(year%100!=0&&year%4==0))
            {
                if(day==29)
                {
                  day=1;month++;
                }
                else
                {
                    day++;
                }
            }
            else{
                if(day==28)
                {
                  day=1;month++;
                }
                else
                {
                    day++;
                }

                }
        }

    }
    return *this;
	//cout<<year<<"-"<<month<<"-"<<day<<endl;
}
ostream& operator<<(ostream& output ,const date &c)
{
    output<<"出生日期："<<c.year<<"-"<<c.month<<"-"<<c.day<<endl;
}
