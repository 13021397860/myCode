#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;


class Date
{
    friend class Student;
    friend ostream& operator<<(ostream&, const Date&);
    public:
        Date();
        Date(int ,int ,int);
        Date(const Date &);
        Date& operator++();
        Date operator ++(int);
        void setDate(int y,int m,int d);
        void setYear(int y);
        void setMonth(int m);
        void setDay(int d);
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        bool isLeapYear() const;
        void nextDay();
        bool checkDate();
    protected:

    private:
        int year,month,day;

};



#endif // DATE_H
