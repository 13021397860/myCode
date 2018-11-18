#include "Data.h"
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int monthday[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
bool isLeapYear(int year)
{
    if(year%400==0||(year%100!=0&&year%4==0))
        return true;
    else
        return false;
}
void isdatalegal(int yy,int mm,int dd)
{
    int a=isLeapYear(yy);
    if((yy>=0&&yy<=9999)&&(mm>=1&&mm<=12)&&dd>=1&&dd<=monthday[a][mm-1])
    {

    }
    else
    {
        throw MyException();
    }
}
Data::Data(int y,int m,int d)
{
    settime(y,m,d);//ctor
}
Data::Data(const Data &t)
{
    year=t.year;
    month=t.month;
    day=t.day;
}
void Data::SetSystemDate()
{
    //取得系统时间
    tm *gm;  //tm是时间结构体
    time_t t=time(NULL);    //time_t是长整型，t表示（总秒数）
    gm=gmtime(&t);
    year=1900+gm->tm_year;
    month=gm->tm_mon+1;
    day=gm->tm_mday;
}
bool Data::isLeapYear()
{
    if(year%400==0||(year%100!=0&&year%4==0))
        return true;
    else
        return false;
}
void Data::settime(int yy,int mm,int dd)
{
    try{
        isdatalegal(yy,mm,dd);
        year=yy; month=mm; day=dd;
    }catch(MyException ex){
        cout<<"#出现异常："<<ex.what1()<<"\n";
        cout<<"#时间输入不合法，自动修改为系统时间\n";
        SetSystemDate();
    }
}
void Data::nextDay()
{
    int a=isLeapYear();
    if(day==monthday[a][month-1])
    {
        day=1;
        month++;
        if(month==13)
        {
            month=1;
            year++;
        }
    }
    else
        day++;
}
Data::~Data()
{
    //cout<<"Data析构函数运行\n";//dtor
}
