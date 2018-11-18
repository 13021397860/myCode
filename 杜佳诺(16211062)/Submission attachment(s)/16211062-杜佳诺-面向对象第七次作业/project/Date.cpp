#include "Date.h"
#include "myexception.h"
#include <iostream>
#include <iomanip>
using namespace std;

Date::Date( int y, int m, int d )
{
    setDate( y, m, d );
}

Date::Date( const Date &da )
{
    year = da.year;
    month = da.month;
    day = da.day;
}

Date::~Date()
{
    //cout<<"Object destructor runs.\n";
}

void Date::checkLegal()
{
    if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day==32){day=1;month++;}
    if((month==4||month==6||month==9||month==11)&&day==31){day=1;month++;}
    if((month==2&&((year%4==0&&year%100!=0)||year%400==0)&&day==30)){day=1;month++;}
    if(month==2&&(year%4!=0||(year%100==0&&year%400!=0))&&day==29){day=1;month++;}
    if(month==13){month=1;year++;}
}

bool Date::judgeDate()
{
    if( year<=0 || month<1 || month>12 || (((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&day>31))|| ((month==4||month==6||month==9||month==11)&&day>30) || ((year%4!=0||(year%100==0&&year%400!=0))&&day>28) || (((year%4==0&&year%100!=0)||year%400==0)&&day>29))
    {
        //cout<<"Wrong Date!\n\n";
        setDate(2000,1,1);
        return false;
    }
    return true;
}

void Date::setDate( int y, int m, int d )
{
    if(!MyException::DateException(y,m,d))
    {
        setDate(2000,1,1);
        return;
    }
    year = y;
    month = m;
    day = d;
}

int Date::getYear() const
{
    return year;
}

int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

bool Date::isLeapYear() const
{
    if ( year%4!=0 || (year%100==0&&year%400!=0) )return false;
    else return true;
}

void Date::nextDay()
{
    day++;
    checkLegal();
}

Date Date::operator++()
{
    this->nextDay();
    return *this;
}

Date Date::operator++(int)
{
    Date tmp(*this);
    this->nextDay();
    return tmp;
}

Date &Date::operator+( int x )
{
    for(int i=1;i<=x;i++)
        this->nextDay();
    return *this;
}

Date &operator+( int x, Date &da )
{
    return da+x;
}

ostream &operator<<( ostream &output, const Date &da )
{
    output<<da.year<<"-"<<da.month<<"-"<<da.day;
    return output;
}

istream &operator>>( istream &input, Date &da )
{
    string str1="Wrong year\n";
    string str2="Wrong month\n";
    string str3="Wrong day\n";
    int y,m,d;
    input>>y;
    if(input.fail()){cout<<str1;y=2000;input.clear();input.ignore();}
    input.ignore();
    input>>m;
    if(input.fail()){cout<<str2;m=1;input.clear();input.ignore();}
    input.ignore();
    input>>d;
    if(input.fail()){cout<<str3;d=1;input.clear();input.ignore();}
    input.ignore();
    da.setDate(y,m,d);
    return input;
}
