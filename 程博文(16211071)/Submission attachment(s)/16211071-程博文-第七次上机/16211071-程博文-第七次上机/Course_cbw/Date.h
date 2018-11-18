#include<iostream>
using namespace std;
#ifndef DATE_H
#define DATE_H
#include "Date.h"
#include "MyException.h"
class Date
{
public:
    Date(const int year=1970,const int month=1,const int day=1);
    Date(const Date &t);
    virtual ~Date();
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    /*bool setYear(const int y);
    bool setMonth(const int m);
    bool setDay(const int d);*/
    bool setDate(const int y,const int m,const int d);
    bool isLeapYear() const;
    void nextDay();
    //void print() const;
    friend ostream & operator <<(ostream &os,const Date& d);
    Date& operator++();//Ç°ÖÃ++
    Date operator++(int);//ºóÖÃ++

protected:

private:
    int year;
    int month;
    int day;
    bool testValid() const;
};

#endif // DATE_H
