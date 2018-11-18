#ifndef DATE_H
#define DATE_H
#include<iostream>
#include "MyException.h"
using namespace std;

class Date
{
    public:
        Date(int = 1900 , int = 1, int = 1);
        virtual ~Date();
        Date(const Date &d);
        void setDate(int , int , int );
        int getMonth() const {return month;}
        int getDay() const {return day;}
        int getYear() const {return year;}
        bool isLeapYear();
        //void nextDay();
        friend ostream& operator<<(ostream& ,const Date& );
        Date& operator ++ ();//ǰ ++
        //void print() const;
        void checkDate();
        int maxDay();
    protected:

    private:
        int year;
        int month;
        int day;
};

#endif // DATE_H
