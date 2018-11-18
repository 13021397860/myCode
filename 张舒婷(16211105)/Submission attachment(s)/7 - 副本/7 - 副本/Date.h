#ifndef DATE_H
#define DATE_H
#include <iostream>
using std::ostream;

class Date
{
    friend ostream& operator<<(ostream &,const Date &);
    public:
        Date();
        Date(int y,int m,int d);
        virtual ~Date();
        Date(Date const &d);

        bool isLeapYear() const;
        void nextDay();
        void print() const;
        void setDate(int y,int m,int d);
        int getyear()const{return year;}
        int getmonth()const{return month;}
        int getday()const{return day;}
        Date& operator++();
        Date operator++(int);

    protected:

    private:
        int year;
        int month;
        int day;
        bool checkdate();
        int maxday() const;
};

#endif // DATE_H
