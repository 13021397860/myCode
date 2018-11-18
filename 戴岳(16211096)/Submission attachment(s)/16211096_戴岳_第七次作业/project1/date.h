#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;

class Date
{
    public:
        Date();
        virtual ~Date();
        Date(int ,int ,int);
        Date(const Date&);

        void setTime(int,int,int);
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        bool isLeapYear(int) const;
        int daysOfMonth(int ,int ) const;
        void nextDay();
        void print() const;

        friend ostream& operator<<(ostream&, const Date&);

        Date& operator++();
        Date operator++(int);

    protected:

    private:
        int year;
        int month;
        int day;
};

#endif // DATE_H
