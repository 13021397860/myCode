
//time.h
#include <iostream>
using namespace std;
#ifndef DATE_H_
#define DATE_H_



class Date
{
	private:
		int year,month,day;
		bool checklegal() const;
	public:
	    void setDate(int y,int m,int d){year=y,month=m,day=d;}
		void setYear(int y){year=y;}
		void setMonth(int m){month=m;}
		void setDay(int d){day=d;}
		int getYear()const{return year;}
		int getMonth()const{return month;}
		int getDay()const{return day;}
		bool isLeapYear()const;
		void nextDay();
		Date();
		Date( int y,int m,int d);
		Date(const Date &d);
		friend ostream& operator<<(ostream& os,const Date& p);
		Date& operator ++();
		Date operator ++ (int);
};


#endif
