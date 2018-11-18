#include "Date.h"
#include<iostream>
#include"MyException.h"
using namespace std;
        Date::Date(){}
		Date::Date(const Date &t)//拷贝构造函数； 
		{
		  	year=t.year;
		  	month=t.month;
		  	day=t.day;
		}
		Date::Date (int n ,int y ,int r)
		{
			year=n;
		  	month=y;
		  	day=r;
		  if(checkLegal()==0)
		  {
		  	throw MyException(Date_wrong);//日期非法 
		  }
		} 
		Date::~Date()
		{
    		//dtor
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
		void Date::setYear(int n)
		{
			year=n;
		}
		void Date::setMonth(int y)
		{
			month=y;
		}
		void Date::setDay(int r)
		{
			day=r;
		}
		bool Date::isLeapYear()
		{
			if(year%400==0)return 1;
			if (year%100==0)return 0;
			if(year%4==0)return 1;
			return 0; 
		}
		 ostream &operator <<( ostream &out, const Date &a)
		{
			out<<a.getYear()<<"-"<<a.getMonth()<<"-"<<a.getDay()<<endl;
			return  out ;
		}
		Date & Date::operator ++() //++前置 
		{
			  nextDay();
			 return *this;
		}
		Date Date::operator ++(int )//++后置 
		{
		     Date old(*this);
		     nextDay();
		     return old;
		}
		bool Date::checkLegal()
		{
			if(month<0||month>12) return 0;
		    else 
		    {
		    	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		    	{
		    		if(day>=1&&day<=31)
					    return 1;
		    		else return 0;
				}
		    	if(month==4||month==6||month==9||month==11)
		    	{
		    		if(day>=1&&day<=30)
						return 1;
		    		else return 0;
				}
				if(month==2&&isLeapYear()==1&&day>=1&&day<=29)
				    return 1;
				if(month==2&&isLeapYear()==0&&day>=1&&day<=28)
				    return 1;
				else return 0;
			}
			
		}
	      void Date::nextDay()
	      {
	      	 if(month==12&&day==31)
	      	{
	      	 	year++;
	      	 	month=1;
	      	 	day=1;
			}
			 else if((month==1||month==3||month==5||month==7||month==8||month==10)&&day==31)
			{
				month++;
				day=1;
			}
			 else if((month==4||month==6||month==9||month==11)&&day==30)
			{
				month++;
				day=1;
			}
			else  if(isLeapYear()==1&&month==2&&day==29)
			{
				month++;
				day=1;
			}
			 else if(isLeapYear()==0&&month==2&&day==28)
			{
				month++;
				day=1;
			}
			else day++;
		  }
	   	  
