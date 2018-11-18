#include<iostream>
#include "Date.h"
#include <iomanip>
using namespace std;


Date::Date(int yy,int mm,int dd)//这里的yy，mm，dd只是一个参数而已；
{
    setDate(yy,mm,dd);

    //ctor
}
Date::Date(Date &t)
{
    year=t.year;
    month=t.month;
    day=t.day;
    //ctor
}
void Date::setDate(int y,int m,int d){
year=(y>0)?y:1949;
month=(m>0 || m<=12)?m:1;
day=(d>0 || d<31)?d:1;
}

bool Date::isLeepYear(){
    if(year%400==0 || (year%100!=0 && year%4==0)){
        monkey[2]=29;
        return true;
    }
    else {monkey[2]=28;return false;}
}

void Date::cheakDate(){

    if(month==2){
        if(isLeepYear()==1 && day>29){year=1949;month=1;day=1;}
        if(isLeepYear()==0 && day>28){year=1949;month=1;day=1;}
    }
    if(month==1 || month==3 ||month==5 || month==7 || month==8 || month==10 || month==12){
        if(day>31){year=1949;month=1;day=1;}
    }
    if(month==4 || month==6 || month==9 || month==11){
        if(day>30){year=1949;month=1;day=1;}
    }


}


void Date::nextDay(){
    if(day<monkey[month]){day++;}
    else {
        day=1;
        if(month==12){
            month=1;
            year++;
        }
        else {month++;}

    }
}

void Date::print(){

    cout<<year<<"/"<<setfill('0')<<setw(2)<<month<<"/"<<setfill('0')<<setw(2)<<day<<endl;
}


Date::~Date()
{
    //dtor
}
