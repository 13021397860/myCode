#include "Date.h"
#include <bits/stdc++.h>
#include "MyException.h"
using namespace std;
void Date::setYear(int y)
{
    while(true)
    {
        try
        {
            if(y<0) throw MyException();
                break;
        }
        catch(MyException BE)
        {
            cout<<BE.BirthdayError()<<endl;

            cin>>y;
        }
    }
    year=y;

}

void Date::setMonth(int m)
{

    //if(m<=12&&m>=1) month=m;
	//else throw MyException();
    while(true)
    {
        try
        {
            if(m<0||m>12) throw MyException();
                break;
        }
        catch(MyException BE)
        {
            cout<<BE.BirthdayError()<<endl;
            cin>>m;
        }
    }
    month=m;
}

void Date::setDay(int d)
{
	/*if(month==2&&isLeapYear())
		{if(d<=29&&d>=1) day=d;
		else throw MyException();}
	else
		{if(d<=monthDays()&&d>=1) day=d;
		else throw MyException();}*/
    while(true)
    {
        try
        {
            if(month==2&&isLeapYear())
            {
                if(d>29||d<0) throw MyException();
                break;
            }
            else
                if(month==2&&isLeapYear()==false)
            {
                if(d>28||d<0) throw MyException();
                break;
            }
            else
                if(month==1||month==3||month==5||month==7||
                   month==8||month==10||month==12)
            {
                 if(d>31||d<0) throw MyException();
                break;
            }
            else
                if(month==4||month==6||month==9||month==11)
            {
                if(d>30||d<0) throw MyException();
                break;
            }
        }
        catch(MyException BE)
        {
            cout<<BE.BirthdayError()<<endl;
            cin>>d;
        }
    }
    day=d;

}


Date::Date()
{
	setDate(1,1,1);
}

Date::Date(int x,int y,int z)
{
	setDate(x,y,z);

 }

Date::Date(Date &h)
 {
     year=h.year;
     month=h.month;
     day=h.day;
 }

bool Date::isLeapYear()
{
	if((year%400)!=0)
	{
		if(year%4==0)
			return true;
	}
	else
	{
		if(year%400==0)
			return true;
	}
}

void Date::setDate(int y, int m, int d)
{
        setYear(y);
		setMonth(m);
		setDay(d);
}

/*void Date::print()
{
	if(checkDate(year, month, day))
		cout<<year<<"."<<month<<"."<<day<<"\n";
	else
		setDate(1,1,1);
}*/

int Date::checkMonth(int m)
{
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		return 1;
	else
	{
		if(m==4||m==6||m==9||m==11)
		return 2;
		else if(m==2) return 3;
	}
}

void Date::nextDay()
{
	if(day<28)
		day++;
	else
	{
		if(day==28)
			{
				if(checkMonth(month)==1||checkMonth(month)==2)
					day++;
				else
				{
					if(isLeapYear())
						day++;
					else
					{
						day = 1;
						month++;
					}
				}
			}
		else
		{
			if(day==29)
			{
				if(checkMonth(month)==1||checkMonth(month)==2)
					day++;
				else
				{
					day = 1;
					month++;
				}
			}
			else
			{
				if(day==30)
					{
						if(checkMonth(month)==1)
							day++;
						else
						{
							day = 1;
							month++;
						}
					}
				else
				{
					day = 1;
					month++;
				}
			}
		}
	}
	if(month>12)
		{
			day = 1;
			month = 1;
			year++;
		}
}

bool Date::checkDate(int y, int m, int d)
{
	if(y<0||m<1||m>12||d<1||d>31)
		return false;
	else
	{
		if(checkMonth(m)==2)
		{
			if(d>30)
				return false;
		}
		else
		{
			if(checkMonth(m)==3)
			{
				if(isLeapYear())
				{
					if(d>29)
						return false;
				}
				else
				{
					if(d>28)
						return false;
				}
			}
		}
	}

	return true;
}
int Date::getYear(){return year;}

int Date::getMonth(){return month;}

int Date::getDay(){return day;}

Date &Date::operator++()
{
	nextDay();
	return *this;
}

Date Date::operator++(int)
{
    Date tmp=*this;
	nextDay();
	return tmp;
}

ostream& operator<<(ostream& output,const Date& a)
{
	output<<a.year<<'-'<<a.month<<'-'<<a.day;
	return output;
}




