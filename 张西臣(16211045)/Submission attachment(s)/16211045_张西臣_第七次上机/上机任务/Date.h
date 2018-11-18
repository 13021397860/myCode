#ifndef DATE_H
#define DATE_H

#include<iostream>
using namespace std;
class Date
{
    public:
        Date(const int y,const int m,const int d);
        ~Date();
        Date(const Date &);
        int getyear()const;
        int getmonth()const;
        int getday()const;
        bool setdate(int y,int m,int d);
        bool isLeapYear()const;
        void nextDay();
        Date& operator ++();
        Date operator ++(int);
        friend ostream&  operator <<(ostream&, const Date &c);
        void print()const;
    private:
        int year;
        int month;
        int day;
        int dayscontrol;
        int dayscontrols();
        bool checkdate();
};

#endif // DATE_H
