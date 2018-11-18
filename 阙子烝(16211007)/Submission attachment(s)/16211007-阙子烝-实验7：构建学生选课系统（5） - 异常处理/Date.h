#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date
{
	public:
		const static int mlenth[2][13];
		Date(const int y=1900,const int m=1,const int d=1);
		Date(const Date &d);
		virtual ~Date();
		void setDate(const int y,const int m,const int d);
		void setDate_Force(const int y,const int m,const int d);
		void setYear(const int y);
		void setMonth(const int m);
		void setDay(const int d);
		int getYear() const;
		int getMonth() const;
		int getDay() const;
		//void print();
		Date& operator++();
		const Date operator++(int );
		friend std::istream& operator>>(std::istream&,Date&);
		friend std::ostream& operator<<(std::ostream&,const Date&);
		const Date operator+(const int &num);
		bool check();
		
	protected:
	
	private:
		int year,month,day;
		bool isLeapYear();
		void nextDay();
};

#endif
