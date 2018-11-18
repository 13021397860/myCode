#pragma once
#ifndef DATE_H
#define DATE_H
#include<iostream>
#include"MyException.h"
#include"DateException.h"
using namespace std;
class Date
{
public:
	Date();
	bool isLeapYear();
	bool setDate(const int &y,const int &m,const int &d);
	bool checkDate();
	void nextDay();
	Date& operator ++(int);
	Date operator ++();
	friend ostream& operator << (ostream&, Date&);
	int getDate(char)const;
	//void print()const;
	Date(Date&);
	~Date();
private:
	int year;
	int month;
	int day;
	int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
};
#endif

