//
//  Date.cpp
//  Date
//
//  Created by Pirate Hero on 17/3/7.
//  Copyright © 2017年 mac. All rights reserved.
//
#include <iostream>

#include "Date.hpp"
using namespace std;
Date::Date(const Date & X)
{
    year=X.year;
    month=X.month;
    day=X.day;
}

void Date::setDate()
{
    int y,m,d;
    cin>>y>>m>>d;
    year=y;
    month=m;
    day=d;
    
}

void Date::getDate()
{
    Year=year;
    Month=month;
    Day=day;
}

void Date::nextDay()
{
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if(day==31)
            {
                month++;
                day=1;
            }
            else
                day++;
            break;
        case 12:
            if(day==31)
            {
                month=1;
                day=1;
                year+=1;
            }
            else
                day++;
            break;
        case 2:
        {
            if(isLeapYear())
            {
                if(day==29)
                {
                    month=3;
                    day=1;
                }
                else day++;
            }
            else if(day==28)
            {
                month=3;
                day=1;
            }
            else day++;
        }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(day==30)
            {
                month++;
                day=1;
            }
            else
                day++;
            break;
    }
    
}
bool Date::isLeapYear()const
{
    
    if(year%4!=0 ||(year%100==0&&year%400!=0))
        return false;
    else
        return true;
}

Date::Date()
{
    year=0;
    month=0;
    day=0;
}

int Date::Judge()const
{
    int J;
    bool R=Date::isLeapYear();
    J=1;
    if(day<0) J=0;
        else
        {
            if(month>12||month<0) J=0;
                else
                    switch(month)
                {
                        
                        
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        if(day>31)
                            
                            J=0;
                            
                            break;
                        
                        
                    case 2:
                        if(!R)
                        { if(day>28)
                            J=0;
                            }
                        else if(day>29)
                        {
                            J=0;
                        }
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        if(day>30)
                            J=0;
                            break;
                }
            
            
            
            
            
        }
    
    if(J==0) return 0;
    else return 1;
}
ostream & operator<<(ostream &out, Date &A)
{
    out << A.year <<" "<< A.month <<" "<<A.day<<endl;
    return out;
}
istream & operator>>(istream &in,Date &A){
    in >> A.year>>A.month >> A.day;
    return in;
}
Date::~Date()
{
    
}
