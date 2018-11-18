#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;
class Date
{
    friend ostream& operator<<(ostream &, const Date &);
    friend istream& operator>>(istream &, const Date &);
    public:
    	Date(int = 1900, int = 1, int = 1);
        void setDate( int , int , int );
        bool isLeapYear()const;
		void nextDay();
        const int getYear()const;
        const int getMonth()const;
        const int getDay()const;
        ~Date();
		Date(const Date &);
		Date& operator++();
		Date& operator++(int);

    private:
        int month;
        int day;
        int year;
        bool checkLegal();
};

#endif // DATE_H
