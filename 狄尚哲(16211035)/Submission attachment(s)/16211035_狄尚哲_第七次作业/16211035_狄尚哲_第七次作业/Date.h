#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<iomanip>
#include<cstdio>
using namespace std;

class Date
{
    public:
        Date(const int = 1900, const int = 1, const int = 1);
        Date(const Date &);
        virtual ~Date();
        int getYear() const;
        int getMonth() const;
        int getDay() const;
        bool setDate(int, int, int);
        bool isLeapYear();

        //void nextDay();
        //重载++
        Date& operator ++(); //前置
        Date operator ++(int);//后置

        //重载+(未完成)
        //Date& operator  +(int d);

        //void print() const;
        //重载输入输出运算符，只能用友元函数
        friend ostream &operator<<(ostream &,const Date &);
        friend istream &operator>>(istream &,Date &);

    protected:

    private:
        bool isValid();
        int month;
        int day;
        int year;
};

#endif // DATE_H
