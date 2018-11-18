
using namespace std;
#include "ElectiveCourse.h"
#include "MyException.h"
ElectiveCourse::ElectiveCourse()
{
    //ctor
}

void ElectiveCourse::setScore(const int g)
{
    if(g==95)
        grade = 'A';
    else if(g == 85)
        grade = 'B';
    else if(g == 75)
        grade = 'C';
    else if(g == 65)
        grade = 'D';
    else if(g == 55)
        grade = 'E';
    else
        throw MyException(SCORE_ILLEGAL);
}

int ElectiveCourse::getScore() const
{
    switch (grade)
    {
    case 'A':
        return 95;
    case 'B':
        return 85;
    case 'C':
        return 75;
    case 'D':
        return 65;
    case 'E':
        return 55;
    default:
        return 0;
    }
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
