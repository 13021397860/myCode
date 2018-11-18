#include <cstdio>
#include "date.h"
int Month[2][14]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};   //0-not leapYear 1-leapYear


date::date(int y,int m,int d){
    setDate(y,m,d);
}

date::date(const date &d){
    setDate(d.year,d.month,d.day);
}

void date::setDate(int y,int m,int d){
    year=y; month=m; day=d;
    if(!isLegalDate()){
        printf("日期不合法!请重新输入:\n");
        scanf("%d%d%d",&y,&m,&d);
        setDate(y,m,d);
    }
}

bool date::isLeapYear(){
    if(((year%4==0)&&(year%100!=0))||(year%400==0)) return true;
    else return false;
}

void date::print()const{
    printf("%d.%d.%d\n",year,month,day);
}

bool date::isLegalDate(){
    if(year==0) return false;
    else{
        if(month>12||month<1) return false;
        else{
            if(isLeapYear()){
                if(day>Month[1][month]||day<1) return false;
            }
            else{
                if(day>Month[0][month]||day<1) return false;
            }
        }
    }
    return true;
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

