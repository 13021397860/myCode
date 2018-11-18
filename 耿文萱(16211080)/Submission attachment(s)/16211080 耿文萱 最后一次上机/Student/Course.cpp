#include "Course.h"
#include <string>
#include <iostream>
using namespace std;

Course::Course(const string &s,const int x)
{
    setAll(s,x);//ctor
}

ostream& operator << (ostream& out,const Course& d)
{
   out<<"课程名 "<<d.name<<"  学分 "<<d.creditHour<<" 成绩 "<<d.getScore()<<endl;
   return out;
}

void Course::setAll(const string &s,const int x)
{
    name=s;
    creditHour=x;
}

string Course::getCourse()const
{
    return name;
}

int Course::getCreditHour()const
{
    return creditHour;
}

Course::~Course()
{
    //dtor
}
