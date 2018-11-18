#include "electivecourse.h"
#include "Myexception.h"
#include <iostream>

ElectiveCourse::ElectiveCourse()
{
    grade='#';
}

void ElectiveCourse::setgrade(const char _grade)
{
    if (!(_grade>='A'&&_grade<='E'))
        throw MyException(SCORE_INVALID);
    grade=_grade;
}

int ElectiveCourse::getScore() const
{
    int score;
    if (grade=='#')
        score=0;
    else
        score=95+10*('A'-grade);
    return score;
}

