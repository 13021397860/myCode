#ifndef DATE_H
#define DATE_H
#include<iostream>
#include"MyException.h"
using namespace std;


class Date
{
    public:
        Date(int y,int m,int d);
        Date();//缺省构造函数
        Date(const Date &);//拷贝构造函数
        virtual ~Date();

        friend ostream &operator<<(ostream &,const Date &);
        Date &operator++();//前置
        Date operator++(int);//后置


        int DateGetDay();
		int DateGetMonth();
		int DateGetYear();
        void DateSet( int y , int m , int d);
        bool isLeapYear();
        void nextDay();
        void print() const;
        void checkDate();

    protected:

    private:
        int year;
        int month;
        int day;
};

#endif // DATE_H
