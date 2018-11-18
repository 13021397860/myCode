#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse()
{
    //ctor
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

ElectiveCourse::ElectiveCourse(const string s, const int h, const char c):Course(s, h)
{
    ElectiveCourse::setGrade(c);
}

int ElectiveCourse::setGrade(const char c)
{
    if(c >= 'A' && c <= 'E')
    {
        grade = c;
        return 1;
    }
    else
        throw MyException(SCORE_INVALID);
}

int ElectiveCourse::getScore()const
{
    switch(grade)
    {
        case 'A': return 95;
        case 'B': return 85;
        case 'C': return 75;
        case 'D': return 65;
        case 'E': return 55;
        default : return 0;
    }
}
