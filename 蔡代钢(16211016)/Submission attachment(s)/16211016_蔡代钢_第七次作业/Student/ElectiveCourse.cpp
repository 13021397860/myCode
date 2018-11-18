#include "ElectiveCourse.h"
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>
void setscoreexception2(char grades)
{
    if(grades=='A'||grades=='B'||grades=='C'||grades=='D'||grades=='E'||grades=='F')
    {
    }
    else
        throw MyException();
}
ElectiveCourse::ElectiveCourse()
{

}
ElectiveCourse::ElectiveCourse(string a,double x,char grades)
{
    setcourse(a,x);//ctor
    setScore(grades);
}
void ElectiveCourse::setall(string a,double x,char grades)
{
    setcourse(a,x);//ctor
    setScore(grades);
}
void ElectiveCourse::setScore(char grades)
{
    try{
        setscoreexception2(grades);
        grade=grades;
    }catch(MyException ex){
        cout<<"#出现异常："<<ex.what3()<<"\n";
        printf("#输入的等级有误，等级自动设置为F(即未设置分数等级状态)!\n");
        grade='F';
    }
}
double ElectiveCourse::getScore()
{
    if(grade=='A')
        return 95;
    else if(grade=='B')
        return 85;
    else if(grade=='C')
        return 75;
    else if(grade=='D')
        return 65;
    else if(grade=='E')
        return 55;
    else if(grade=='F')
        return -1;
}
ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
