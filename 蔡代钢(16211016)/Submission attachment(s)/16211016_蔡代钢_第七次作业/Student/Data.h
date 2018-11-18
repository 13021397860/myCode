#ifndef DATA_H
#define DATA_H
#include "MyException.h"
#include<iostream>
using namespace std;
class Data
{
    public:
        Data(int =1900,int =1,int =1);
        Data(const Data &);
        virtual ~Data();
        void settime(int,int,int);
        int get_year() const {return year;}
        int get_month() const {return month;}
        int get_day() const {return day;}
        bool isLeapYear();
        void SetSystemDate();
        void nextDay();
        friend class Student;
        friend istream& operator>> (istream& is,Data& p){
            is>>p.year>>p.month>>p.day;
            return is;
        }
        friend ostream& operator<<(ostream& os,const Data& p)
        {
            os<<p.year<<"-"<<p.month<<"-"<<p.day;
            return os;
        }
        Data& operator ++ (){
            //前置
            //期望使用方式 ++a
            nextDay();
            return *this;
        }
        Data operator ++ (int){
            //后置
            //期望使用方式 a++
            Data tmp = *this;
            nextDay();
            return tmp;
        }
        Data& operator + (int x){
            for(int i=0;i<x;i++)
                nextDay();
            return *this;
        }
    protected:
    private:
        int year;
        int month;
        int day;
};

#endif // DATA_H
