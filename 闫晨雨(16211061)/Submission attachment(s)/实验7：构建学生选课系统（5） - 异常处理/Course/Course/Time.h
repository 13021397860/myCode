#ifndef TIME_H
#define TIME_H
#include <iostream>
#include "MyException.h"
using namespace std;
class Time
{
public:
	Time();
	Time(const int , const int , const int );
    Time(const Time &);
	virtual~Time();
	void setTime(const int , const int , const int);
	int getYear()const;
	int getMonth()const;
	int getDay()const;
	bool isLeapYear()const;
	void nextDay();
	Time operator ++(int);
	Time& operator ++();
friend ostream& operator <<(ostream& , const Time& );
private:
	int year;
	int month;
	int day;
	bool checkTime();
};

#endif // TIME_H
