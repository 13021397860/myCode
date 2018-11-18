#ifndef DATE_H
#define DATE_H
#include<iostream>
using std::istream;
using std::ostream;
class Date
{
public:
    Date();
    Date(const int TempYear,const int TempMonth,const int TempDay);
    Date(const Date &Anoter);
    int GetYear()const;
    int GetMonth()const;
    int GetDay()const;

    bool SetYear(const int TempYear);
    bool SetMonth(const int TempMonth);
    bool SetDay(const int TempDay);

    bool IsLeapYear()const;

    void NextDay();
    Date& operator++();
    Date operator++(int);
    //void Print()const;
    friend istream& operator>>(istream &input, Date& date);
    friend ostream& operator<<(ostream &output, const Date& date);

    ~Date();
private:
    int Year;
    int Month;
    int Day;
};

#endif // DATE_H
