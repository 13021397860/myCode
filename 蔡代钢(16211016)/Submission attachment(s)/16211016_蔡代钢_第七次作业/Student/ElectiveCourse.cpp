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
        cout<<"#�����쳣��"<<ex.what3()<<"\n";
        printf("#����ĵȼ����󣬵ȼ��Զ�����ΪF(��δ���÷����ȼ�״̬)!\n");
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
