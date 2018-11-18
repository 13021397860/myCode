#include "electivecourse.h"
#include <iomanip>
using namespace std;

ElectiveCourse::ElectiveCourse()
{
    grade='A';
    //ctor
}

ElectiveCourse::ElectiveCourse(const string n,const int h):Course(n,h)
{
    grade='A';
}

ElectiveCourse::ElectiveCourse(const string n,const int h,char x):Course(n,h)
{
    grade=x;
}

void ElectiveCourse::setScore(const char g)
{
    grade=g;
}

int ElectiveCourse::getScore()const
{
    if(grade=='A')return 95;
    else if(grade=='B')return 85;
    else if(grade=='C')return 75;
    else if(grade=='D')return 65;
    else if(grade=='E')return 55;
    return 0;
}



ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
