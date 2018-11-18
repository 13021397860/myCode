#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;
class Date
{
    public:
        friend class student;
        Date(int=1,int=1,int=1);
        Date(const Date& x);
        ~Date();
        int getYear()const;
        int getMonth()const;
        int getDay()const;
        void setYear(const int &y);
        void setMonth(const int &m);
        void setDay(const int &d);
        void set(const int &y,const int &m,const int &d);
        bool isLeapYear();
        void nextDay();
        friend ostream & operator<<(ostream &out,Date x)
        {
            out<<x.year<<"-"<<x.month<<"-"<<x.day;
            return out;
        }
        Date& operator++();
        Date& operator++(int);
        Date& operator+(int x);
        friend istream& operator>>(istream &in,Date &x)
        {
            in>>x.year>>x.month>>x.day;
            return in;
        }
    protected:

    private:
        int year,month,day;
        bool check();
};

#endif // DATE_H
