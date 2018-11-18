#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "My_Exception.h"
using namespace std;
class Date
{
    public:
        Date(){year=1900; month=1; day=1;}

        Date ( int y, int m, int d)
        {
            year=y;month=m;day=d;
         if ( !ch())
            throw My_Exception(1);
        }

        Date( const Date &date)
        {

            year=date.year;
            month=date.month;
            day=date.day;
        }
        virtual ~Date();
        int getyear() const {return year;}
        int getmonth() const {return month;}
        int getday() const {return day;}
        void setDate( int , int , int );
        void nextDay( );
        bool isLeapYear();
        int maxmonth();


        friend ostream &operator << ( ostream &, const Date& );
        Date operator++(int );
        Date& operator++();

        protected:

    private:
         bool ch();
         bool check=1;
         int year;
         int month;
         int day;
};

#endif // DATE_H
