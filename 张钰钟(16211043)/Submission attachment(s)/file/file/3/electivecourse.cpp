#include "electivecourse.h"

ElectiveCourse::ElectiveCourse()
{
    //ctor
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
void ElectiveCourse::setGrade(const char g)
{
    grade=g;
}

int ElectiveCourse::getScore()
{
    switch(grade)
    {
        case 'A':return 95;
        case 'B':return 85;
        case 'C':return 75;
        case 'D':return 65;
        case 'E':return 55;
        default:return 0;
    }
}
