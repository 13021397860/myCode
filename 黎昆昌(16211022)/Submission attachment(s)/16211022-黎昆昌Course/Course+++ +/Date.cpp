#include "Date.h"
#include<iostream>
using namespace std;

Date::Date(const int y,const int m,const int d)
{
	setDate(y,m,d);
}

Date::Date(const Date& t){
	year=t.year;
	month=t.month;
	day=t.day;
}

bool Date::isLeapYear()
{
	bool res=false;
	if(year%400==0||(year%4==0&&year%100!=0)){
		res=true;
	}
	return res;
}

int Date::day_of_month()
{
	int res;
	int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	res=d[month];
	if(month==2&&isLeapYear()){
		res=29;
	}
	return res;
}

void Date::setDate(const int y,const int m,const int d)
{
    try{
        setYear(y);
        setMonth(m);
        setDay(d);
    }
	catch(MyException &e){
        cout<<e.what()<<endl;
    }
    catch(...){
        cout<<"Unknown mistake!"<<endl;
    }
}

void Date::setYear(const int y)
{
	if(y>0){
	    year=y;
    }
    else{
        year=1998;
        throw MyException(DATE_INVALID);
    }
}

void Date::setMonth(const int m)
{
	if(m>0&&m<13){
	    month=m;
    }
    else{
        month=4;
        throw MyException(DATE_INVALID);
    }
}

void Date::setDay(int d)
{
    if(d>0&&d<=day_of_month()){
	    day=d;
    }
    else{
        day=4;
        throw MyException(DATE_INVALID);
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

void Date::nextDay()
{
	if(month==12){
		if(day==31){
			year++;
			month=1;
			day=1;
		}
		else{
			day++;
		}
	}
	else{
		if(day==day_of_month()){
			day=1;
			month++;
		}
		else{
			day++;
		}
	}
}

istream &operator>>(istream &input,Date &date)
{
    int y,m,d;
    input>>y;
    input.ignore();
    input>>m;
    input.ignore();
    input>>d;
    input.ignore();
    date.setDate(y,m,d);
    return input;
}

ostream &operator<<(ostream &output,const Date &date)
{
    output<<date.getYear()<<'-'<<date.getMonth()<<'-'<<date.getDay();
    return output;
}

Date &Date::operator++()
{
    nextDay();
    return *this;
}

Date Date::operator++(int i)
{
    Date temp=*this;
    nextDay();
    return temp;
}

Date Date::operator+(int num)
{
    Date temp=*this;
    for(int i=0;i<num;i++){
        temp.nextDay();
    }
    return temp;
}

Date::~Date()
{
    /*cout<<endl;
    print();*/
}
