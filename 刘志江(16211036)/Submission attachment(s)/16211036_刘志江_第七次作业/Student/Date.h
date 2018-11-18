#ifndef DATE_H
#define DATE_H
using namespace std;
#include "MyException.h"

class Date
{
    friend ostream& operator<<(ostream&, const Date&);
    public:
        Date(const int =1, const int =1, const int =1);
        Date(const Date &da);
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        void setDate(const int y, const int m, const int d);
        void nextDay();
        bool isLeapYear() const;
        bool checkDate();
        Date& operator++();
        Date operator++(int);
        virtual ~Date();

    protected:

    private:
        int year;
        int month;
        int day;
        int maxDay() const;
};

#endif // DATE_H
