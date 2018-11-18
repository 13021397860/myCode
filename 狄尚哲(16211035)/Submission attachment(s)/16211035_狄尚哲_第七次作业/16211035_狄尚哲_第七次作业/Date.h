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
        //����++
        Date& operator ++(); //ǰ��
        Date operator ++(int);//����

        //����+(δ���)
        //Date& operator  +(int d);

        //void print() const;
        //������������������ֻ������Ԫ����
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
