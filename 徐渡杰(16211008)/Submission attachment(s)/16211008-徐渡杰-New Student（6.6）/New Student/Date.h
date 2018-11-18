#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<iomanip>
using namespace std;

class Date
{
    public:
        Date(int = 0,int = 1,int = 1);
        Date(const Date &date);
        virtual ~Date();
        void setDate(int y,int m,int d);
        int getDate_y()const;
        int getDate_m()const;
        int getDate_d()const;
        void isStandard();
        void nextDay();
        //void print()const;
        bool isLeapYear()
        {
            if((year%400==0)||(year%4==0&&year%100!=0))
                return true;
            return false;
        }
        Date &operator++();//Ç°++
        Date operator++(int);//ºó++
        friend ostream&operator<<(ostream &out,const Date &date)
        {
            return out<<setw(4)<<setfill('0')<<date.year<<"-"<<setw(2)<<setfill('0')<<date.month<<"-"<<setw(2)<<setfill('0')<<date.day<<endl;
        }
    protected:

    private:
        int year;
        int month;
        int day;
};

#endif // DATE_H
