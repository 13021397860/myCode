#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;

class Date
{
    public:
        Date();
        Date(const Date&);
        virtual ~Date();
        bool isLeapyear();
        bool IsLegalDate();
        void nextDay();
        void SetDate(int,int,int);
        int GetYear()const;
        int GetMonth()const;
        int GetDay()const;
        void PrintDate()const;
        void PrintIsLeapeyear();
        friend ostream& operator<<(ostream& cout,const Date& dd);
        Date& operator++();
        const Date operator++(int);

    protected:

    private:
        int year;
        int month;
        int day;

};


#endif // DATE_H

