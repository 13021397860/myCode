#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
	public:
		Date();
		Date(const Date &);
		~Date();
		friend ostream& operator << (ostream &, Date &); 
		bool isLeapYear(const int );
		void setDate(const int, const int, const int );
		int get_day() const;
		int get_month() const;
		int get_year() const;
		void nextDay();
		Date &operator++();
		Date operator++(int);
	private:
		int month;
		int day;
		int year;
};
#endif

