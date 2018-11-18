#include <iostream>
#include "Date.h"
using namespace std;

ostream& operator << (ostream& output, const Date& d)
{
    output << d.year << "-" << d.month << "-" << d.day;
    return output;
}

Date& Date::operator++()
{
    this->day++;
    if (!checkDate()){
        this->month++;
        if (!checkDate()){
            this->year++;
        }
    }
    return *this;
}

Date Date::operator++(int )
{
    Date d(*this);
    this->day++;
    if (!checkDate()){
        this->month++;
        if (!checkDate()){
            this->year++;
        }
    }
    return d;
}

Date::Date(const int y, const int m, const int d)
{
    year=y;
    month=m;
    day=d;
    if (!checkDate()) throw MyException("Invalid date.\n");
}

Date::Date(const Date &da)
{
    year=da.year;
    month=da.month;
    day=da.day;
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

void Date::setDate(const int y, const int m, const int d)
{
    year=y;
    month=m;
    day=d;
    if (!checkDate()) cout << "False input!" << endl;
}

void Date::nextDay()
{
    day++;
    if (!checkDate()){
        month++;
        if (!checkDate()){
            year++;
        }
    }
}

bool Date::isLeapYear() const
{
    if (year%4==0&&year%100!=0||year%400==0) return true;
    else return false;
}

bool Date::checkDate()
{
    if (month<1||month>12) {month=1; return 0;}
    else if (day<1||day>maxDay()) {day=1; return 0;}
    else return 1;
}

int Date::maxDay() const
{
    switch(month){
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
            return isLeapYear()?29:28;
        default:
            return 31;
    }
}

Date::~Date()
{
    //dtor
}
