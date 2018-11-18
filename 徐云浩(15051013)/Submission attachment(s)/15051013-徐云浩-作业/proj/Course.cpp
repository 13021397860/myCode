#include "Course.h"

Course::Course()
{
    //ctor
}

Course::~Course()
{
    //dtor
}

void Course::setHour(float a)
{
    creditHour = a;
}

void Course::setName(string a)
{
    name = a;
}

float Course::getHour()const{
    return creditHour;
}

string Course::getName()const{
    return name;
}
