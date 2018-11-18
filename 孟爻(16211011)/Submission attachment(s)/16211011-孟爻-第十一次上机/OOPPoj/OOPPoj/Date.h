#pragma once
#ifndef _Date_
#define _Date_
#include<iostream>
using namespace std;
class Date {
public:
	Date();
	Date(int y, int m, int d);
	~Date();
	Date(const Date &date);
	int GetYear(void)const;
	int GetMonth(void)const;
	int GetDay(void)const;
	void SetYear(int y);
	void SetMonth(int m);
	void SetDay(int d);
	bool IsLeapYear(void)const;
	void NextDay(void);
	//void Print(void)const;
	friend ostream& operator<<(ostream&,const Date&);
	Date& operator++();
	Date operator++(int);
	static bool TestLeapYear(int y);
protected:
private:
	int year, month, day;
	static int daylib[15];
	bool check(int y, int m, int d);
};

#endif // !1
