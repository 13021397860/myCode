#include "electivecourse.h"
#include "course.h"

ElectiveCourse::ElectiveCourse( string str, int cre, char gra, double w ) : Course( str, cre )
{
    grade = gra;
    weight = w;
    //ctor
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

void ElectiveCourse::setGrade( int c )
{
    grade = (char)c;
}

int ElectiveCourse::getScore() const
{
    switch ( grade )
    {
        case 'A' : return 95;
        case 'B' : return 85;
        case 'C' : return 75;
        case 'D' : return 65;
        case 'E' : return 55;
        case 'F' : return -1;
    }
    return 0;
}

double ElectiveCourse::getWeight() const
{
    return weight;
}
