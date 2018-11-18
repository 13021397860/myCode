#include"Date.h"
#include<cstdio>
#include<iostream>
using namespace std;
int Ly[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int Ny[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
Date::Date(int y, int m, int d)
{
    setDate(y,m,d);
	/*year = y;
	month = m;
	day = d;*/
}
Date::Date(const Date &dat)
{
	year = dat.year;
	month = dat.month;
	day = dat.day;
}
Date::~Date(){
}
void Date::setDate( int y, int m, int d )
{
    year = y;
   if(m >= 1 && m <= 12)
    month = m;
    else
    {
    cout<<"数据不合法，已重置\n";
    month = 1;
    day = 1;
    year = 1900;
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
            if(d >= 1 && d <= 31)
                day = d;
            else
            {
            cout<<"数据不合法，已重置\n";
            month = 1;
            day = 1;
            year = 1900;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(d >= 1 && d <= 30)day = d;
            else
            {
            cout<<"数据不合法，已重置\n";
            month = 1;
            day = 1;
            year = 1900;
            }
            break;
        case 2:
            if(isLeapYear())
                if(d >= 1 && d <= 29)day = d;
                else
                {
                cout<<"数据不合法，已重置\n";
                month = 1;
                day = 1;
                year = 1900;
                }
            else
                if(d >= 1 && d <= 28)day = d;
                else
                {
                cout<<"数据不合法，已重置\n";
                month = 1;
                day = 1;
                year = 1900;
                }
        }

}

bool Date::isLeapYear()const
{
    if((year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0)
        return true;
    else
        return false;
}

const int Date::getYear()const
{
    return year;
}
const int Date::getMonth()const
{
	return month;
}
const int Date::getDay()const
{
	return day;
}
void Date::nextDay()
{
    if((day < Ly[month-1] && isLeapYear()) ||(day < Ny[month-1] && !isLeapYear()))
        day++;
    else if((day == Ly[month-1] && isLeapYear() && month < 12 )||( day == Ny[month-1] && !isLeapYear() && month < 12))
    {
        day = 1;
        month++;
    }
    else if((day == Ly[month-1] && isLeapYear() && month == 12 )||( day == Ny[month-1] && !isLeapYear() && month == 12))
    {
        day = 1;
        month = 1;
        year++;
    }
}
ostream& operator<<(ostream &Cout, const Date &date)
{
    Cout<<date.year<<"-"<<date.month<<"-"<<date.day;
    return Cout;
}
istream& operator>>(istream &Cin, const Date &date)
{
    cout<<"格式为：年 月 日，中间用空格隔开\n";
    scanf("%d%d%d", &date.year, &date.month, &date.day);
    //Cin>>date.year>>date.month>>date.day;
    return Cin;
}

Date& Date::operator++()
{
    nextDay();
    return *this;
}
Date& Date::operator++(int)
{
    Date before = *this;
    this->nextDay();
    return before;
}

