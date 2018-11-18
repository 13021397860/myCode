#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "Exception.h"

class Date
{
    public:
        Date();
        Date(const int&, const int&, const int&);
        Date(const Date&);
        virtual ~Date();

        Date operator +(const int&);
        Date operator -(const int&);
        Date& operator +=(const int&);
        Date& operator -=(const int&);
        Date& operator ++();
        const Date operator ++(int);

        bool operator ==(const Date&);
        bool operator !=(const Date&);
        bool operator >(const Date&);
        bool operator <(const Date&);
        bool operator >=(const Date&);
        bool operator <=(const Date&);

        friend std::istream& operator >>(std::istream&, Date&);
        friend std::ostream& operator <<(std::ostream&, const Date&);

        void setDate(const int&, const int&, const int&); //throw(Illegal_Date_Exception);
        void setDate(const Date&);
        void setYear(const int&); //throw(Illegal_Date_Exception);
        void setMonth(const int&); //throw(Illegal_Date_Exception);
        void setDay(const int&); //throw(Illegal_Date_Exception);

        int getYear() const;
        int getMonth() const;
        int getDay() const;

        bool isLeapYear();
        void nextDay(const int& = 1);
        void lastDay(const int& = 1);

    private:
        int year;
        int month;
        int day;

        bool isLegal();
};

#endif // DATE_H
