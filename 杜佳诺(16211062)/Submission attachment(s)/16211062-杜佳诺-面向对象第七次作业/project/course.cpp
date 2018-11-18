#include "course.h"
#include <iostream>
#include <iomanip>
using namespace std;

Course::Course( string str, int x )
{
    name = str;
    creditHour = x;
    //ctor
}

Course::~Course()
{
    //dtor
}

string Course::getName()
{
    return name;
}

int Course::getCreditHour()
{
    return creditHour;
}

ostream &operator<<( ostream &output, const Course &cou )
{
    output<<"CourseName:"<<setw(12)<<left<<cou.name<<setfill(' ')<<"Credit:"<<setw(6)<<left<<cou.creditHour<<setfill(' ')<<"Grade:"<<cou.getScore();
    return output;
}
