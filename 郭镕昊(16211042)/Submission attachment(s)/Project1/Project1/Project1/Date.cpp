
#include"Date.h"

#include<iostream>
#include<iomanip>
#include "MyException.h"

using namespace std;

Date::Date() {
	year = 1970;
	month = day = 1;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
	if (!Legal()) throw MyException(Date_invalid);
}

Date::Date(const Date & a)
{
	year = a.year;
	day = a.day;
	month = a.month;
}

Date::~Date() {
	//cout << "A 'Date' has been destroyed\n";
}

Date & Date::operator++()
{
	nextDay();
	return *this;
}

Date Date::operator++(int)//后置自增
{
	Date d = *this;
	nextDay();
	return d;
}

bool Date::setDate(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
	return Legal();
}

bool Date::setDay(int d) {
	day = d;
	return Legal();
}
bool Date::setMonth(int m) {
	month = m;
	return Legal();
}
bool Date::setYear(int y) {
	year = y;
	return Legal();
}

bool Date::isLeapYear()const {
	return year % 100 != 0 ? year % 4 == 0 : year % 400 == 0;
}

int Date::getMonthday() {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	if (month == 2) return isLeapYear() ? 29 : 28;
	return 0;
}


bool Date::nextDay() {
	if (!Legal()) return 0;
	++day;
	if (day > getMonthday()) day = 1, ++month;
	if (month > 12) month = 1, ++year;
	return 1;
}

bool Date::print() {
	if (!Legal()) return 0;
	cout << setfill('0') << setw(4) << year << ':' << setfill('0') << setw(2) << month
		<< ':' << setfill('0') << setw(2) << day << endl;
	return 1;
}

bool Date::Legal() {
	bool flag = 1;
	if (year <= 0 || year >9999) flag = 0;
	if (month < 1 || month > 12) flag = 0;
	if (day < 1 || day > getMonthday()) flag = 0;
	if (!flag) {
		year = 1970;
		month = day = 1;
	}
	return flag;
}

ostream & operator<<(ostream &output, const Date &d)
{
	output << d.year << '-' << d.month << '-' << d.day;
	return output;
	// TODO: 在此处插入 return 语句
}
