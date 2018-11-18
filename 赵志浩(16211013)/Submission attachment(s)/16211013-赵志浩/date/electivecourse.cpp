#include "electivecourse.h"
int ElectiveCourse::score[5]={95,85,75,65,55};
ElectiveCourse::ElectiveCourse(string n,int c,char g):Course(n,c)
{
    this->grade=g;
}
ElectiveCourse::ElectiveCourse(const ElectiveCourse& a):Course(a.name,a.creditHour)
{
    this->grade=a.grade;
}
void ElectiveCourse::setScore(int g)
{
    bool flag=true;
    for (int i=0;i<5&&flag;i++)
        if(g>=score[i])
        {
            grade=i+'A';
            flag=false;
        }
    if(flag)    grade='E';
    return;
}
ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
