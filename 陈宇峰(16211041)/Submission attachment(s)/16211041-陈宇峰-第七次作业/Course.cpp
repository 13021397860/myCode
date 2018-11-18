#include "Course.h"
#include <iostream>
#include <iomanip>
using namespace std;

Course::Course()
{

}

Course::Course(const string _name,const int _creditHour)
{
    name=_name;
    creditHour=_creditHour;
}

Course::~Course()
{
    //dtor
}

string Course::getname() const
{
    return name;
}

int Course::getcreditHour() const
{
    return creditHour;
}

void Course::setname(const string aname)
{
    name=aname;
}

void Course::setcreditHour(const int acreditHour)
{
    creditHour=acreditHour;
}

ostream& operator<<(ostream& output, const Course& course)
{
    output<<setw(36)<<left<<course.name<<"("<<course.creditHour<<" credit hour) : "<<course.getScore();
}
