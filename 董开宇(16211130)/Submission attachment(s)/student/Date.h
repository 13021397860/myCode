#ifndef DATE_H
#define DATE_H

#include<iostream>
using namespace std;

class Date
{
    friend ostream& operator<<(ostream &, const Date &);
public:
    Date& operator++();
    Date operator++(int);
    Date(int=1,int=1,int=1900);
    Date(const Date &);

    void setMonth(int);
    void setDay(int);
    void setYear(int);

    int getMonth()const;
    int getDay()const;
    int getYear()const;

    bool isLeapYear()const;
    void nextDay();
    void print()const;

    bool isLeagal()const;
protected:

private:
    int year,month,day;
    int monthDays();
};

#endif // DATE_H
