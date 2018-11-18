#ifndef DATE_H
#define DATE_H
#include "MyException.h"
#include<iostream>
using namespace std;
class Date
{
	public:
		Date(int y=2000,int m=1,int d=1);
		Date(const Date&); 
		bool isLeapYear();
		void nextDay();
		int getYear()const;
		int getMonth()const;
		int getDay()const;
		void setYear(int y);
		void setMonth(int m);
		void setDay(int d);
		bool setBirthday(int y,int m,int d);
		bool checkDate(int y,int m,int d); 
        friend ostream &operator <<(ostream&out,const Date &A);
        Date &operator ++();
        Date &operator ++(int);
		int maxday();
		bool check();
		private:
		int year,month,day;
};

#endif
