#include "Date.h"

#include <iostream>
//#include <iomanip>

const int dayOfMonth[13]={31,31,28,31,30,31,30,31,31,30,31,30,31}; // the first value is only used in function lastDay();

Date::Date() //default constructor
{
    setDate(1970,1,1);
}

Date::Date(const int &y,const int &m,const int &d) //constructor
{
    year = 1970;
    month = 1;
    day = 1;
    setDate(y,m,d);
}

Date::~Date() //destructor
{

}

Date::Date(const Date& another) //copy constructor
{
    setDate(another.year,another.month,another.day);
}

Date Date::operator+(const int& n)
{
    Date re(*this);
    re.nextDay(n);
    return re;
}

Date Date::operator-(const int& n)
{
    Date re(*this);
    re.lastDay(n);
    return re;
}

Date& Date::operator+=(const int& n)
{
    nextDay(n);
    return *this;
}

Date& Date::operator-=(const int& n)
{
    lastDay(n);
    return *this;
}

Date& Date::operator++()
{
    nextDay();
    return *this;
}

const Date Date::operator++(int)
{
    Date re = *this;
    nextDay();
    return re;
}

bool Date::operator ==(const Date& another)
{
    return (this->year == another.year) && (this->month == another.month) && (this->day == another.day);
}

bool Date::operator !=(const Date& another)
{
    return (this->year != another.year) || (this->month != another.month) || (this->day != another.day);
}

bool Date::operator >(const Date& another)
{
    return (this->year > another.year) || ((this->year == another.year) && (this->month > another.month)) || ((this->year == another.year) && (this->month == another.month) && (this->day > another.day));
}

bool Date::operator <(const Date& another)
{
    return (this->year < another.year) || ((this->year == another.year) && (this->month < another.month)) || ((this->year == another.year) && (this->month == another.month) && (this->day < another.day));
}

bool Date::operator >=(const Date& another)
{
    return !(*this < another);
}

bool Date::operator <=(const Date& another)
{
    return !(*this > another);
}

std::istream& operator >>(std::istream& input, Date& date)
{
    int y_temp, m_temp, d_temp;
    input >> y_temp;
    input.ignore();
    input >> m_temp;
    input.ignore();
    input >> d_temp;
    if(input.fail())
    {
        input.clear();
        input.sync();
        y_temp = 1970;
        m_temp = d_temp = 1;
    }
    date.setDate(y_temp, m_temp, d_temp);
    return input;
}

std::ostream& operator <<(std::ostream& output, const Date& date)
{
    output << date.year << "-"
        << date.month << "-"
        << date.day;
    return output;
}

void Date::setDate(const int &y, const int &m,const int &d) //throw(Illegal_Date_Exception)
{
    int y_bak = year;
    int m_bak = month;
    int d_bak = day;
    year = y;
    month = m;
    day = d;
    if(!isLegal())
    {
        year = y_bak;
        month = m_bak;
        day = d_bak;
        throw Illegal_Date_Exception();
    }
}

void Date::setDate(const Date &another)
{
    setDate(another.year,another.month,another.day);
}

void Date::setYear(const int &y) //throw(Illegal_Date_Exception)
{
    int y_bak = year;
    year = y;
    if(!isLegal())
    {
        year = y_bak;
        throw Illegal_Date_Exception();
    }
}

void Date::setMonth(const int &m) //throw(Illegal_Date_Exception)
{
    int m_bak = month;
    month = m;
    if(!isLegal())
    {
        month = m_bak;
        throw Illegal_Date_Exception();
    }
}

void Date::setDay(const int &d) //throw(Illegal_Date_Exception)
{
    int d_bak = day;
    day = d;
    if(!isLegal())
    {
        day = d_bak;
        throw Illegal_Date_Exception();
    }
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

bool Date::isLegal()
{
    if(year == 0 || month < 1 || month > 12 || day < 1)
    {
        return false;
    }
    if(month == 2)
    {
        if(isLeapYear())
        {
            if(day > 29)
            {
                return false;
            }
        }
        else if(day > 28)
        {
            return false;
        }
    }
    else if(day > dayOfMonth[month])
    {
        return false;
    }
    return true;
}

bool Date::isLeapYear()
{
    bool re = false;
    if(year < 0)
    {
        ++year;
    }
    if(year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0))
    {
        re = true;
    }
    if(year <= 0)
    {
        --year;
    }
    return re;
}

void Date::nextDay(const int& next) //default value of "next" is 1
{
    day += next;
    while(day > dayOfMonth[month])
    {
        if(isLeapYear() && month == 2 && day == 29)
        {
            break;
        }
        else
        {
            day -= dayOfMonth[month++];
        }
        if(month == 13)
        {
            ++year;
            month = 1;
            if(year == 0)
            {
                year = 1;
            }
        }
    }
}

void Date::lastDay(const int& last) //default value of "last" is 1
{
    day -= last;
    while(day <= 0)
    {
        if(isLeapYear() && month == 3)
        {
            month = 2;
            day += 29;
        }
        else
        {
            day += dayOfMonth[--month];
        }
        if(month == 0)
        {
            --year;
            month = 12;
            if(year == 0)
            {
                year = -1;
            }
        }
    }
}
