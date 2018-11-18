#include "Course.h"
#include<iostream>
using namespace std;

Course::Course(string na,int credit)
{
    setName(na);
    setCreditHour(credit);
}
void Course::setName(string na)
{
    name=na;
}
void Course::setCreditHour(int credit)
{
    creditHour=credit;
}
string Course::getName()const
{
    return name;
}
int Course::getCreditHour()const
{
    return creditHour;
}
void Course::setScore(int a)
{
    score=a;
}
Course::~Course()
{
    //dtor
}
