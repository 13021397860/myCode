//Date.h
#ifndef DATE_H
#define DATE_H

#include<iostream>
using namespace std;

class Date {
public:
	Date();
	Date(const int,const int,const int);
	Date(const Date&);

	void setDate(const int,const int,const int);
	void setDate(const Date&);
	void setYear(const int);
	void setMonth(const int);
	void setDay(const int);

	void nextDay();
	//void print()const;
	bool recount();

	int getYear();
	int getMonth();
	int getDay();

	bool isLeapYear();

	Date& operator ++();
	Date operator ++(int);
	Date operator + (int);
	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);

private:
	int year;
	int month;
	int day;
};

#endif // DATE_H_DEFINE
