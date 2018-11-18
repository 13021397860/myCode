#include "Date.h"
#include"Myexception.h"
#include<iostream>
using namespace std;

Date::Date()
{

}
Date::Date(const int &Y=1900,const int &M=1,const int &D=1)
{
    //ctor
    setdate(Y,M,D);
}

Date::Date(const Date &t)
{
    year=t.year;
    month=t.month;
    day=t.day;
}

Date::~Date()
{
    //dtor
    cout<<"The Date's object is destroyed"<<endl;
}

void Date::setdate(const int &y,const int &m,const int &d)
{
    year=y;
    month=m;
    day=d;
    if(checkdate()==0)
        throw Myexception();
    //checkdate();
}

bool Date::isleapyear()const
{
    if((year%4==0&&year%100!=0)||(year%400==0))
        return true;
    else
        return false;
}

bool Date::checkdate()
{
    if(month<1||month>12)
    {
        month=1;
        return false;
    }
    else
    {
        switch(month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            {
                if(day<1||day>31)
                    {
                        day=1;
                        return false;

                    }
                break;
            };

            case 4:
            case 6:
            case 9:
            case 11:
            {
                if(day<1||day>30)
                    {
                        day=1;
                        return false;

                    }
                break;
            };

            case 2:
                {
                    if(isleapyear()==1)
                    {
                        if(day<1||day>29)
                        {
                            day=1;
                            return false;

                        }
                    }
                    else
                    {
                        if(day<1||day>28)
                        {
                            day=1;
                            return false;

                        }
                    }
                break;
                }
        }
    }


    return true;
}

void Date::nextday()
{
    day++;
    if(checkdate()==false)
    {
        month++;
        if(checkdate()==false)
        {
            year++;
        }
    }
}

Date& Date::operator++()
{
    nextday();
    return *this;//++a
}
Date Date::operator++(int)
{
    Date d(*this);
    nextday();
    return d;//a++
}
ostream& operator<<(ostream& output,const Date &x)
{
    output<<x.year<<"-"<<x.month<<"-"<<x.day;
    return output;
}
