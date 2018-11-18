#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;

class Date
{
    public:
        Date();
        Date(const int &,const int &,const int &);
        Date(const Date &);//?/const
        virtual ~Date();
        int getyear()const{return year;};
        int getmonth()const{return month;};
        int getday()const{return day;};
        void setdate(const int &,const int &,const int &);
        bool isleapyear()const;
        void nextday();
        void print()const;
        Date& operator++();
        Date operator++(int);
        friend ostream& operator<<(ostream& ,const Date &);

    protected:

    private:
        int year;
        int month;
        int day;
        bool checkdate();
};

#endif // DATE_H
