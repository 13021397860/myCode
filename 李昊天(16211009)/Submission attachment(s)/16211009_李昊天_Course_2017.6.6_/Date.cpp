#include "Date.h"
#include "MyException.h"
#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
using namespace std;

bool Date::isLeapYear()
{
    if(year%400==0 || (year %4==0 && year %100 !=0)){mon[2]=29; return true;}
    else {mon[2]=28; return false;}
}

Date::Date(int y,int m,int d)
{
    setDate(y,m,d);
    da=true;
}

Date::Date(Date &d)
{
    year=d.year;
    month=d.month;
    day=d.day;
}

Date::~Date()
{

}
void Date::CheckDate()
{
    if(year%400==0 || (year %4==0 && year %100 !=0)){mon[2]=29;}
    else {mon[2]=28;}
    if(year<=0){year=1970;month=1;day=1;throw MyException(date);}
    if(month<=0 || month>12){year=1970;month=1;day=1;throw MyException(date);}
    if(day<=0 || day>mon[month]){year=1970;month=1;day=1;throw MyException(date);}
}

void Date::setDate(int y,int m,int d)
{
    da=true;
    year=y;
    month=m;
    day=d;
    try{
        CheckDate();
    }
    catch(MyException me){
        da=false;
        cout<<me.what()<<endl;
    }
}

void Date::nextDay()
{
    if(year%400==0 || (year %4==0 && year %100 !=0)){mon[2]=29;}
    else {mon[2]=28;}
    if(day<mon[month])day++;
    else{
        day=1;
        if(month<11)month++;
        else{
            month=1;
            year++;
        }
    }
}

string Date::toString() const
{

    string ys,ms,ds;
    stringstream yys,mms,dds;
    yys << year;mms<<month;dds<<day;
    yys >> ys; mms >> ms; dds >> ds;
    return ys+"-"+ms+"-"+ds;
}

/*void Date::print()
{

    cout<<year<<"-"<<setfill('0')<<setw(2)<<month<<"-"<<setfill('0')<<setw(2)<<day<<endl;
}
*/

Date& Date::operator ++ (){
    //前置
    //期望使用方式 ++a
    this->nextDay();
    return *this;
}

Date Date :: operator ++ (int){
    //后置
    //期望使用方式 a++
    Date tmp = *this;
    ++(*this);
    return tmp;
}
