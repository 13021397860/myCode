#ifndef DATE_H
#define DATE_H
#include <iostream>
using std::ostream;
using std::istream;

class Date
{
    friend ostream& operator<<(ostream &, const Date &);
    friend istream& operator>>(istream& input, Date &d);
    public:
        Date& operator++();
        Date operator++(int);

        //void print() const;

        void nextDay();
        bool isLeapYear() const;

        void setDate(int y, int m, int d);
        int getYear()const {return year;}
        int getMonth()const {return month;}
        int getDay()const {return day;}

        Date(int y, int m, int d);//构造函数
        Date();//缺省构造函数
        Date(const Date &d);  //拷贝构造函数
       ~Date();
    protected:
    private:
        bool checkDate();
        int maxDay() const;

        int year;
        int month;
        int day;
};

#endif // DATE_H
