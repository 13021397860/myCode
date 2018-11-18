#include "course.h"
#include<string.h>
Course::Course()
{
    //ctor
}

Course::~Course()
{
    //dtor
}

void Course::setName(const string &s)
{
    name=s;
}

void Course::setCreditCard(const int credit)
{
    creditHour=credit;
}
string Course::getName()
{
    return name;
}

int Course::getCreditHour()
{
    return creditHour;
}

void Course:: setMark(int x)
{
    return ;
}
void Course:: setGrade(char z)
{
    return ;
}



