#include "Date.h"
#include "MyException.h"
#include <iostream>
using namespace std;

Date::Date()
{
    year=1998;
    month=9;
    day=18;
}

Date::Date(int y, int m, int d)
{
    setDate(y, m, d);
}

Date::Date(const Date &d)
{
    setDate(d.year, d.month, d.day);
}

Date::~Date()
{
    //dtor
}

void Date::setDate(int y, int m, int d)
{
    year=y;
    month=m;
    day=d;

    if(!checkDate())
    {
        throw MyException(DATE_INVALID);
    }

}

bool Date::checkDate()
{
    bool flag=true;

    if ((month<1)||(month>12))
    {
        month=1;
        flag=false;
    }
    if ((day<1)||(day>maxDay()))
    {
        day=1;
        flag=false;
    }
    return flag;
}

int Date::maxDay() const
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
            if(isLeapYear()) return 29;
            else return 28;
        default:
            return 0;
    }
}

bool Date::isLeapYear() const
{
    return ( ((year%4==0)&&(year%100)) || (year%400==0) );
}

void Date::nextDay()
{
    day++;
    if(!checkDate()) month++;
    if(!checkDate()) year++;
}

/*void Date::print() const
{
    cout<<year<<"-"<<month<<"-"<<day;
}*/

Date& Date::operator++()
{
    nextDay();
    return *this;
}

Date Date::operator++(int)
{
    Date d=*this;
    nextDay();
    return d;
}

ostream& operator<<(ostream &output, const Date &d)
{
    output<<d.year<<"-"<<d.month<<"-"<<d.day;
    return output;
}

istream& operator>>(istream& input, Date &d)
{
	int year, month, day;
	input>>year>>month>>day;
	d.setDate(year,month,day);
	return input;
}
