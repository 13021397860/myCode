#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
class Date
{
    public:
        Date();
        Date(const Date&);
        Date(int _year,int _month,int _day);
        bool setTime(int _year,int _month,int _day);
        bool setYear(int _year);
        bool setMonth(int _month);
        bool setDay(int _day);
        int getYear()const;
        int getMonth()const;
        int getDay()const;
        bool isLeapYear()const;
        void nextDay();
        friend ostream &operator <<(ostream&out,const Date &A);
        friend istream &operator >>(istream&in,Date &A);
        Date &operator ++();
        Date operator ++(int);
        Date operator +(int _number);
        Date operator +=(int _number);
        virtual ~Date();
    protected:
    private:
        int year;
        int month;
        int day;
        bool check();
};

#endif // DATE_H
