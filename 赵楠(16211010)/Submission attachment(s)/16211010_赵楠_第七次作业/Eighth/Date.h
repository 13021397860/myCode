#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
class Date
{
	public:
		Date(const Date&);
		Date(int yea=1900,int mon=1,int da=1);
		bool isLeapYear();
		void setDate(int y,int m,int d);
		friend ostream &operator<<(ostream&, const Date&);
		Date &operator ++ ();//qianzhi
        Date operator ++ (int);//houzhi
		void setYear(int y);
		void setMonth(int m);
		void setDay(int d);
		int getYear()const;
		int getMonth()const;
		int getDay()const;
		//void print()const;
		void nextDay();
		virtual~Date();
	private:
		int year;
		int month;
		int day;
		
};

#endif
