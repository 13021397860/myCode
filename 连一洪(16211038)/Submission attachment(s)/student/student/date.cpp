#include "date.h"
#include "MyException.h"
#include <iostream>
using namespace std;
using std::ostream;
Date::Date(const int y, const int m, const int d)
{
    setDate(y,m,d);
    //ctor
}
Date::Date(const Date &a){
    Year=a.Year;
    Month=a.Month;
    Day=a.Day;
}

int Date::getYear()const {
    return Year;
}

int Date::getMonth()const{
    return Month;
}

int Date::getDay()const{
    return Day;
}

bool Date::checkDate(int y, int m, int d){
    if(y>=0&&m>=1&&m<=12){
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
            if(d>=1&&d<=31) return 1;
            else return 0;
        }
        else if(m==4||m==6||m==9||m==11){
            if(d>=1&&d<=30) return 1;
            else return 0;
        }
        else{
            if(isLeapYear(y)){
                if(d>=1&&d<=29) return 1;
                else return 0;
            }
            else{
                if(d>=1&&d<=28) return 1;
                else return 0;
            }
        }
    }
    else return 0;
}
void Date::setDate(int y, int m, int d){
    if(!checkDate(y,m,d)){
        throw Date_exception();
        Year=0;Month=0;Day=0;
    }
    else{
        Year=y;Month=m;Day=d;
    }

}

bool Date::isLeapYear(const int y){
    if((y%4==0&&y%100!=0)||(y%400==0))
        return true;
    else
        return false;
}

void Date::nextDay(){
    if(Month==1||Month==3||Month==5||Month==7||Month==8||Month==10||Month==12){
        if(Month==12){
            if(Day==31){
                Day=1;
                Month++;
                Year++;
            }
            else
                Day++;
        }
        else{
            if(Day==31){
                Day=1;
                Month++;
            }
            else
                Day++;
        }
    }
    else if(Month==4||Month==6||Month==9||Month==11){
        if(Day==30){
            Day=1;
            Month++;
        }
        else
            Day++;
    }
    else{
        if(Date::isLeapYear(Year)){
            if(Day==29){
                Day=1;
                Month++;
            }
            else
                Day++;
        }
        else{
            if(Day==28){
                Day=1;
                Month++;
            }
            else
                Day++;
        }
    }

}
ostream& operator<<(ostream& output ,const Date& date){
            output<<date.Year<<"-"<<date.Month<<"-"<<date.Day<<"\n";
            return output;
        }
/*
void Date::printDate()const{
    cout<<Year<<" "<<Month<<" "<<Day<<" "<<endl;
}
*/
