#include "ElectiveCourse.h"
#include<iostream>
#include "Course.h"
#include<cstring>
using namespace std;


void ElectiveCourse::setGrade(char g)
{
    grade=g;
}

int ElectiveCourse::getScore() const
{
    if (grade=='A') return 95;
    else if (grade=='B') return 85;
    else if (grade=='C') return 75;
    else if (grade=='D') return 65;
    else if (grade=='E') return 55;
    else return 0;
}
ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
