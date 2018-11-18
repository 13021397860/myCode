#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse()
{
    //ctor
    grade='A';
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

void ElectiveCourse::setGrade(char _grade)
{
    grade=_grade;
}

int ElectiveCourse::getScore() const
{
    switch(grade){
case 'A':
    return 95;
    break;
case 'B':
    return 85;
    break;
case 'C':
    return 75;
    break;
case 'D':
    return 65;
    break;
case 'E':
    return 55;
    break;
    }
    return 0;
};
