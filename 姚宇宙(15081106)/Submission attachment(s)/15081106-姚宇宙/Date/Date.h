#ifndef DATE_H
#define DATE_H

#include<iostream>
#include "MyException.h"

class Date
{
    public:
        Date();
        Date(int, int, int);
        Date(const Date&);
        virtual ~Date();
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        void setDate(int, int, int);
        void setYear(int);
        void setMonth(int);
        void setDay(int);
        bool isLeapYear() const;
        void nextDay();
        //void print() const;
        Date& operator ++ ();
        Date operator ++ (int);
        friend std::ostream& operator << (std::ostream&, const Date&);
        friend std::istream& operator >> (std::istream&, Date&);
        Date operator + (int);
        //Date operator + (int);
    protected:

    private:
        int year;
        int month;
        int day;
        int maxDay() const;
        bool checkDate();
};

#endif // DATE_H
