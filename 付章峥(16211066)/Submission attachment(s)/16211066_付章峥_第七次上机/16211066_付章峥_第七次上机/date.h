#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;

//class Date definition
class Date
{
    public:
        Date(const int = 1,const int = 1,const int = 2000);//default constructor
        Date(Date&);
        void setDate(const int = 1,const int = 1,const int = 2000);
        int getYear();
        int getMonth();
        int getDay();
        int maxDay();
        friend ostream &operator<<(ostream &,const Date &);
        friend istream &operator>>(istream &,const Date &);
        Date& operator++();
        Date operator++(int);
        Date operator+(int);
        bool isLeapYear();
        void nextDay();
        ~Date();

    protected:

    private:
        int year;
        int month;
        int day;
        void checkDate();
};//end class Date

#endif // DATE_H
