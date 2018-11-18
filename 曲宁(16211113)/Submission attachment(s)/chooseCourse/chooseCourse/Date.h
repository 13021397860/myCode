#ifndef DATE_H
#define DATE_H

#include<iostream>
using namespace std;

class Date
{
        friend ostream &operator<<( ostream &,const Date &);
    public:
        Date(int y=1990,int m=1,int d=1);
        Date();
        Date(const Date &);
        void setDate(int ,int ,int );
        Date &operator++();
        Date operator++( int );
        const Date &operator+=( int );
        int getYear()const;
        int getMonth()const;
        int getDay()const;
        void nextDay();
        static bool isLeapYear( int );
        bool endOfMonth( int )const;    //判断某天是否为最后一天
        virtual ~Date();

    protected:

    private:
        int month;
        int day;
        int year;

        static const int days[];
        void helpIncrement();
};

#endif // DATE_H
