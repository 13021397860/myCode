#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;


class Date
{
        friend ostream &operator<<( ostream &, const Date& );
        friend istream &operator>>( istream &, Date & );
        friend Date &operator+( int, Date & );

    public:

        Date operator++();
        Date operator++(int);
        Date &operator+(int);

        Date( int = 2000, int = 1, int = 1 );
        Date( const Date& );
        ~Date();

        void setDate( int, int, int );

        int getYear() const;
        int getMonth() const;
        int getDay() const;

        bool isLeapYear() const;

        void nextDay();

        void checkLegal();
        bool judgeDate();

    protected:

    private:
        int year;
        int month;
        int day;
};

#endif // DATE_H
