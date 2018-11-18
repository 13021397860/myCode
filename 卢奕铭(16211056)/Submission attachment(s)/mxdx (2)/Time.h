#ifndef TIME_H
#define TIME_H
#include<iostream>
#include<MyException.h>
using namespace std;

class Time
{

public:
	Time();
	Time(int , int , int );
    Time(const Time &);
	~Time();
	void setTime(int ,int , int);
	int getYear()const;
	int getMonth()const;
	int getDay()const;
	bool isLeapYear()const;
	void nextDay();
	void print()const;
	Time operator++(int);
	Time operator++();
	friend ostream& operator<< (istream& outs,const Time& p);

private:
	int year;
	int month;
	int day;
	bool checkTime();
};

#endif // TIME_H
