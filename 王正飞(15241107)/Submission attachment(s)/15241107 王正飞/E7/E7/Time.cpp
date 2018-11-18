#include <iostream>
#include <string>
#include "Time.h"
using namespace std;

Time::Time() :year(1), month(1), date(1) {}

Time::Time(const int y, const int m, const int d) : year(y), month(m), date(d) {}

Time::Time(const Time &copy_time) : year(copy_time.year), month(copy_time.month), date(copy_time.date) {}

Time::~Time() {}

const int Time::GetTime(const TimeType t) const
{
	switch (t)
	{
	case Year: return year; break;
	case Month: return month; break;
	case Date: return date; break;
	default: return -1; break;
	}
}

const void Time::SetTime(const TimeType t, const int x)
{
	switch (t)
	{
	case Year: year = x; break;
	case Month: month = x; break;
	case Date: date = x; break;
	}
}

const bool Time::isLeapYear(const int y) const
{
	return(y % 4 != 0 || y % 100 == 0 && y % 400 != 0) ? false : true;
}

const bool Time::isLongMonth(const int m) const
{
	return m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12;
}

const bool Time::isLegalDate(const int d) const
{
	return d > 0 && d <= DateOfMonth();
}

const bool Time::isWrong() const
{
	return year < 0 || month <= 0 || month >= 13 || !isLegalDate(date);
}

void Time::TimeCorrect()
{
	int temp_year = year, temp_month = month, temp_date = date;
	while (!isLegalDate(date))
	{
		if (date > 0) { date -= DateOfMonth(); month++; }
		else if (date <= 0) { month--; date += DateOfMonth(); }
		if (month <= 0) { month = 12; year--; }
		else if (month > 12) { month = 1; year++; }
		if (year < 0) { year = temp_year; month = temp_month; date = temp_date; cout << "Year cannot be lower than 0.\n"; return; }
	}
}

const int Time::DateOfMonth() const
{
	return month == 2 ? 28 + (int)isLeapYear(year) : 30 + (int)isLongMonth(month);
}

ostream& operator<<(ostream &output, const Time &t)
{
	output << t.year << "-" << t.month << "-" << t.date;
	return output;
}

istream& operator>>(istream &input, Time &t)
{
	int input_year, input_month, input_date;
	input >> input_year >> input_month >> input_date;
	t.SetTime(Time::Year, input_year);
	t.SetTime(Time::Month, input_month);
	t.SetTime(Time::Date, input_date);
	return input;
}

const Time& Time::operator++()
{
	date++;
	TimeCorrect();
	return *this;
}

const Time Time::operator++(int)
{
	Time temp(*this);
	date++;
	TimeCorrect();
	return temp;
}

const Time& Time::operator+(const int t)
{
	date += t;
	TimeCorrect();
	return *this;
}

const Time Time::operator+(const Time &t)
{
	Time temp(year + t.year, month + t.month, date + t.date);
	temp.TimeCorrect();
	return temp;
}

const bool Time::isLegalTime() const
{
	return year > 0 && month > 0 && month < 13 && isLegalDate(date);
}