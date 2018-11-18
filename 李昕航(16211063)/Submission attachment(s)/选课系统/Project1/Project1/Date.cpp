#include"Date.h"

Date::Date()
	: year(1900), month(1), day(1)
{
}

Date::Date(int y,int m,int d)
	: year(y), month(m), day(d)
{
}

Date::Date(const Date &t)
{
	year = t.year;
	month = t.month;
	day = t.day;
}

Date::~Date()
{
}

void Date::setYear(int x)
{
	if (x != 0)
		year = x;
	else throw MyException(Date_Invalid);
}

void Date::setMonth(int x)
{
	if (x > 0 && x < 13)
		month = x;
	else throw MyException(Date_Invalid);
}

void Date::setDay(int x)
{
	if ((getMonth() == 1 || getMonth() == 3 || getMonth() == 5 ||
		getMonth() == 7 || getMonth() == 8 || getMonth() == 10 ||
		getMonth() == 12) && x < 32 && x>0)
		day = x;
	else if ((getMonth() == 4 || getMonth() == 6 || getMonth() == 9 ||
		getMonth() == 11) && x < 31 && x>0)
		day = x;
	else if (getMonth() == 2 && isLeapYear(getYear()) && x > 0 && x < 30)
		day = x;
	else if (getMonth() == 2 && !isLeapYear(getYear()) && x > 0 && x < 29)
		day = x;
	else throw MyException(Date_Invalid);
}

bool Date::isLeapYear(int x) const
{
	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
		return true;
	else return false;
}

void Date::nextDay()
{
	int mm[2][12] = { 31,28,31,30,31,30,31,31,30,31,30,31,
	31,29,31,30,31,30,31,31,30,31,30,31 };
	if (getDay() != mm[isLeapYear(getYear())][getMonth()-1])
		day++;
	else if (getMonth() != 12)
	{
		day = 1;
		month++;
	}
	else if (getYear() != -1)
	{
		day = 1;
		month = 1;
		year++;
	}
	else
	{
		day = 1;
		month = 1;
		year = 1;
	}
}

Date& Date::operator++()
{
	nextDay();
	return *this;
}

Date Date::operator++(int x)
{
	Date c = *this;
	nextDay();
	return c;
}

Date Date::operator+(int x)
{
	Date c = *this;
	for (int i = 0; i < x; i++)
		c.nextDay();
	return c;
}

ostream& operator<<(ostream& os, const Date c)
{
	os << c.getYear() << " " << c.getMonth() << " " << c.getDay() << endl;
	return os;
}

istream& operator >> (istream& is, Date &c)
{
	int year, month, day;
	cout << "Please input year, month, and day." << endl;
	is >> year >> month >> day;
	c.setYear(year);
	c.setMonth(month);
	c.setDay(day);
	return is;
}
