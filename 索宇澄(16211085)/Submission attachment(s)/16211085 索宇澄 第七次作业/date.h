#include<iostream>

using namespace std;
#ifndef DATE_H
#define DATE_H

class Date
{
	friend ostream & operator<<(ostream & , const Date & );
	public:
		Date();
		Date(int, int, int);
		Date(const Date &);
		
		Date & operator++();
		Date operator++( int );
		
		int getyear() const;
		int getmonth() const;
		int getday() const;
		void setyear(int y);
		void setmonth(int m);
		void setday(int d);
		void nextday();
		~Date();
	private:
		int year;
		int month;
		int day;
		bool isLeapYear(int y);

};
#endif
