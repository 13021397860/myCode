#ifndef DATE_H
#define DATE_H
#include <cstdio>
#include <iostream>
#include "MyException.h"
using namespace std;
class date
{
    public:
        date(const int =2000,const int =1,const int=1);
        date(const date &);
        int getYear()const{return year;}
        int getMonth()const{return month;}
        int getDay()const{return day;}
        void setDate(int ,int ,int );
        bool isLeapYear()const;
        void nextDay();
        //void print()const;
        bool isLegalDate()const;
        date operator ++(int i);
        date &operator ++();
        date &operator + (const int t);
        friend istream & operator >> (istream &,date &);
        friend ostream & operator << (ostream &,const date &);
    //protected:
    private:
        int year;
        int month;
        int day;
};

#endif // DATE_H
