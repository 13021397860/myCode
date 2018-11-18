#include "Date.h"
#include<iostream>
using namespace std;


Date::~Date()
{
    //dtor
}
bool Date::isLeapYear( )
{
    if ( (year%4==0 && year%100!=0) || (year%400==0 ) )
        return 1;

    else return 0;
}
void Date::setDate(int y, int m, int d)
{

    year=y;
    month =m;
    day =d;
    if ( !ch())
    {
        check=0;
        cout<<"wrong\n please enter the correct data "<<endl;
    }
}
/*void  Date::setyear( int y)
{

        year=y;
}
void Date::setmonth( int m)
{
    if ( m>=1 && m<=12 )
        month=m;
    if ( m==13 && check==1 )
        month=1;

}
void Date::setday( int d)
{

      day=d;
     if ( getmonth()==2 && isLeapYear(getyear())==1 && d==30 && check==1)
        day=1;
    else if ( getmonth()==2 && isLeapYear(getyear())==0 && d==29&& check==1)
        day=1;
    else if ( (getmonth()==1 || getmonth()==3 || getmonth()==5|| getmonth()==7 || getmonth()==8 || getmonth()==10 ||getmonth()==12 )&& d==32&& check==1)
        day=1;
    else if ( (getmonth()==4 || getmonth()==6 || getmonth()==9 || getmonth()==11) && d>=1 &&d==31&& check==1)
        day=1;
}*/
void Date::nextDay()
{
    if ( check )
    {

        day++;

        if ( !ch() )
        {
            day=1;
            month++;
            if ( !ch() )
            {
                month=1;
                year++;

            }
        }
    }

}
/*void Date::print() const
{
    if ( check )
    {

        cout<<year<<"."<<month<<"."<<day<<"."<<endl;


    }

}*/
int Date::maxmonth()
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
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if ( isLeapYear())


            return 29;
        else return 28;

    default :
        return 0;
    }
}

ostream &operator<<( ostream &output, const Date& A)
{

    output<<A.getyear()<<"-"<<A.getmonth()<<"-"<< A.getday()
    ;
    return output;
}
Date Date::operator++(int )
{
    Date before =*this;
    this ->nextDay();
    return before;
}

Date& Date::operator++()
{
    this ->nextDay();
    return (*this);
}
bool Date::ch()
{
    /*if ( getyear()<0)
        return 0;
    else if ( getmonth()<=0 || getmonth()>=13)
        return 0;
    else if ( getday()<=0 || getday()>=32 )
        return 0;
    else if ( getmonth()==2 && isLeapYear(getyear())==1 && getday()>=30 )
        return 0;
    else if ( getmonth()==2 && isLeapYear(getyear())==0 && getday()>=29)
       return 0;

    else if ( (getmonth()==4 || getmonth()==6 || getmonth()==9 || getmonth()==11)  &&getday()>=31)
       return 0;

    else return 1;*/
    if  ( month<=0 || month>=13 || day<=0 || day>maxmonth() || year<0 )
        return 0;
    else return 1;

}









