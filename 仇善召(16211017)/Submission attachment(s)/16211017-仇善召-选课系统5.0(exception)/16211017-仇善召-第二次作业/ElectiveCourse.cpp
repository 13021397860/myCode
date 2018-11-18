#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse( string a, int b,char c)
{
    name = a;
    creditHour = b ;
    grade = c; //ctor
}

void ElectiveCourse::setScore( int a)
{
    if ( a>= 95 )
    {
        grade = 'A';
        return ;
    }
    else if ( a>=85 )
    {
        grade = 'B';
        return ;
    }
    else if ( a>=75 )
    {
        grade = 'C';
        return ;
    }
    else if ( a>=65 )
    {
        grade = 'D';
        return ;
    }
    else if ( a>=55 )
    {
        grade = 'E';
        return ;
    }
    else return ;
}

int ElectiveCourse::getScore()const
{
    if ( grade == 'A')
        return 95;
    else if ( grade == 'B')
        return 85;
    else if ( grade == 'C')
        return 75;
    else if ( grade == 'D')
        return 65;
    else if ( grade == 'E')
        return 55;
    else return 0;
}
string ElectiveCourse::toString() const
{
    return name;
}
ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
