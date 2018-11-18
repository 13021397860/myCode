#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
using namespace std;
class date
{
private:
    int year;
    int month;
    int day;
public:
    date(int ,int ,int );
    date();
    date(const date &);
    virtual ~date();
    bool checkDate();
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    bool setDate(const int ,const int ,const int );
    bool setYear(const int );
    bool setMonth(const int );
    bool setDay(const int );
    bool isLeapYear() const;
    void nextDay();
    date &operator++();
    date operator++(int);
    date &operator+(const int);
    friend ostream &operator<<(ostream &,const date &);
    friend istream &operator>>(istream &,date &);
};


#endif // DATE_H_INCLUDED
