#include "Course.h"
#include<iostream>
using namespace std;

ostream &operator<<(ostream &output,const Course &course)
{
    //int a=course.Getscore();
    output<<"�γ���: "<<course.name<<"  "<<"ѧ��: "<<course.creditHour<<"�ɼ�: "<<course.Getscore()<<endl;
    return output;
}


Course::Course()
{
    name="none";
    creditHour=0;
    //ctor
}

Course::Course(std::string N,int s)
{
    name=N;
    creditHour=s;
}

void Course::Setcourse(std::string N,int s)
{
    name=N;
    creditHour=s;
}

void Course::Getcourse()
{
    cout<<*this;
}

int Course::GetcreditHour()
{
    return creditHour;
}

Course::~Course()
{
    //dtor
}

