#include "ElectiveCourse.h"
#include "Course.h"

ElectiveCourse::ElectiveCourse(const char& m,const string& n,int l):Course(n,l)
{
    grade=m;
}

void ElectiveCourse::setScore(int score,const char& k)
{
    grade=k;
}

 int ElectiveCourse::getScore()const
{
    if(grade=='A')
        return 95;
    else if(grade=='B')
        return 85;
    else if(grade=='C')
        return 75;
    else if(grade=='D')
        return 65;
    return 55;
}

int ElectiveCourse::print()const
{
    cout<<getScore()<<endl;
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
