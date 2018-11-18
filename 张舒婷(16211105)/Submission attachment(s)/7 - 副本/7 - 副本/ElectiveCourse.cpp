#include "ElectiveCourse.h"
#include "MyException.h"

ElectiveCourse::ElectiveCourse(string name_,int creditHour_)
    :Course(name_,creditHour_)
{

}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
void ElectiveCourse::setgrade(char grade_)
{
    if((grade_>='A') && (grade_<='E'))
        grade=grade_;
    else
        throw MyException(RANGE_INVALID);
}

int ElectiveCourse::getScore() const
{
    if(grade=='A')
        return 95;
    else if(grade=='B')
        return 85;
    else if(grade=='C')
        return 75;
    else if(grade=='D')
        return 65;
    else if(grade=='E')
        return 55;
    else
        return 0;
}
