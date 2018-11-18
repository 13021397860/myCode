#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
	public:
		Date();
		Date(int, int, int);
		Date(const Date&);
		
		Date& setDate(const int, const int, const int);
		int getYear() const	{return year;}
		int getMonth() const	{return month;}
		int getDay() const	{return day;}
		
		Date& operator++();
		Date operator++(int);

		void nextDay();
		friend ostream& operator<<(ostream&, const Date&);
		/*void printDate() const;*/
		bool isLegalDate(const int y, const int m, const int d);
		bool isLeapYear(const int) const;
		
		~Date();
		
	protected:
		
	private:
		int year;
		int month;
		int day;
		
		bool isLegalYear(const int) const;
		bool isLegalMonth(const int) const;
		bool isLegalDay(const int, const int, const int) const;
};



#endif
