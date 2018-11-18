#ifndef DATE_H
#define DATE_H
#include <iostream>
#include "MyException.h"
using namespace std;

class Date
{
	public:
		Date(int = 1998, int = 4, int = 4);
		Date(const Date &t);
		~Date();

		void setDate(const int ,const int ,const int);
		void setYear(const int);
		void setMonth(const int);
		void setDay(const int);

		int getYear() const;
		int getMonth() const;
		int getDay() const;

		bool isLeapYear();
		void nextDay();

        friend ostream &operator<<(ostream &, const Date &);
        friend istream &operator>>(istream &,Date &);
		Date &operator++();
		Date operator++(int);
		Date operator+(int);

	private:
		int day_of_month();
		int year;
		int month;
		int day;
};

#endif
