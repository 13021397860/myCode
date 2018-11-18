#include <iostream>
using namespace std; 
#ifndef DATE_H
#define DATE_H

#include "MyException.h"

class Date 
{
	friend ostream& operator<<(ostream& output, const Date& d)
	{
		output<< d.year << "-" << d.month << "-" << d.day<<endl; 
		return output;
	}
		
	public:
		Date(int = 1,int = 1,int = 1);
		Date(const Date &);
		~Date(); 
		void setDate(const int,const int,const int);
		bool checkDate() const;
		int maxDay() const;
		int getYear() const ;
		int getMonth() const ;
		int getDay() const ;
		bool isLeapYear() const;
		void nextDay();
		//void print() const;
		Date &operator++();
		Date operator++(int);

	private:
		int year;
		int month;
  		int day;	
};

#endif
