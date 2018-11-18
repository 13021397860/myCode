#include "ElectiveCourse.h"
using namespace std;
ElectiveCourse::ElectiveCourse(const string x,int a,char q):Course(x,a)
{
    setGrade(q);
    //ctor
}

ElectiveCourse::ElectiveCourse(const string x,int a):Course(x,a)
{

}

ElectiveCourse::ElectiveCourse(const ElectiveCourse &el):Course(el)
{
    setGrade(el.grade);
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}

bool ElectiveCourse::setGrade(char c)
{
    if((c>='A')&&(c<='E'))
    {
       grade=c;
        return true;
    }
    else
    {
        //grade='\0';
        //return false;
        throw Exception(SCORE_INVALID);
    }
}

int ElectiveCourse::getScore() const
{
    if(grade=='A')
        return 95;
    if(grade=='B')
        return 85;
    if(grade=='C')
        return 75;
    if(grade=='D')
        return 65;
    if(grade=='E')
        return 55;
    else
        return 0;
}
