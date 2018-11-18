#ifndef TIME_H
#define TIME_H
#include <iostream>
#include "MyException.h"
using namespace std;


class time
{
    public:
        time(const int =1900,const int =1,const int =1);
        time (const time &);
        virtual ~time();
        bool checkTime();
        void SetTime (const int ,const int ,const int );
        int getDay () const ;
        int getMonth () const ;
        int getYear () const ;
        void print () const ;
        bool isLeapYear() const ;
        void nextDay();
        friend ostream & operator << (ostream &, time &);
        friend istream & operator >> (istream & ,time &);
        time& operator++();
        time operator++(int);
        time& operator +(int );
    protected:

    private:
        int year;
        int month;
        int day;
};

#endif // TIME_H
