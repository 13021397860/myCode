#include "Course.h"
#include<iostream>
#include<iomanip>
using namespace std;

Course::Course(string s, int hour)
{
    setName(s);
    setCreditHour(hour);
}

Course::~Course()
{
    //dtor
}

void Course::setName(string n)
{
    name=n;
}

void Course::setCreditHour(int hour)
{
    creditHour=hour;
}

void Course::setCourseType(string type)
{
    CourseType=type;
}

ostream& operator<<(ostream& os,Course& p)
{
    os<<left<<"Course name: "<<p.name<<"    CreditHour: "<<p.creditHour<<"    Score: "<<right<<p.getScore()
      <<"    CourseType: "<<p.getCourseType()<<endl;
    return os;
}
