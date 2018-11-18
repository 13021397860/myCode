#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
    public:
        Date(int=1,int=1,int=1);
        Date(Date&);
        virtual ~Date();
        void setDate(int,int,int);
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        bool isLeapYear();
        void nextDay();
        friend ostream& operator<<(ostream&,const Date&);
        Date& operator++();
        Date& operator++(int);
    protected:
    private:
        int year;
        int month;
        int day;
        bool judge();
};

#endif // DATE_H

