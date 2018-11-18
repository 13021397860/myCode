#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse()
{
    //ctor
}

void ElectiveCourse::setGrade(char gr)
{
    grade=gr;
}

int ElectiveCourse::getScore()
{
    switch(grade)
    {
    case 'A':
    {
        return 95;
        break;
    }
    case 'B':
    {
        return 85;
        break;
    }
    case 'C':
    {
        return 75;
        break;
    }
    case 'D':
    {
        return 65;
        break;
    }
    case 'E':
    {
        return 55;
        break;
    }
    }
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
