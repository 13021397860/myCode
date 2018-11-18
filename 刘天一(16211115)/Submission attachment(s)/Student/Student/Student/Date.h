#ifndef STUDENT_DATE_H
#define STUDENT_DATE_H


#include<iostream>
#include "../Exception/MyException.h"
using namespace std;

class Date
{
    friend ostream & operator<<(ostream &,const Date &);
    friend istream & operator>>(istream &,Date &);
public:
    Date(int=1,int=1,int=2000);
    Date(const Date & );
    virtual ~Date();
    void print()const;
    void setDate(int m,int d,int y);
    void setDay(int d){day=d;}
    void setMonth(int m){month=m;}
    void setYear(int y){year=y;}
    Date &operator++();//pre
    Date operator++(int);//post
    Date &operator+(const int days);
    int getYear()const{return year;}
    int getMonth()const{return month;}
    int getDay()const{return day;}
    bool isLeapYear()const;
    void nextDay();


protected:

private:
    int year;
    int month;
    int day;
    bool checkLegal();
};


#endif //STUDENT_DATE_H
