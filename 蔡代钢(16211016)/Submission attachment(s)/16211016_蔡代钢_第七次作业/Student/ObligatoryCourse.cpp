#include "ObligatoryCourse.h"
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>
void setscoreexception1(double a)
{
    if(a>100||a<-1)
    {
        throw MyException();
    }
}
ObligatoryCourse::ObligatoryCourse()
{

}
ObligatoryCourse::ObligatoryCourse(string a,double x,double num)
{
    setcourse(a,x);//ctor
    setScore(num);
}
void ObligatoryCourse::setall(string a,double x,double num)
{
    setcourse(a,x);
    setScore(num);
}
void ObligatoryCourse::setScore(double a)
{
    try{
        setscoreexception1(a);
        mark=a;
    }catch(MyException ex){
        cout<<"#出现异常："<<ex.what3()<<"\n";
        printf("#成绩输入错误，自动修改为-1分（即未设置分数状态）!\n");
        mark=-1;
    }
}
double ObligatoryCourse::getScore()
{
    return mark;
}
ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
