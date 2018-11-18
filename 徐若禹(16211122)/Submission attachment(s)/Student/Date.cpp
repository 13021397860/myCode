#include "Date.h"

Date::Date(int y, int m, int d)
{
    if(checkDate( y, m ,d))
        setDate( y, m, d);
    else
        printWrong();
}

Date::~Date()
{

}

Date::Date(const Date &t)
{
    month = t.month;
    day = t.day;
    year = t.year;
}

bool Date::checkDate( int y, int m, int d )
{
    int maxDay[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};

    int flagy = 0;
    if(isLeapYear(y))
        flagy = 1;
    if(m >= 1 && m <= 12)
    {
        if(d >= 1 && d <= maxDay[flagy][m-1])
            return true;
        else
            return false;
    }
    else
        return false;
}

bool Date::isLeapYear( int y )
{
    return ( y % 4 == 0 && y % 100 != 0) || ( y % 400 == 0 );
}

void Date::setDate( int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}


Date Date::getDate(Date &d)
{
    return d;
}

Date Date::nextDay()
{
    day++;
    if(!checkDate(year ,month ,day))
    {
        day = 1;
        month++;
        if(!checkDate(year ,month ,day))
        {
            month = 1;
            year++;
        }
    }
}

Date &Date::operator++()
{
    nextDay();
    return *this;
}

Date Date::operator++(int)
{
    Date temp = *this;
    nextDay();
    return temp;
}

void Date::printWrong() const
{
    cout << "The date is invalid£¡" << endl;
}

ostream &operator<<(ostream &output,const Date &date)
{
    output << date.year << "-" << date.month << "-" << date.day;
    return output;
}
