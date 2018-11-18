#include<iostream>
#ifndef DATE_H
#define DATE_H
#include<stdio.h>
using namespace std;
class Date
{
    public:
        Date(int y=1998,int m=1,int d=1);
        Date(Date &);
        virtual ~Date();
        int getYear()const {return year;}
        int getMonth()const {return month;}
        int getDay() const {return day;}
        void setDate(int,int,int);
        void print() const;
        void nextDay();
        bool check() const;
        Date& operator ++ ()
        {
            this->nextDay();
            return *this;
        }
        Date operator ++ (int hz)
        {
            Date tmp=*this;
            ++(*this);
            return tmp;
        }
        Date& operator + (int hz)
        {
            while(hz--)
            this->nextDay();
            return *this;
        }
        friend ostream& operator << (ostream& out, const Date& c);
    protected:
    private:
        int year;
        int month;
        int day;
        bool LeapYear() const;
};

#endif // DATE_H
