#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
	public:
		Date();
		Date(const int,const int,const int);
		Date(const Date&);
		int getYear()const;
		int getMonth()const;
		int getDay()const;

		bool setDate(const int,const  int ,const int);
		void nextDay();
		void setYear(const int);
		void setMonth(const int);
		void setDay(const int);
		void Datecpy(Date&,const Date&);

		bool isLeapYear()const;
		bool validDate(const int,const int,const int)const;
		friend ostream &operator<<(ostream &,const Date);
		friend istream &operator>>(istream &,Date&);
	    Date& operator ++ ();  //前置
        Date operator ++ (int); //后置
		Date operator + (int);   //加上任意日期

		virtual ~Date();

	protected:

	private:
		int year;
		int month;
		int day;
};

#endif // DATE_H
