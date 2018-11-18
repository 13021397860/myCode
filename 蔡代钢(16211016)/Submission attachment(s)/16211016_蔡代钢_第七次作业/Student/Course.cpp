#include "Course.h"
#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>
Course::Course()
{
    //ctor
}
void Course::setcourse(string a,double x)
{
    setname(a);
    setcreditHour(x);
}
void Course::setname(string a)
{
    name=a;
}
void Course::setpd(int a)
{
    pd=a;
}
void Course::setcreditHour(double x)
{
    if(x>8||x<0)
    {
        printf("#学分输入错误，自动修改为2！\n");
        //printf("#学分输入错误，自动修改为2！\n");
        creditHour=2;
    }
    else
        creditHour=x;
}
void Course::setall(string a,double x, double num)
{

}
void Course::setall(string a,double x, char scores)
{

}
void Course::setScore(double x)
{

}
void Course::setScore(char x)
{

}
double Course::getScore()
{

}
int Course::getpd() const
{
    return pd;
}
string Course::getname() const
{
    return name;
}
double Course::getcreditHour() const
{
    return creditHour;
}
Course::~Course()
{
    //dtor
}
