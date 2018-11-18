#include "course.h"

Course::Course(string n,int c)
{
    name=n;
    creditHour=c;
}
Course::Course(const Course &a)
{
    this->name=a.name;
    this->creditHour=a.creditHour;
}
Course::~Course()
{
    //dtor
}
