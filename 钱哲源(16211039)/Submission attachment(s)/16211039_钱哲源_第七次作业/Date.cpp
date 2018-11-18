#include "Date.h"
#include "MyException.h"
#include<iostream>
#include<iomanip>
using namespace std;


ostream& operator<<(ostream& output, const Date& da)
{
    output<<da.year<<"-"<<da.month<<"-"<<da.day<<endl;
    return output;
}

Date& Date::operator++()
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

Date::Date(){}
Date::Date(int y,int m,int d)
{
    setDate(y,m,d);
}
Date::Date(const Date &da)
{
    year=da.year;
    month=da.month;
    day=da.day;
}
void Date::setDate(int y,int m,int d){
    year=y;
    month=m;
    day=d;
    if(!checkDate())
    {
        throw MyException("wrong date.\n");
    }
}
void Date::setYear(int y){
    year=y;
}
void Date::setMonth(int m){
    month=m;
}
void Date::setDay(int d){
    day=d;
}
int Date::getYear()const{
    return year;
}
int Date::getMonth()const{
    return month;
}
int Date::getDay()const{
    return day;
}
bool Date::isLeapYear()const
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return true;
    else return false;
}
void Date::nextDay(){
    day++;
    if (!checkDate()){
        month++;
        if (!checkDate()){
            year++;
        }
    }
}


bool Date::checkDate(){
    if (month < 1 || month > 12){
        month = 1;
        return false;
    }
    else if (day < 1 ){
        day = 1;
        return false;
    }
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)&& day > 31){
        day = 1;
        return false;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11)&& day > 30){
        day = 1;
        return false;
    }
    else if (isLeapYear() && month ==2 && day > 29){
        day = 1;
        return false;
    }
    else if (!isLeapYear() && month ==2 && day > 28 ){
        day = 1;
        return false;
    }
    else return true;
}
