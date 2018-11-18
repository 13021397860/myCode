#ifndef TIME_H
#define TIME_H
#include<iostream>
#include"MyException.h"
using namespace std;

class Date
{
    public:
        Date();
        Date(const int, const int, const int);
        Date(const Date &);
        virtual ~Date();
        int getYear() const {return year;}
        int getMonth() const {return month;}
        int getDay() const {return day;}
        void setTime(const int, const int, const int);
        bool isLeapYear();
        bool check();
        void nextDay();
        void print()const;
        friend ostream& operator<<(ostream& , const Date&);
        Date& operator++();
        Date operator++(int);
    protected:

    private:
        int year, month, day;
};

#endif // TIME_H
