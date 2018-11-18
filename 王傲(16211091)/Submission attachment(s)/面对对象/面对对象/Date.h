#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <stdlib.h>
using namespace std;
class Date
{
	public:
		Date();
		Date(int, int, int);
		Date(const Date &);
		
		void setDate(int, int, int);
		int getYear() const	{return year;}
		int getMonth() const	{return month;}
		int getDay() const	{return day;}
		
		void nextDay();
		void printDate() const;
		//жиди<< 
		friend istream& operator>>(istream&,Date&);
		friend ostream& operator<<(ostream&,const Date&);
		//жиди++
		Date operator ++( );
		Date operator ++( int );
		
		bool isLegalDate();
		bool isLeapYear(int) const;
		
		~Date();
		
	protected:
		
	private:
		int year;
		int month;
		int day;
		
		bool isLegalYear(int);
		bool isLegalMonth(int);
		bool isLegalDay(int, int, int);
};

#endif
