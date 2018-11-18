#include "Date.h"
#include <iostream>
#include "MyException.h"
using namespace std;


Date::Date()
{
    year=month=day=1;
}

Date::Date(const int ye,const int mo,const int da)
{
     //cout<<"hh"<<endl;
    setDate(ye,mo,da);
    //ctor
}

Date Date::operator ++()
{
	nextDay();
	return *this;
}

Date Date::operator ++(int)
{
	Date d(*this);
	nextDay();
	return d;
}

ostream& operator << (ostream& output,const Date& d)
{
   output<<d.year<<"-"<<d.month<<"-"<<d.day<<endl;
   return output;
}

bool Date::isLeapYear()const
{
    bool x;
    if(((year%4==0)&&(year%100!=0))||(year%400==0))
       x=true;
    else
        x=false;
    return x;
}

int Date::getDate1()const
{
    return year;
}

int Date::getDate2()const
{
    return month;
}

int Date::getDate3()const
{
    return day;
}

/*void Date::print() const
{
    cout<<year<<"/"<<month<<"/"<<day<<endl;
}*/

int Date::monthday()const
{
    if(month==4||month==6||month==9||month==11)
        return 30;
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        return 31;
    if(month==2&&(((year%4==0)&&(year%100!=0))||(year%400==0)))
        return 29;
    else
        return 28;
}

void Date::setDate(const int y,const int m,const int d)
{
   year=y;
   month=m;
   day=d;
}

bool Date::checkDate()const
{
    if(year==0||month==0||day==0)
    {
        return false;
    }
    else
        return true;
}

void Date::nextDay()const
{
    int da,mo,ye;
    cout<<"下一天日期是 ";
    if(day<monthday())
    {
        da=day+1;
        mo=month;
        ye=year;
        cout<<ye<<"/"<<mo<<"/"<<da<<endl;
    }
    else
    {
        if(month==12)
        {
            ye=year+1;
            mo=da=1;
            cout<<ye<<"/"<<mo<<"/"<<da<<endl;
        }
        else
        {
            mo=month+1;
            da=1;
            ye=year;
            cout<<ye<<"/"<<mo<<"/"<<da<<endl;
        }
    }
}


Date::~Date()
{
    //dtor
}
