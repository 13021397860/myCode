#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
/*
 * No description
 */
class Date
{
	private:
	int year;
	int month;
	int day;
	int checklegal();
	void check(int);// private section
	public:
		void setyear(int);
		void setmonth(int);
		void setday(int);
		int getyear(){
			return year;
		}
		int getmonth(){
			return month;
		}
		int getday(){
			return day;
		}
		bool isLeapYear();
		void nextDay();
		void print()const;
		friend ostream &operator << (ostream &,const Date &);
		Date &operator++();
		Date operator++(int);
		// class constructor
		Date(int =2000,int =1,int =1);
		// class destructor
		~Date();
		Date(const Date &); 
	protected:
};

#endif // DATE_H

