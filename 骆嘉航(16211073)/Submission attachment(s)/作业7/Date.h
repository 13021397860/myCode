#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "MyException.h"

using namespace std;

class Date
{
	public:
		Date();
		Date(const int,const int,const int);
		Date(const Date &);
		virtual ~Date();
		int get_year()const;
		int get_month()const;
		int get_day()const;
		void setDate(const int,const int,const int);
		bool isLeapYear()const;
		void nextDay();
		friend ostream &operator << (ostream&,Date &); 
		bool operator == (Date &);
		Date &operator ++();
		Date operator ++(int);
		bool isLegal(const int,const int,const int);
	private:
		int year;
		int month;
		int day;	
};
#endif

