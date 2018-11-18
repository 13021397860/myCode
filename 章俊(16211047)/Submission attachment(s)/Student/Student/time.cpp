#include "time.h"
#include <iostream>
#include "myexception.h"
using namespace std;
using std::ostream;
using std::istream;
Time::Time()
{
   setTime(1,1,1);
}
Time::Time(const int year,const int month,const int day)
{
   setTime(year, month,day);
}
Time::Time(const Time &t)
{
   year=t.year;
   month=t.month;
   day=t.day;
}
Time::~Time()
{
    //dtor
}
void Time::setTime(const int y,const int m,const int d)
{
    if(check(y,m,d)==0)
    {
        throw MyException(DATE_INVALID);
    }
    setyear(y);
    setmonth(m);
    setday(d);
}
int Time::check(const int y,const int m,const int d)const
{
    int flag=1;
    if(m>=13||m<=0)
    {
        flag=0;
    }
    else if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
    {
        if(d>=32||d<=0)
        {
            flag=0;
        }
    }
    else if(m==2)
    {
        if((y%4==0&&y%100!=0)||y%400==0)
        {
            if(d>=30||d<=0)
            {
                flag=0;
            }
        }
        else{
            if(d>=29||d<=0)
            {
                flag=0;
            }
        }
    }
//cout<<"flag"<<flag<<endl;
    if(flag==0)
    {
//cout<<"flag22"<<flag<<endl;
        return 0;
    }
    else{
        return 1;
    }
}
void Time::setyear(const int y)
{
    year=y;
}
void Time::setmonth(const int m)
{
   month=m;
}
void Time::setday(const int d)
{
   day=d;
}
int Time::getyear()const
{
    return year;
}
int Time::getmonth()const
{
    return month;
}
int Time::getday()const
{
    return day;
}
bool Time::isLeapyear()const
{
    int y=getyear();
    if((y%4==0&&y%100!=0)||y%400==0)
    {
        return true;
    }
    else
    return false;
}
void Time::nexDay()
{
    if(day<=27)
    {
       day++;
    }
    //这里不能输出；
    else if(month==2)
    {
        if(isLeapyear()==1&&day==28)
        {
            day++;
        }
        else if(isLeapyear()==1&&day==29)
        {
            month=3;
            day=1;
        }
    }
    else if(month==1||month==3||month==5||month==7||month==8||month==10)
    {
        if(day==31)
        {
            day=1;
            month++;
        }
        else
        {
            day++;
        }
    }
    else if(month==4||month==6||month==9||month==11)
    {
        if(day==30)
        {
            day=1;
            month++;
        }
        else
        {
            day++;
        }
    }
    else if(month==12)
    {
        if(month==31)
        {
            day=1;
            month=1;
            year++;
        }
        else{
            day++;
        }
    }
}


ostream& operator << (ostream& output,Time &t)
{
    output<<t.getyear()<<"-"<<t.getmonth()<<"-"<<t.getday();
    return output;
}
istream& operator >> (istream& input,Time &t)
{
    cout<<"输入年"<<endl;
    input>>t.year;
    cout<<"输入月"<<endl;
    input>>t.month;
    cout<<"输入日"<<endl;
    input>>t.day;
    return input;
}
Time& Time::operator ++ ()
{
    nexDay();
    return *this;
}
Time& Time::operator ++ (int)
{
    Time t(*this);
    nexDay();
    return t;
}
