#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
using std::ostream;
class Date
{
    friend ostream& operator<<(ostream& ,const Date&);
    public:
        Date(const int, const int, const int);
        Date(const Date &a);
        virtual ~Date(){}

        int getYear()const;
        int getMonth()const;
        int getDay()const;
        bool checkDate(int, int, int);

        void setDate(int, int, int);
        bool isLeapYear(const int);
        void nextDay();
        void printDate()const;

    protected:
    private:
        int Year;
        int Month;
        int Day;

//F:\2017project\student\date.h|28|error: 'std::ostream& Date::operator<<(std::ostream&, const Date&)' must take exactly one argument|
};

#endif // DATE_H
