#ifndef DATE_H
#define DATE_H
#include<iostream>
class Date
{
    public:
        Date();
        Date(int,int,int);
        Date(const Date &);
        virtual ~Date();
        void setDate(int,int,int);
        void setYear(int y)
		{
			year=y;
		}
        void setMonth(int m)
		{
			month=m;
		}
        void setDay(int d)
		{
			day=d;
		}
        int getYear()const
		{
			return year;
		}
        int getMonth()const
		{	
			return month;
		}
        int getDay()const
		{	
			return day;
		}
        bool isLeapYear()const
		{	
			return((year%100)&&!(year%4))||!(year%400);
		}
        void nextDay();
        void clean()
		{	
			year=0;
			month=0;
			day=0;
		}
        bool judgement()const;
        Date &operator++();
        Date operator++(int);
        friend std::ostream&operator<<(std::ostream& o,const Date& a);
        friend std::istream&operator<<(std::istream& i,Date &a);
    private:
        int year,month,day;
};
#endif
