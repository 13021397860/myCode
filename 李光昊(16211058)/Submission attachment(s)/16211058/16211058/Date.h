#ifndef DATE_H
#define DATE_H
#include<iostream>
class Date
{
	
	friend std::ostream &operator<<(std::ostream &,const Date &);
    friend std::istream &operator>>(std::istream &,Date &);
    Date &operator++();
    Date operator++(int);
    Date &operator+(int);
    
	public:
		Date(int y,int m,int d);
        Date();
		Date(const Date &d);
		
		bool set(int y,int m,int d);
		int getYear()const;
		int getMonth()const;
		int getDay()const;
		bool isLeapYear()const;
		
		void nextDay();
		
		void print()const;
		bool check();
		
		virtual ~Date();
		
	protected:
		int year;
		int month;
		int day;
};

#endif
