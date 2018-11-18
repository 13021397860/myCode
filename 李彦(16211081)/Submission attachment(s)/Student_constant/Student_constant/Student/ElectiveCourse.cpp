#include "ElectiveCourse.h"
#include<iostream>
using std::cout;
using std::string;
using std::endl;
using std::cin;
ElectiveCourse::ElectiveCourse()
{
    //ctor
}

ElectiveCourse::ElectiveCourse(string n,int c,char g)
{
    name=n;
    creditHour=c;
    grade=g;//ctor
}

ElectiveCourse::~ElectiveCourse()
{

}

void ElectiveCourse::set_(string n,int c,char g)
{
    course::set_(n,c);
    grade=g;
}

char ElectiveCourse::getEGrade()
{
    return grade;
}

void ElectiveCourse::setChengji(int in,char g)
{
    grade=g;
}

void ElectiveCourse::print()
{
    cout<<"coursename:"<<name<<" creditHour:"<<creditHour<<" grade:"<<grade<<endl;
}

int ElectiveCourse::getScore() const
{
    if(grade=='A')  return 90;
    else if(grade=='B') return 80;
    else if(grade=='C') return 70;
    else if(grade=='D') return 60;
     else if(grade=='E') return 50;
     else   return 40;
}
