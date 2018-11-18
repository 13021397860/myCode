#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include<iostream>
using namespace std;
class Date
{
    friend ostream &operator<<(ostream &,const Date&);
public:

    Date(int =0,int =0,int =0);

    Date(const Date &);
    virtual ~Date();
    void setDate(int,int,int);
    int getYear() const;
    int getMonth() const ;
    int getDay() const ;
    bool isLeapYear() const ;
    void nextDay();
    int mxDay();

    //Date operator++(Date &);
    Date& operator++();//qian
    Date operator++(int);
private:
    int year;
    int month;
    int day;
};

#endif // DATE_H_INCLUDED
