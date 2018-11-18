#include "date.h"
#include<iostream>
using namespace std;
Date::Date()
{
   year=month=day=0; //ctor
}


Date::Date(int y,int m,int d)
{
    setDate(y,m,d);
}


Date::Date(Date& date)
{
    setDate(date.year,date.month,date.day);
}



Date::~Date()
{
    //dtor
}

void Date::setDate(int y,int m,int d)
{
    year=(y>=1&&y<=2017)?y:0;
    month=(m>=1&&m<=12)?m:0;
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        day=(d>=1&&d<=31)?d:0;
    else if(m==4||m==6||m==9||m==11)
        day=(d>=1&&d<=30)?d:0;
    else if(isLeapYear(y))
        day=(d>=1&&d<=29)?d:0;
    else day=(d>=1&&d<=28)?d:0;
}


bool Date::isLeapYear(int y){if(y%400==0||(y%100!=0&&y%4==0))return true;else return false;}



void Date::nextDay(){
    if(month==12&&day==31)
    {
        year++;month=1;day=1;
    }
    else if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day==30)
    {
        month++;day=1;
    }
    else if(month==2&&(isLeapYear(year))&&day==29)
    {
        month++;day=1;
    }
    else if(month==2&&day==28)
    {
        month++;day=1;
    }
    else day++;
}



//void Date::print()
//{
  //  cout<<year<<"-"<<month<<"-"<<day<<endl;
//}

int Date::getDateYear()
{
    return year;
}

int Date::getDateMonth()
{
    return month;
}


int Date::getDateDay()
{
    return day;
}

Date Date::operator << (Date &d)
{
    cout<<year<<"-"<<month<<"-"<<day<<endl;
}


Date& Date::operator ++ (){
            nextDay();
            return *this;
        }

Date Date::operator ++ (int){
            //后置
            //期望使用方式 a++
            Date tmp = *this;
            ++(*this);
            return tmp;
        }





