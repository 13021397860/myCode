#include "date.h"
#include "MyException.h"
#include <iostream>
using std::cin;
using std::cout;
bool date::judge() const
{
	if (month < 1 || month>12)
		return 0;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		if (day > 31 || day < 0)
			return 0;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day > 30 || day < 0)
			return 0;
	if (month == 2)
	{
		if (year % 4 || !(year % 1000))
		{
			if (day > 28 || day < 0)
				return 0;
		}
		else
		{
			if (day > 29 || day < 0)
				return 0;
		}
	}
	return 1;
}
void date::judge1() const
{
	if (!judge())
		throw bad_date();
}
date::date()
{

}
date::date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (!judge())
	{
		cout << "Invalid Input!\nThe date is set to 0.0.0\n";
		year = month = day = 0;
	}
}
date::date(const date & t)
{
	year = t.year;
	month = t.month;
	day = t.day;
}
date::~date()
{

}
int date::getyear() const
{
	return year;
}
int date::getmonth() const
{
	return month;
}
int date::getday() const
{
	return day;
}
date date::get() const
{
	return *this;
}
void date::set(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (!judge())
	{
		cout << "Invalid Input!\nThe date is set to 0.0.0\n";
		year = month = day = 0;
	}
}
bool date::isLeapYear() const
{
	if (year % 4 || !(year % 1000))
		return 0;
	return 1;
}
date& date::nextDay()
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
	{
		if (day < 31)
			day++;
		else
		{
			day = 1;
			month++;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 30)
			day++;
		else
		{
			day = 1;
			month++;
		}
	}
	else if (month == 12)
	{
		if (day < 31)
			day++;
		else
		{
			day = 1;
			month = 1;
			year++;
		}
	}
	else if (month == 2)
	{
		if (isLeapYear())
		{
			if (day < 29)
				day++;
			else
			{
				month++;
				day = 1;
			}
		}
		else
		{
			if (day < 28)
				day++;
			else
			{
				month++;
				day = 1;
			}
		}
	}
	return *this;
}

/*
void date::print() const
{
	cout << year << ".";
	if (month < 10)
		cout << "0";
	cout << month << ".";
	if (day < 10)
		cout << "0";
	cout << day << "\n";
}
*/

std::ostream & operator<<(std::ostream & os, const date & t)
{
	os << t.year << "-";
	if (t.month < 10)
		os << "0";
	os << t.month << "-";
	if (t.day < 10)
		os << "0";
	os << t.day << "\n";
	return os;
}
std::istream & operator>>(std::istream & is, date & t)
{
	while (cin >> t.year >> t.month >> t.day)
	{
		try
		{
			t.judge1();
		}
		catch (bad_date & bd)
		{
			cout << bd.what();
			cout << "\n请重新输入！\n请输入学生生日：";
			continue;
		}
		break;
		/*
		if (!t.judge())
		{
			
			cout << "Invalid Input!\nThe date is set to 0.0.0\n";
			t.year = t.month = t.day = 0;
			
		}
		*/
	}
	return is;
}
date &date::operator=(const date &a)
{
	year = a.year;
	month = a.month;
	day = a.day;
	return *this;
}