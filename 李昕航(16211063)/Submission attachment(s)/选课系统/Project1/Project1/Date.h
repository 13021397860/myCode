#pragma once
#ifndef DATE_H
#define DATE_H
#include"MyException.h"
#include<iostream>
using namespace std;

class Date
{
public:

	Date();
	Date(int, int, int);
	Date(const Date &);
	virtual ~Date();

	int getYear() const {return year;} 
	int getMonth() const {return month;}
	int getDay() const {return day;}

	void setYear(int);
	void setMonth(int);
	void setDay(int);

	bool isLeapYear(int) const;
	void nextDay();

	Date& operator++();
	Date operator++(int);
	Date operator+(int);

	friend ostream& operator<<(ostream &, const Date);
	friend istream& operator >> (istream &, Date &);

	//void print() const;

protected:
	int year;
	int month;
	int day;
};

#endif // !DATE_H;

