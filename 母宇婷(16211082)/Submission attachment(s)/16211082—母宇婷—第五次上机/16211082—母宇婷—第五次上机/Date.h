#ifndef DATE_H
#define DATE_H
#include <iostream>
using std::ostream; 

class Date
{
	friend ostream& operator<<(ostream &,const Date &);
    public:
        Date(int ,int ,int );
        Date();
        Date &operator++();
        Date operator++(int);
        int getyear()const;
        int getday()const;
        int getmonth()const;
        void setDate(int y,int m,int d);
        void nextDay();
        int runnian(int y);
        bool panduan();
        Date ( const Date &d)
        {
        	year=d.year;
        	month=d.month;
        	day=d.day;
		}

    protected:

    private:
        bool isLeapYear(int year);
        int year,month,day;
};

#endif // Date_H
