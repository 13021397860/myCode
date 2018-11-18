#pragma once
#include <iostream>

class Time
{
	friend std::ostream& operator<<(std::ostream& output, const Time &t);
	friend std::istream& operator>>(std::istream& input, Time &t);

public:
	const enum TimeType { Year, Month, Date };

	Time();
	Time(const int y, const int m, const int d);
	Time(const Time &copy_time);
	~Time();
	const int GetTime(const TimeType t) const;
	const void SetTime(const TimeType t, const int x);
	const bool isLeapYear(const int y) const;
	const bool isLegalTime() const;
	const Time& operator++();
	const Time operator++(int);
	const Time& operator+(const int t);
	const Time operator+(const Time &t);

private:
	const int DateOfMonth() const;
	const bool isLongMonth(const int m) const;
	const bool isWrong() const;
	const bool isLegalDate(const int d) const;
	void TimeCorrect();

	int year, month, date;
};