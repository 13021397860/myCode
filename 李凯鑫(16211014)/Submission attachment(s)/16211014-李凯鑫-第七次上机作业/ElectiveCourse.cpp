#include "ElectiveCourse.h"
#include<iostream>
#include"Course.h"
using namespace std;

ElectiveCourse::ElectiveCourse(string cname, int hour, string g):Course(cname, hour)
{
    setGrade(g);
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

void ElectiveCourse::setGrade(string g)
{
    grade = g;
}

int ElectiveCourse::getScore()
{
    if(grade=="A")
        return 95;
    else if(grade=="B")
        return 85;
    else if(grade=="C")
        return 75;
    else if(grade=="D")
        return 65;
    else if(grade=="E")
        return 55;
    else
        return 0;
}
