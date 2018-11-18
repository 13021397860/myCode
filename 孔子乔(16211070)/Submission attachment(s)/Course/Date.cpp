#include "Date.h"
#include<iostream>
#include<cmath>
using std::istream;
using std::ostream;
using std::abs;
#define ThirtyOne Month==1||Month==3||Month==5||Month==7||Month==8||Month==10||Month==12
#define Thirty Month==4||Month==6||Month==9||Month==11
#define Twenty Month==2

Date::Date()
{
    Year = 1980;
    Month = 1;
    Day = 1;
}

Date::Date(const int TempYear, const int TempMonth,const int TempDay)
{
    if(!(Date::SetYear(TempYear)&&Date::SetMonth(TempMonth)&&Date::SetDay(TempDay)))
    {
        Year = 1980;
        Month = 1;
        Day = 1;
    }
}

Date::Date(const Date &Another)
{
    Year = Another.Year;
    Month = Another.Month;
    Day = Another.Day;
}

//  function needs a "const" in the end if it is called by a const obj.
int Date::GetDay()const{return Day;}
int Date::GetMonth()const{return Month;}
int Date::GetYear()const{return Year;}

bool Date::SetDay(const int TempDay)
{
    if(ThirtyOne)
    {
        if(TempDay>31||TempDay<0)
        {
            Day=1;
            return false;
        }
    }
    else if(Thirty)
    {
        if(TempDay>30||TempDay<0)
        {
            Day=1;
            return false;
        }
    }
    else if(Twenty)
    {
        if(Date::IsLeapYear())
        {
            if(TempDay>29||TempDay<0)
            {
                Day=1;
                return false;
            }
        }
        else
        {
            if(TempDay>28||TempDay<0)
            {
                Day=1;
                return false;
            }
        }
    }
    else
    {
        Day=1;
        return false;
    }
    Day = TempDay;
    return true;
}

bool Date::SetMonth(const int TempMonth)
{
    if(TempMonth<0||TempMonth>12)
    {
        Month=1;
        return false;
    }
    else
    {
        Month=TempMonth;
        return true;
    }
}
bool Date::SetYear(const int TempYear){Year=TempYear;return true;}

bool Date::IsLeapYear()const
{
    if(Year%4!=0)return false;
    else
    {
        if(Year%100!=0)return true;
        else
        {
            if(Year%400==0)return true;
            else return false;
        }
    }
}


/*void Date::Print()const
{
    if(Year<0)
    {
        int TempYear=abs(Year);
        printf("%dB.C./%d/%d\n",TempYear,Month,Day);
    }
    else printf("%d/%d/%d\n",Year,Month,Day);
}*/

istream& operator>>(istream &input, Date& date)
{
    int year,month,day;
    input>>year>>month>>day;
    date.SetDay(day);
    date.SetMonth(month);
    date.SetYear(year);
    return input;
}

ostream& operator<<(ostream &output,const Date& date)
{
    output<<date.Year<<"-"<<date.Month<<"-"<<date.Day;
    return output;
}

void Date::NextDay()
{
    if(ThirtyOne)
    {
        if(Day<=30&&Day>=1)Day++;
        else if(Day==31)
        {
            if(Month<=11&&Month>=1)
            {
                Month++;
                Day=1;
            }
            else if(Month==12)
            {
                Year++;
                Month=1;
                Day=1;
            }
        }
    }
    else if(Thirty)
    {
        if(Day<=29&&Day>=1)Day++;
        else if(Day==30)
        {
            Month++;
            Day=1;
        }
    }
    else if(Twenty)
    {
        if(Date::IsLeapYear())
        {
            if(Day<=28&&Day>=1)Day++;
            else if(Day==29)
            {
                Month=3;
                Day=1;
            }
        }
        else
        {
            if(Day<=27&&Day>=1)Day++;
            else if (Day==28)
            {
                Month=3;
                Day=1;
            }
        }
    }
    return;
}

Date& Date::operator++()
{
    this->NextDay();
    return *this;
}

Date Date::operator++(int) // can't reference or it will return a pointer to the local variable.
{
    Date another(*this);
    this->NextDay();
    return another;
}

Date::~Date(){}
