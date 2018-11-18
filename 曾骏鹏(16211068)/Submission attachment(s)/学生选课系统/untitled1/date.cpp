//
// Created by zjp on 2017/4/17.
//

#include "date.h"
#include "myException.h"
#include <iostream>
using namespace std;

int date::getYear() const {
    return year;
}

int date::getMonth() const {
    return month;
}

int date::getDay() const {
    return day;
}

void date::setYear(const int y) {
    year=y;
    check();
}

void date::setMonth(const int m) {
    month=m;
    check();
}

void date::setDay(int d) {
    day=d;
    check();
}

void date::setDate(int y,int m,int d) {
    year=y;
    month=m;
    day=d;
}

bool date::isLeapYear() const {
    if((year%4==0 && year%100!=0) || year%400==0)
        return 1;
    else
        return 0;
}

void date::nextDay() {
    if(month==12 && day==31)
        year+=1,month=1,day=1;
    else if(day==31)
        month+=1,day=1;
    else if(month==2 && ((isLeapYear() && day==29) || (!isLeapYear() && day==29)))
        month=3,day=1;
    else if((month==4 || month==6 || month==9 || month==11) && day==30)
        month+=1,day=1;
    else
        day+=1;
}

/*void date::printDate() const {
    cout << "The date is " << year << '.' << month << '.' << day << '.' << endl;
}*/

ostream& operator << (ostream &os,const date &t)
{
    os << t.year << '-' << t.month << '-' << t.day;
    return os;
}

istream& operator >> (istream &is,date &t)
{
    char a,b;
    is >> t.year >> a >> t.month >> b >> t.day;
    return  is;
}

date& date::operator ++()
{
    nextDay();
    return *this;
}

date& date::operator ++(int)
{
    date temp(year,month,day);
    nextDay();
    return temp;
}

bool date::check() const {
    if(day<1 || day >31)
        return 0;
    if(month<1 || month>12)
        return 0;
    if(year<1)
        return 0;
    if(month==2 && ((isLeapYear() && day>29) || (!isLeapYear() && day>28)))
        return 0;
    if((month==4 || month==6 || month==9 || month==11) && day>30)
        return 0;
    return 1;
}

date::date(int y,int m,int d) {
    setDate(y,m,d);
}

date::date(const date &t) {
    setDate(t.year,t.month,t.day);
}



date::~date() {

}
