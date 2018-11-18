#include "ElectiveCourse.h"
#include<iostream>
using namespace std;
ElectiveCourse::ElectiveCourse(const string &n,int creditHour,char g):Course(n,creditHour)
{
    setgrade(g);
    //ctor
}
ElectiveCourse::ElectiveCourse():Course()
{

}
void ElectiveCourse::setgrade(char g)
{
    grade=(g=='A'||g=='B'||g=='C'||g=='D'||g=='E')?g:'A';
}
int ElectiveCourse::getScore()
{
    int h;
    if(grade=='A')
    {
        h=95;
    }
    else if(grade=='B')
    {
        h=85;
    }
    else if(grade=='C')
    {
        h=75;
    }
    else if(grade=='D')
    {
        h=65;
    }
    else
    {
        h=55;
    }
    return h;
}
//void ElectiveCourse::setCourse(const string &a,int b)
//{
 //   Course::Course(const string &a,int b);
//}
void ElectiveCourse::print()
{
    cout<<name<<":"<<grade<<":"<<getScore()<<endl;
}
ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
