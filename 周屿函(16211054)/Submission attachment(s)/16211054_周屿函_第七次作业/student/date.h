#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
    friend ostream& operator<<(ostream&,Date&);
    friend istream& operator>>(istream&,Date&);
    public:
        Date();
        Date(int y,int m,int d);
        Date(const Date &);
        virtual ~Date();
        //void print()const;

        int getYear()const {return year;}
        int getMonth()const{return month;}
        int getDay()const{return day;}
        bool isLeapYear()const;
        void nextDay();
        bool setDate(int y,int m,int d);
        Date &operator++();
        Date &operator++(int);
        Date &operator+(int x);
    protected:

    private:
        bool check();
        int year,month,day;
};

#endif // DATE_H
