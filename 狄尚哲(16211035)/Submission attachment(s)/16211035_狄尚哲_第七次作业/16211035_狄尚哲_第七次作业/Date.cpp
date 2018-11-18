#include "Date.h"
#include "MyException.h"
int Year[2] = {365, 366};
int Month[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};

Date::Date(const int y, const int m, const int d)
{
    setDate(y, m, d);
    isValid();
}
Date::Date(const Date &d){
    setDate(d.year, d.month, d.day);
    isValid();
}

Date::~Date(){}

int Date::getYear()const{ return year;}
int Date::getMonth()const{ return month;}
int Date::getDay()const{ return day;}

bool Date::setDate(int y, int m, int d){
    month = m;
    day = d;
    year = y;
    if(!isValid()) throw MyException(DATE_INVALID);
    return isValid();
}

bool Date::isLeapYear(){
    if((year%4==0 && year%100!=0) || year%400==0) return true;
    else return false;
}

//重载++
Date& Date::operator ++(){//前置
     day++;
     if(day > Month[isLeapYear()][month]){
         //cout<<"##Month["<<isLeapYear()<<"]["<<month<<"]: "<<Month[isLeapYear()][month]<<endl; //
         day -= Month[isLeapYear()][month];
         month++;
     }
     if(month > 12){
         month = 1;
         year++;
     }
     return *this;
}
Date Date::operator ++(int){//后置
     Date before = *this;
     day++;
     if(day > Month[isLeapYear()][month]){
         //cout<<"##Month["<<isLeapYear()<<"]["<<month<<"]: "<<Month[isLeapYear()][month]<<endl; //
         day -= Month[isLeapYear()][month];
         month++;
     }
     if(month > 12){
         month = 1;
         year++;
     }
     return before;
}
//void Date::nextDay(){
//     day++;
//     if(day > Month[isLeapYear()][month]){
//         //cout<<"##Month["<<isLeapYear()<<"]["<<month<<"]: "<<Month[isLeapYear()][month]<<endl; //
//         day -= Month[isLeapYear()][month];
//         month++;
//     }
//     if(month > 12){
//         month = 1;
//         year++;
//     }
// }


//重载+
//Date& Date::operator +(int d){

//}


//重载<< >>
//void Date::print()const{
//    cout << setfill('0') << setw(2) << month << '/' << setfill('0') << setw(2) << day << '/' << setfill('0') << setw(4) << year << endl;
//}
ostream & operator<<(ostream &os, const Date &d){
    os << d.year << "-" << d.month << "-" << d.day;
    return os;
}

istream & operator>>(istream &is, Date &D){
    int y, m, d;
    is >> y >> m >> d;
    D.setDate(y, m, d);
    //is >> d.year >> d.month >> d.day;
    return is;
}



bool Date::isValid(){
    int flag = 1;
    if(day <= 0 || day > Month[isLeapYear()][month]){
        //printf("##Month[%d][%d]:%d\n", isLeapYear(), month, Month[isLeapYear()][month]);
        if(day >= Month[isLeapYear()][month]) month++;
        day = 1;
        flag = 0;
    }
    if(month <= 0 || month > 12){
        if(month>12) year++;
        flag = 0;
        month = 1;
    }
    //if(!flag) throw MyException(DATE_INVALID);
    return flag;
}
