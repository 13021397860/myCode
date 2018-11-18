#include "Date.h"
#include<iostream>
#include <fstream>
#include <string>
#include "Exception.h"
int Date::classID() const {
	return ClassID;
}
Date::Date(int y,int m,int d){
    year=y;
    month=m;
    day=d;
    if(!rightData()){
		OORException ex(ClassID);
		throw ex;
    }
}
Date::Date(const Date& father){
    year=father.year;
    month=father.month;
    day=father.day;
}
Date::~Date(){
    //dtor
}
bool Date::rightData()const{
    if(month>12)
        return false;
    if(day>31)
        return false;
    if(isLeapYear()&&month==2&&day>29)
        return false;
    if(month==2&&day>28)
        return false;
    if(month==4||month==6||month==9||month==11)
        if(day>30)
            return false;
    return true;
}
bool Date::setAll( unsigned int Y=0, unsigned int M=0, unsigned int D=0){
    year=Y;
    month=M;
    day=D;
    if(!rightData()){
		OORException ex(ClassID);
		throw ex;
        year=month=day=0;
        return false;
    }else{
        return true;
    }
}
unsigned int Date::getYear()const{
    return year;
}
unsigned int Date::getMonth()const{
    return month;
}
unsigned int Date::getDay()const{
    return day;
}
void Date::getAll(unsigned int &Y,unsigned int &M,unsigned int &D)const{
    Y=year;
    M=month;
    D=day;
}
bool Date::isLeapYear()const{
    return (year%4==0&&year%100!=0)||year%400==0;
}
void Date::nextDay(){
    day++;
    if(!rightData()){
        day=1;
        month++;
    }
    if(!rightData()){
        month=1;
        year++;
    }
}
bool Date::operator == (const Date &another)const{
    if(year!=another.year)
        return false;
    if(month!=another.month)
        return false;
    if(day!=another.day)
        return false;
    return true;
}
/*Date::operator int() {
	return year * 10000 + month * 100 + day;
}*/
Date& Date::operator++() {
	nextDay();
	return *this;
}
Date Date::operator++(int) {
	Date temp(*this);
	(*this)++;
	return temp;
}
Date Date::operator+ (int days)const {
	Date temp(*this);
	for (int i = 0; i < days; i++) {
		temp++;
	}
	return temp;
}
std::ostream& operator << (std::ostream& output_date,const Date& date){
	output_date << date.getYear() << '-' << date.getMonth() << '-'<<date.getDay();
	return output_date;
}
std::istream& operator >> (std::istream& input_date, Date& date) {
	int y, m, d;
	input_date>> y >> m >> d;
	date.year = y;
	date.month = m;
	date.day = d;
	if (!date.rightData()) {
		date.year = 1997;
		date.month = 10;
		date.day = 16;
	}
	return input_date;
}
std::ofstream& operator << (std::ofstream& outputf_date, const Date& date) {
	outputf_date << date.year<<" "<< date.month<<" "<< date.day;
	return outputf_date;
}