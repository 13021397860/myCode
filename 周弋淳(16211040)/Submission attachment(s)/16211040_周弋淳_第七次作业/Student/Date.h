#ifndef DATE_H
#define DATE_H

#include<iostream>

using namespace std;

class Date
{
    friend ostream& operator<<(ostream&, const Date&);
    public:
        Date(const int=1,const int=1,const int=1);
        Date(const Date&);
        virtual ~Date();
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        void setDate(const int y, const int m, const int d);
        bool isLeapYear() const;
        void nextDay();
        //void print() const;
        bool checkDate();
        int maxDay() const;
        Date& operator++();
        Date operator++(int);

    protected:

    private:
        int year;
        int month;
        int day;
};

#endif // DATE_H
