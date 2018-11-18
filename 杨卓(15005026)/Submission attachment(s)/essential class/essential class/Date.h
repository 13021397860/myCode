#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
    public:
        Date(int=1949,int=1,int=1);
        Date(const Date &);
        virtual ~Date();
        void printUniversal();
        void printStandard();
        void setDate(int,int,int);
        int getYear(){return year;}
        int getMonth(){return month;}
        int getDay(){return day;}
        void cheakDate();
        bool isLeepYear();
        void print();
        void nextDay();
        friend ostream& operator << (ostream &,const Date &);
        Date& operator ++ ();
        Date operator ++(int);
    protected:
    private:
        int year;
        int month;
        int day;
        int monkey[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};

};

#endif // DATE_H
