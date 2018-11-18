#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
class Date
{
	friend ostream &operator<<(ostream&,const Date &);
	public:
		Date(int m=1,int d=1,int y=1900);
		bool setDate(int,int,int);
		Date &operator++();
		Date operator++(int);
		const Date &operator+=(int);
		static bool leapYear(int);
		bool endOfMonth(int) const;
		int getyear();
		int getmonth();
		int getday();
	protected:
	private:
		int year;
		int month;
		int day;
	
		static const int days[];
		void helpIncrement();
};

#endif
