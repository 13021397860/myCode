#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>
using namespace std;

class Date
{
    public:
        Date();
        Date(const int,const int,const int);
        Date(const Date& d)
        {
            year=d.year;
            month=d.month;
            day=d.day;
        }
        Date operator ++();
        Date operator ++(int);
        friend ostream& operator << (ostream&,const Date&);
        bool checkDate()const;
        virtual ~Date();
        int getDate1()const;
        int getDate2()const;
        int getDate3()const;
        void setDate(const int ,const int ,const int);
        bool isLeapYear( )const;
        void nextDay()const;
        //void print() const;
        int monthday()const;
    protected:
    private:
        int year;
        int month;
        int day;
};

#endif // DATE_H
