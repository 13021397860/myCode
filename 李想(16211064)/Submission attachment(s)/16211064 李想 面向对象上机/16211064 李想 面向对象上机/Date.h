#ifndef DATE_H
#define DATE_H
#include<bits/stdc++.h>
using namespace std;
class Date
{
	public:
	    friend ostream& operator<<(ostream&,const Date&);
		Date();//构造函数，无返回类型。 而且此构造函数是缺省构造函数。
		Date(int,int,int);
		Date(Date &h);
		int getYear();
		int getMonth();
		int getDay();
    	void setYear(int);
		void setMonth(int);
		void setDay(int);
		void setDate(int, int ,int);
 		bool checkDate(int, int , int);
		bool isLeapYear();
		void nextDay();
		//void print();
		Date &operator++();
		Date operator++(int);
		int checkMonth(int);

	protected:
	private:
		int year;
		int month;
		int day;
};
ostream& operator<<(Date&,ostream);
#endif
