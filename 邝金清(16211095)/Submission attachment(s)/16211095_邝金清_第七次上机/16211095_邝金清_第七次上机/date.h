#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "my_exception.h"
class date
{
    friend std::ostream& operator<< (std::ostream& out, const date& A);
    friend std::istream& operator>> (std::istream& in, date& A);
private:
    int year;
    int month;
    int day;
    bool isLegal(int _year, int _month, int _day);

public:
    date(int _year = 0, int _month = 1, int _day = 1);
    date(const date & anonther_date);
    bool isLeapYear() const   {return (!(year % 4) && (year % 100)) || !(year % 400);}
    int getYear() const       {return year;}
    int getMonth() const      {return month;}
    int getDay() const        {return day;}
    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    void nextDay();
    date& operator++ () {this->nextDay(); return *this;}
    date& operator++ (int)  {date old(*this); this->nextDay(); return old;}
    friend date operator+ (date& A, int i);
    //void print() const;
};
#endif // DATE_H
