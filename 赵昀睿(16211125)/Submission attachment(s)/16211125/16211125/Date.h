#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "IllegalDate.h"
using namespace std;

class Date
{
    public:
        Date();
        Date( int m, int d, int y );
        Date( const Date &anoDate );
        virtual ~Date();
        //
        void setDate( int m, int d, int y );
        Date getDate()const;
        int getMonth()const;
        int getDay()const;
        int getYear()const;
        bool isLeapYear()const;
        void nextDay();
        //
        friend ostream& operator<<(ostream&, const Date&);
        Date& operator++();
        Date operator++( int );

    protected:

    private:
        int month;
        int day;
        int year;
        //
        bool isLeagal()const;
};

#endif // DATE_H
