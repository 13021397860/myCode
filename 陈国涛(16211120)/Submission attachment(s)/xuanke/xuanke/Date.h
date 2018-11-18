#ifndef DATE_H
#define DATE_H
#include <iostream>
#include "MyException.h"
using namespace std;

class Date
{
    friend ostream &operator<<( ostream &, const Date &);
public:
    Date(int m=1, int d=1, int y=1990);
    Date();
    Date(const Date &);

     const void setDate(int m, int d,int y) throw(MyException);
    Date &operator++();//++date
    Date operator++( int );//date++
    const Date &operator+=( int );
    int getYear()const;
    int getMonth()const;
    int getDay()const;
    const int monthDays( int m);//返回当月的天数;
    void nextday();
    const bool isLeapYear() ;
    virtual ~Date();
protected:
private:
    int year;
    int month;
    int day;

};

#endif // DATE_H
