//Date.cpp
#include"Date.h"
#include"MyException.h"
#include<iostream>
using namespace std;

int month_to_day[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

ostream& operator << (ostream& output, const Date& _Date) {
	output<<_Date.year<<"-"<<_Date.month<<"-"<<_Date.day;
	return output;
}

istream& operator >> (istream& input, Date& _Date) {
	int year,month,day;
	input>>year>>month>>day;
	_Date.setDate(year,month,day);
	return input;
}

Date& Date::operator ++() {
	this->nextDay();
	return *this;
}

Date Date::operator ++(int) {
	Date temp=*this;
	this->nextDay();
	return temp;
}

Date Date::operator + (int _day) {
	Date temp=*this;
	temp.day+=_day;
	while(temp.recount());
	return temp;
}

Date::Date() {
	year=1;
	month=1;
	day=1;
}

Date::Date(const int y,const int m,const int d) {
	setDate(y,m,d);
}

Date::Date(const Date& a) {
	year=a.year;
	month=a.month;
	day=a.day;
}

void Date::setDate(const int y,const int m,const int d) {
	year=y;
	month=(m>0&&m<13)?m:throw MyException(0);
	if(Date::isLeapYear()) {
		month_to_day[2]=29;
	}
	day=(d>0&&d<=month_to_day[month])?d:throw MyException(0);
	month_to_day[2]=28;
}

void Date::setDate(const Date& a) {
	year=a.year;
	month=a.month;
	day=a.day;
}

void Date::setYear(const int y) {
	year=y;
	recount();
}

void Date::setMonth(const int m) {
	month=(m>0&&m<13)?m:1;
	recount();
}

void Date::setDay(const int d) {
	if(isLeapYear()) {
		month_to_day[2]=29;
	}
	day=(d>0&&d<=month_to_day[month])?d:1;
	month_to_day[2]=28;
	recount();
}

void Date::nextDay() {
	day++;
	recount();
}

//void Date::print()const{
//	cout<<year<<"."<<month<<"."<<day<<endl;
//}

bool Date::recount() {
	bool flag=0;
	if(isLeapYear()) {
		month_to_day[2]=29;
	}
	if(day>month_to_day[month]) {
		day-=month_to_day[month];
		month++;
		flag=1;
	}
	if(month>12) {
		month-=12;
		year++;
		flag=1;
	}
	month_to_day[2]=28;

	return flag;
}

int Date::getYear() {
	return year;
}

int Date::getMonth() {
	return month;
}

int Date::getDay() {
	return day;
}

bool Date::isLeapYear() {
	if((year%4==0&&year%100!=0)||(year%400==0)) {
		return true;
	}
	return false;
}
