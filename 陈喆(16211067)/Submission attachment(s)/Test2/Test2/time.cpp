#include "time.h"
#include <iostream>
using namespace std;

time::time(const int y,const int h,const int d)
{
    time::SetTime(y,h,d);//ctor
}
time::time(const time &a)
{
    year = a.year;
    month = a.month;
    day = a.day;
}
time::~time()
{
    //dtor
}
bool time::isLeapYear() const
{
    if(((year%4==0)&&(year%100!=0))||(year%400==0))
        return true;
    else
        return false;
}
bool time::checkTime()
{
    if(year<0||month<0||month>12||day<0||day>31)
    {
        year=1900;
        month=1;
        day=1;
        return false;
    }
    else if(((month==4)||(month==6)||(month==9)||(month==11))&&(day>30))
    {
        day=1;
        return false;
    }
    else if((time::isLeapYear()&&(month==2)&&(day>29))||(!time::isLeapYear()&&(month==2)&&(day>28)))
    {
        day=1;
        return false;
    }
    else
    {
        return true;
    }
}
void time::SetTime(const int y,const int m,const int d)
{
    year = y;
    month = m;
    day = d;
    if(!time::checkTime())
    {
        //cout<<"Error!"<<endl;
        throw(MyException ("Setting time error!"));
    }
}
int time::getDay() const
{
    return day;
}
int time::getMonth() const
{
    return month;
}
int time::getYear() const
{
    return year;
}
void time::print() const
{
    cout<<year<<"."<<month<<"."<<day<<endl;
}
void time::nextDay()
{
    if((month==12)&&(day==31))
    {
        month=1;
        day=1;
        year++;
    }
    else if(((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10))&&(day==31))
    {
        month++;
        day=1;
    }
    else if(((month==4)||(month==6)||(month==9)||(month==11))&&(day==30))
    {
        month++;
        day=1;
    }
    else if((isLeapYear()&&(month==2)&&(day==29))||((!isLeapYear())&&(month==2)&&(day==28)))
    {
        month++;
        day=1;
    }
    else
    {
        day++;
    }
}

ostream& operator <<(ostream& output,time& x)
{
    output<<x.getYear()<<"."<<x.getMonth()<<"."<<x.getDay();
    return output;
}

istream& operator >>(istream& input,time& x)
{
    int Ay,Am,Ad;
    input>>Ay>>Am>>Ad;
    x.SetTime(Ay,Am,Ad);
    return input;
}

time& time::operator++()
{
    this->nextDay();
    return *this;
}

time time::operator++(int)
{
    time tmp(*this);
    ++(*this);
    return tmp;
}

time& time::operator+(int addedDay)
{
    for(int i=0;i<addedDay;i++)
        ++(*this);
    return *this;
}
