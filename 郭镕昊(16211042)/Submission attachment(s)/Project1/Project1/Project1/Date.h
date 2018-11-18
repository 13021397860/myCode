#pragma once
#ifndef DATE_H
#define DATE_H

#include<iostream>
using std::ostream;

class Date
{
	friend ostream& operator<<(ostream &, const Date &);
public:
	Date();
	Date(int y, int m, int d);
	Date(const Date &a);
	virtual ~Date();

	Date& operator ++();
	Date operator ++(int);//ºóÖÃ×ÔÔö

	bool setDate(int y, int m, int d);
	bool setYear(int y);
	bool setMonth(int m);
	bool setDay(int d);

	int getYear()const {
		return year;
	}
	int getMonth()const {
		return month;
	}
	int getDay()const {
		return day;
	}

	bool isLeapYear()const;

	bool print();
	bool nextDay();
private:
	int year, month, day;
	int getMonthday();
	bool Legal();
};

#endif // !DATE_H
