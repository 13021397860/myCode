#include "Course.h"
#include<iostream>
using namespace std;

ostream &operator<<(ostream &output,const Course &course)
{
    //int a=course.Getscore();
    output<<"课程名: "<<course.name<<"  "<<"学分: "<<course.creditHour<<"成绩: "<<course.Getscore()<<endl;
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

