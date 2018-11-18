#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<iomanip>
using namespace std;

class Date
{
        friend ostream &operator<<(ostream &,const Date &);
    public:
        Date( int y = 2000, int m = 1, int d = 1);
        ~Date();
        Date(const Date &);
        Date &operator++();
        Date operator++(int);
        Date nextDay();
        Date getDate(Date&);
        void setDate( int , int , int );
        void printWrong() const;
        bool checkDate( int , int , int );
        bool isLeapYear( int );

    protected:

    private:
        int month;
        int day;
        int year;
};

#endif // DATE_H
