#include "date.h"
#include <iostream>
#include <cstdio>
#include "MyException.h"
#include <exception>
using namespace std;
const int M[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
Date::Date(int y, int m, int d)
{
    Set(y, m, d);
}
Date::Date(Date &D){
    Set(D.year,D.month,D.day);
}
Date::~Date()
{
    //dtor
}
int Date::Set(int x,int y,int z){
    year=x;
    month=y;
    day=z;
    if(!check()) throw -1;

    return 1;
}
bool Date::isLeapYear()
{
    if((year%4==0&&year%100!=0)||year%400==0)
        return true;
    return false;
}
void Date::nextDay()
{
    short y=0;
    if(isLeapYear())
        y=1;
    day++;
    if(day>M[y][month-1]){
        month++;
        day=1;
    }
    if(month>12){
        year++;
        month=1;
    }
}
bool Date::check()
{
    bool flag=true;
    int y=0;
    if(isLeapYear())
        y=1;
    if(day<=0||day>M[y][month-1]){
        flag=false;
        day=1;
    }
    if(month<=0||month>12){
        flag=false;
        month=1;
    }
    if(year<=0){
        flag=false;
        year=1900;
    }
    return flag;
}
ostream& operator << (ostream &output, const Date &x){
    output << x.year << "-" << x.month << "-" << x.day << "\n";
    return output;
}
Date& Date::operator ++(){
    nextDay();
    return *this;
}
Date& Date::operator ++(int){
    Date *p=this;
    nextDay();
    return *p;
}
