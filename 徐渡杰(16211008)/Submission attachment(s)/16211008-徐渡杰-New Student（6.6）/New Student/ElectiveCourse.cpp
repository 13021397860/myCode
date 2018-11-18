#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse(string A,double cH,int t,char s):Course(A,cH,2)
{
    setScore(s);
    //ctor
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

void ElectiveCourse::setScore(char s)
{
    grade=s;
}

double ElectiveCourse::getScore()
{
    if(grade=='A')
        return 95;
    else if(grade=='B')
        return 85;
    else if(grade=='C')
        return 75;
    else if(grade=='D')
        return 65;
    else if(grade=='F')
        return -1;
    else
        return 55;
}
