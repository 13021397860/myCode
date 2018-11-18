#include "date.h"
#include "myexception.h" // class's header file
#include<iostream>
using namespace std;
// class constructor
Date::Date(int y,int m,int d)
{
	setyear(y);
	setmonth(m);
	setday(d);
	check(checklegal());
	//year=y;
	//month=m;
	//day=d;// insert your code here
}

// class destructor
Date::~Date()
{
	// insert your code here
}
Date::Date(const Date &t){
	day=t.day;
	month=t.month;
	year=t.year;
}
void Date::setyear(int y){
	year=y;
	//check(checklegal());
}
void Date::setmonth(int m){
	month=m;
	//check(checklegal());
}
void Date::setday(int d){
	day=d;
	//check(checklegal());
}
bool Date::isLeapYear(){
	if((year%4==0&&year%100!=0)||year%400==0){
		return 1;
	}
	else{
		return 0;
	}
}
void Date::nextDay(){
	bool ly;
	ly=isLeapYear();
	if(month==1||month==3||month==5||month==7||month==8||month==10){
		if(day==31){
			day=1;
			month++;
		}
		else{
			day++;
		}
	}
	else if(month==12){
		if(day==31){
			day=1;
			month=1;
			year++;
		}
		else{
			day++;
		}
	}
	else if(month==4||month==6||month==9||month==11){
		if(day==30){
			day=1;
			month++;
		}
		else{
			day++;
		}
	}
	else if(ly==1&&month==2){
		if(day==29){
			day=1;
			month=3;
		}
		else{
			day++;
		}
	}
	else if(ly==0&&month==2){
		if(day==28){
			day=1;
			month=3;
		}
		else{
			day++;
		}
	}
}
void Date::print()const{
	cout<<month<<'/'<<day<<'/'<<year<<endl;
}
int Date::checklegal(){
	bool ly;
	ly=isLeapYear();
	if(year<1){
		return 1;
	}
	else if(month<=0||month>=13){
		return 2;
	}
	else if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)&&(day<=0||day>=32)){
		return 3;
	}
	else if((month==4||month==6||month==9||month==11)&&(day<=0||day>=31)){
		return 3;
	}
	else if(month==2&&ly==1&&(day<=0||day>=30)){
		return 3;
	}
	else if(month==2&&ly==0&&(day<=0||day>=29)){
		return 3;
	}
	else{
		return 0;
	}
}
void Date::check(int n){
	if(n==1){
		throw MyException(DATE_INVALID);
		cout<<"年份不合法 已重置为1999年"<<endl; 
		year=1999;
	}
	else if(n==2){
		throw MyException(DATE_INVALID);
		cout<<"月份不合法 已重置为2月"<<endl; 
		month=2;
	}
	else if(n==3){
		throw MyException(DATE_INVALID);
		cout<<"日期不合法 已重置为28号"<<endl; 
		day=28;
	} 
}
ostream & operator << (ostream &output,const Date &date){
	output<<date.year<<'-'<<date.month<<'-'<<date.day<<endl;
	return output;
}
Date & Date::operator ++(){
	nextDay();
	return *this;
}
Date Date::operator++(int){
	Date t=*this;
	++(*this);
	return t;
}
