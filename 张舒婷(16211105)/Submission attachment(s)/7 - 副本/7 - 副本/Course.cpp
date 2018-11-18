#include "Course.h"
#include<iostream>
using namespace std;
Course::Course(string name_,int creditHour_)
{
    setCourse(name_,creditHour_);
}

Course::~Course()
{
    //dtor
}

void Course::setCourse(string name_,int creditHour_)
{
    name=name_;
    creditHour=creditHour_;
}

ostream& operator<<(ostream& output,const Course&c)
{
    output<<"CourseName: "<<c.name<<"  Coursecredit:"<<c.creditHour<<"   CourseScore:"<<c.getScore();
    return output;
}

void Course::printcourse()
{
    cout<<name<<"  "<<creditHour<<"\n";
}
