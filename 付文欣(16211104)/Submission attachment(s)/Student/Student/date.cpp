#include "date.h"
#include <windows.h>
int Month[2][14]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};   //0-not leapYear 1-leapYear


date::date(int y,int m,int d){
    setDate(y,m,d);
}

date::date(const date &d){
    setDate(d.year,d.month,d.day);
}

void date::setDate(int y,int m,int d){
    year=y; month=m; day=d;
    try{
        isLegalDate();
    }catch(MyException &Ex){
        Ex.wtfOfDate();
        system("pause");
        cout<<"\n请重新输入:";
        cin>>(*this);
    }
}

bool date::isLeapYear()const{
    if(((year%4==0)&&(year%100!=0))||(year%400==0)) return true;
    return false;
}

/*void date::print()const{
    printf("%d.%d.%d\n",year,month,day);
}*/

istream & operator >> (istream &in,date &D){
    int y,m,d;
    in>>y>>m>>d;
    D.setDate(y,m,d);
    return in;
}

ostream & operator << (ostream &out,const date &d){
    out<<d.getYear()<<"-"<<d.getMonth()<<"-"<<d.getDay()<<endl;
    return out;
}

date &date::operator + (const int t){
    for(int i=1;i<=t;i++){
        nextDay();
    }
    return (*this);
}

bool date::isLegalDate()const{
    if(year==0) {
        throw MyException();
        return false;
    }
    else{
        if(month>12||month<1) { throw MyException();return false; }
        else{
            if(isLeapYear()){  if(day>Month[1][month]||day<1) { throw MyException();return false; }}
            else{  if(day>Month[0][month]||day<1) {throw MyException();return false; }  }
        }
    }
    return true;
}

date date::operator ++(int i){ //后置
    date p=(*this);
    nextDay();
    return p;
}

date &date::operator++(){  //前置
    nextDay();
    return (*this);
}

void date::nextDay(){
    day++;
    if(!isLegalDate()){
        month++; day=1;
        if(!isLegalDate()){
            year++; month=1;
        }
    }
}

/*date::~date()
{
    //dtor
}*/

