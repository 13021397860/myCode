#include "Date.h"
#include <iomanip>
using namespace std;


Date::Date(int m,int d,int y)
{
    month=m;
    day=d;
    year=y;
    checkLegal();
}
Date::Date(const Date &D)
{
    month=D.month;
    year=D.year;
    day=D.day;
}
Date::~Date()
{
    //dtor
}

bool Date::isLeapYear()const
{
    if(year%400==0) return true;
    if(year%100==0) return false;
    if(year%4==0) return true;
    return false;
}
void Date::print()const
{
    cout<<*this<<endl;
}
void Date::nextDay()
{
    day++;
    if(!checkLegal())
        month++;
    if(!checkLegal())
        year++;
}
void Date::setDate(int m,int d,int y)
{
    setMonth(m);
    setDay(d);
    setYear(y);
    if(!checkLegal()) throw MyException(DATE_ERROR);
}
Date& Date::operator++()
{
    nextDay();
    return *this;
}
Date Date::operator++(int)
{
    Date temp=*this;
    nextDay();
    return temp;
}
Date& Date::operator+(const int days)
{
    for(int i=1;i<=days;i++)
        nextDay();
    return *this;
}
bool Date::checkLegal()
{
    bool rf=true;
    if(year==0)
    {
        rf=false;year=1;
    }
    if(month<1||month>12)
    {
        rf=false;month=1;
    }
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(day>31)
            {day=1;rf=false;break;}
            else break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(day>30)
            {day=1;rf=false;break;}
            else break;
        case 2:
            if((isLeapYear())&&day>29)
            {day=1;rf=false;break;}
            else if((!isLeapYear())&&day>28)
            {day=1;rf=false;break;}
            else break;
        default:return 0;
    }
    return rf;
}


ostream &operator<<(ostream &output,const Date &d)
{
    output<<d.getYear()<<"-"<<d.getMonth()<<"-"<<d.getDay()<<std::endl;
    return output;
}
istream &operator>>(istream &input,Date &d)
{
    int yy,mm,dd;
    input>>yy;
    input.get();
    input>>mm;
    input.get();
    input>>dd;
    d.setDate(mm,dd,yy);
    return input;
}

