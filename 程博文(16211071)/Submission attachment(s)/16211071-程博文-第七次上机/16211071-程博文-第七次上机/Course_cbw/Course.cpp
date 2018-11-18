#include "Course.h"
#include<iostream>
#include<typeinfo>
#include"ObligatoryCourse.h"
#include"ElectiveCourse.h"
#include"MyException.h"
#include<iomanip>
//#include <string>
using namespace std;

Course::Course()
{
    //ctor
}

Course::Course(string _name,int _creditHour)
{
    setName(_name);
    setcreditHour(_creditHour);
}

Course::~Course()
{
    //dtor
}

void Course::setName(string _name)
{
    name=_name;
}

void Course::setcreditHour(int _creditHour)
{
    creditHour=_creditHour;
}

string Course::getName() const
{
    return name;
}

int Course::getcreditHour() const
{
    return creditHour;
};


void Course::SetMark()
{
    int ObliMark;
    char ElecGrade;
    if(typeid(ObligatoryCourse)==typeid(*this))
    {
        cout<<"请输入"<<this->name<<"（必修课）成绩:0~100\n";
        cin>>ObliMark;
        if(ObliMark<0||ObliMark>100)
        {
            MyException ex;
            ex.InvalidGrade();
            throw ex;
        }
        dynamic_cast<ObligatoryCourse*>(this)->setMark(ObliMark);
    }
    else if(typeid(ElectiveCourse)==typeid(*this))
    {
        cout<<"请输入"<<this->name<<"（选修课）成绩:五级制\n";
        cin>>ElecGrade;
        if(ElecGrade<65||ElecGrade>69)
        {
            MyException ex;
            ex.InvalidGrade();
            throw ex;
        }
        dynamic_cast<ElectiveCourse*>(this)->setGrade(ElecGrade);
    }
}

ostream & operator <<(ostream&os,const Course& c)
{
    os<<"CourseName："<<setw(16)<<left<<c.name<<"CreditHour："<<setw(4)<<left<<c.creditHour<<"Grade："<<setw(4)<<left<<c.getScore();
    return os;
}
