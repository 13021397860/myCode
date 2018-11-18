#include "stdafx.h"

#include "Date.h"
#include<iostream>
#include<cstring>

using namespace std;

int Date::daylib[15] = { 0,31,28,31,30,31,30,31,31,30,31,30,31,0,29 };

Date::Date() :
	year(0), month(1), day(1)
{

}

Date::Date(int y, int m, int d) :
	Date::Date()
{
	if (check(y, m, d)) {
		Date::year = y;
		Date::month = m;
		Date::day = d;
	}
	else { cout << "Illegal parameter !\n"; }

}

Date::Date(const Date & date) {
	day = date.day;
	month = date.month;
	year = date.year;
}

Date::~Date() {
	cout << "Date Object Destroyed !" << endl;
}

int Date::GetYear(void) const{ return year; }

int Date::GetMonth(void)const { return month; }

int Date::GetDay(void)const { return day; }

void Date::SetYear(int y) {
	if (check(y, month, day)) {
		year = y;
	}
	else {
		cout << "Illegal Input !";
	}
}

void Date::SetMonth(int m) {
	if (check(year, m, day)) {
		month = m;
	}
	else {
		cout << "Illegal Input !";
	}
}

void Date::SetDay(int d) {
	if (check(year, month, d)) {
		day = d;
	}
	else {
		cout << "Illegal Input !";
	}
}

bool Date::TestLeapYear(int y) {
	if (y % 4 == 0) {
		if (y % 400 == 0)
			return true;
		else if (y % 100 == 0)
			return false;
	}
	else
	{
		return false;
	}
}

bool Date::IsLeapYear(void)const {
	if (year % 4 == 0) {
		if (year % 400 == 0)
			return true;
		else if (year % 100 == 0)
			return false;
	}
	else
	{
		return false;
	}
}

void Date::NextDay(void) {

	day++;
	if (IsLeapYear()) {
		if (month == 2)
			if (day > daylib[14]) {
				day = 1;
				month++;
			}
	}
	else {
		if (day > daylib[month]) {
			day = 1;
			month++;
		}

	}

	if (month > 12) {
		year++;
		month = 1;
	}

}

/*
void Date::Print(void)const {
	cout << year << '-' << month << '-' << day << '\n';
}
*/

ostream& operator<<(ostream& os, const Date &date) {
	os << date.year << ' ' << date.month << ' ' << date.day;
	return os;
}

Date& Date::operator++() {
	NextDay();
	return *this;
}

Date Date::operator++(int){
	Date tmp = *this;
	++(*this);
	return tmp;
}

bool Date::check(int y, int m, int d) {
	if (m > 12 || m < 1)return false;
	if (TestLeapYear(y) && m == 2) {
		if (d > daylib[14]) return false;
	}
	else {
		if (d > daylib[m])return false;
	}
	if (d < 1)return false;
	return true;
}