#ifndef DATE_H
#define DATE_H
#include <iostream>
#include "Exception.h"
using namespace std;
class Date
{
    friend ostream& operator <<(ostream& ,const Date&);
    public:
        Date(int =1,int =1,int =1);
        Date(const Date &);
        virtual ~Date();

        void setDate(int y,int m,int d);
        void setDate(const Date &);
        int  getYear()const;
        int getMonth()const;
        int getDay()const;

        bool isLeapYear()const;
        int maxday() const;
        void nextDay();

        Date& operator ++();//front
        Date operator++(int);//later

    protected:

    private:
        bool dateCheck();
        int year;
        int month;
        int day;
};

#endif // DATE_H
