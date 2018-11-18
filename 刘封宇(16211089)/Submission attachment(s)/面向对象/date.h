#ifndef DATE_H
#define DATE_H
#include <iostream>
using std::ostream;
using std::istream;
class Date{
	
		friend ostream& operator<<(ostream &,const Date &);
		friend istream& operator>>(istream& input,const Date &d);
		
	public:
		
		Date& operator++();
		Date operator++(int);
		
		Date();
		Date(int, int, int);
		Date(const Date &);
		int getYear() const;
		int getMonth() const;
		int getDay() const;
		void setDate(int y,int m,int d);
		bool checkDate();
		void nextDay();
		
		void printDate() const;
		
		~Date();
		bool isLeapYear();
	private:
		int year,month,day;
		
};
#endif

