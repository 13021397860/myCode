#include "ElectiveCourse.h"
#include <iostream>

using namespace std;

static int score[ 5 ] = { 95, 85, 75, 65, 55 };

ElectiveCourse::ElectiveCourse(string n,int c,char m):Course(n,c)
{
    //ctor
    grade = m;
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

void ElectiveCourse::setGrade(char g)
{
    if( g >= 'A' && g <= 'E' )
    {
        grade = g;
    }
    else
    {
        throw IllegalGrade();
    }
}

int ElectiveCourse::getScore()const
{
    return score[ grade - 'A' ];
}

void ElectiveCourse::printScore()const
{
    cout << score[ grade - 'A' ] << endl;
}
