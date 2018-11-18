#include "ElectiveCourse.h"
#include "Course.h"
ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

int ElectiveCourse::setgrade(char g)
{
    grade=g;
    return 1;
}
int ElectiveCourse::getScore() const
{
    if(grade == 'A')
    {
        return 95;
    }
    else if(grade =='B')
    {
        return 85;
    }
    else if(grade =='C')
    {
        return 75;
    }
    else if(grade =='D')
    {
        return 65;
    }
    else if(grade =='E')
    {
        return 55;
    }
    else
    {
        return 0;
    }
}
