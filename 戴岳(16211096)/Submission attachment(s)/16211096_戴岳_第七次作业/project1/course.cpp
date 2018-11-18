#include "course.h"
#include <iomanip>
#include <iostream>
using namespace std;
Course::Course()
{
    name="Undefined";
    creditHour=0;
    //ctor
}

Course::Course(string n,int h)
{
    name=n;
    creditHour=h;
}

string Course::getname() const
{
    return name;
}

int Course::getcreditHour() const
{
    return creditHour;
}

void Course::setname(const string n)
{
    name=n;
}

void Course::setcreditHour(const int h)
{
    creditHour=h;
}



ostream& operator<<(ostream& output, const Course& c)
{
    output<<left<<"CourseName:"<<setw(7)<<c.getname()<<"CreditHour:"<<setw(5)<<c.getcreditHour()<<setw(5)<<c.getScore();
    return output;
}

Course::~Course()
{
    //dtor
}
