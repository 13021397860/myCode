#include "electivecourse.h"
#include<string>
#include<iostream>
#include"Myexception.h"
using namespace std;

electivecourse::electivecourse(const string &n,const int &c)
{
    setname(n);
    setcred(c);
    grade='F';
}
electivecourse::electivecourse(const electivecourse &e)
{
    name=e.name;
    creditHour=e.creditHour;
    grade=e.grade;
}
electivecourse::~electivecourse()
{
    cout<<"the electivecourse has been destroyed"<<endl;//dtor
}


void electivecourse::setgrade(const char &g)
{
    grade=g;
    if(grade!='A'&&grade!='B'&&grade!='C'&&grade!='D'&&grade!='E')
        throw Myexception();
}

int electivecourse::getscore()const
{

    switch(grade)
    {
        case 'A': return 95;
        case 'B': return 85;
        case 'C': return 75;
        case 'D': return 65;
        case 'E': return 55;
        default : return -1;
    }
}

ostream& operator<<(ostream& out,const electivecourse &x)
{
    out<<"课程名："<<x.getname()<<"      "<<"学分："<<x.getcred()<<"      "<<"成绩："<<x.getscore()<<endl;
    return out;
}
