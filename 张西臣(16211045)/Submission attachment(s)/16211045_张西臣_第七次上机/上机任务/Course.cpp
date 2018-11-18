#include "Course.h"
#include <iostream>
#include <string>
using namespace std;
Course::Course(const string na,const int credit)
{
    setcoursename(na);
    setcreditHour(credit);
}

Course::~Course()
{
    //dtor
}

string Course::getcoursename() const
{
    return name;
}

int Course::getcreditHour() const
{
    return creditHour;
}

void Course::setcoursename(const string na)
{
    name=na;
}

void Course::setcreditHour(const int credit)
{
    creditHour=credit;
}

ostream&  operator <<(ostream& output, const Course& c)
{
    output<<"course name:"<<c.name<<"  "<<"the credit :"<<c.creditHour<<" the Score: "<<c.getScore()<<"\n";
  return output;
}
