#include "Course.h"
#include <iostream>

using namespace std;

Course::Course( string n, int c )
{
    //ctor
    name = n;
    creditHour = c;
}

Course::~Course()
{
    //dtor
}

void Course::setName( string n )
{
    name = n;
}

void Course::setCreditHour( int c )
{
    creditHour = c;
}

string Course::getName()const
{
    return name;
}

int Course::getCreditHour()const
{
    return creditHour;
}

ostream& operator<<( ostream &os, Course &c )
{
    os << "课程名：" << c.getName() << " " << "学分：" << c.getCreditHour();
    return os;
}
