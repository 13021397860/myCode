#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
	public:
		Date(int =1990,int =1,int =1);
		Date(Date &D);
		virtual ~Date();
		
		void datecpy(const Date &D);
		
		int getYear()const{return year;}
		int getMonth()const{return month;}
		int getDay()const{return day;}
		
		bool setYear(int );
		bool setMonth(int );
		bool setDay(int );
		bool setAll(int ,int ,int );
		
		bool isYear()const;
		bool isMonth()const;
		bool isDay()const;
		bool isAll()const;
		
		bool isLeapYear()const;	
		void nextDay(); 
		
		friend ostream& operator << (ostream& out,const Date & c)
		{
			out<<c.getYear();
			out<<"--";
			out<<c.getMonth();
			out<<"--";
			out<<c.getDay();
			out<<endl;
			return out;
		}
		
		Date& operator ++ (int )
		{
			if(day<28)
			{
				day++;
			}
			else if(day==28)
			{
				if(month!=2)
				{
					day++;
				}
				else
				{
					if(isLeapYear())
					{
						day=29;
					}
					else 
					{
						day=1;month=3;
					}
				}
			}
			else if(day==29)
			{
				if(month==2)
				{
					day=1;month=3;
				}
				else 
				{
					day++;
				}
			}
			else if(day==30)
			{
				if(month==2||month==4||month==6||month==9||month==11)
				{
					day=1;month++;
				}
				else
				{
					day++;
				}
			}
			else if(day==31)
			{
				if(month==12)
				{
					year++;month=1;day=1;
				}
				else
				{
					month++;day=1;
				}
			}
			return *this;
		}

	private:
		int year,month,day;
};
#endif
