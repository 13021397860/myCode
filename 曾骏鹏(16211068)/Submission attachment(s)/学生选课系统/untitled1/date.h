//
// Created by zjp on 2017/4/17.
//
#include <iostream>
#ifndef DATE_H
#define DATE_H
using namespace std;
class date
{
public:
    date() {
        year=month=day=1;
    };
    date(const int,const int,const int);
    date(const date &);
    ~date();
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    void setYear(const int);
    void setMonth(const int);
    void setDay(const int);
    void setDate(const int,const int,const int);
    void nextDay();
    //void printDate() const;
    friend ostream& operator << (ostream &os,const date &t);
    friend istream& operator >> (istream &is,date &t);
    date& operator ++();
    date& operator ++(int);
    bool check() const;
    bool isLeapYear() const;
private:
    int year;
    int month;
    int day;
};


#endif //DATE_H
