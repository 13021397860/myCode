#ifndef DATE_H
#define DATE_H
#include <iostream>
#include "date.h"
using namespace std;
class date
{
    public:
        date(int y=1999, int m=12, int d=31);
        date(date &);
        virtual ~date();
        int getYear(){return year;}
        int getMonth(){return month;}
        int getDay(){return day;}
        void setDate(const int, const int, const int);
        void setYear(const int);
        void setMonth(const int);
        void setDay(const int);
        void print();
        const date operator++(int);
        bool check();
        date& operator++();
        friend ostream& operator<<(ostream&, const date&);
        friend istream& operator>>(istream& input, date &d);
    protected:

    private:
        int day;
        int month;
        int year;
        bool legal;
        bool isLeapYear();
        int maxDay();
        void nextDay();
};

#endif // DATE_H
