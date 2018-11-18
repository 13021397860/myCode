#include "ElectiveCourse.h"
#include <iostream>
using namespace std;

ElectiveCourse::ElectiveCourse(const string &s,const int x,const char c)
:Course(s,x)
{
    setGrade(0,c);//ctor
}

void ElectiveCourse::setGrade(const int n,const char c)
{
    grade=c;
}

int ElectiveCourse::getScore() const
{
    switch(grade)
    {
	case 'A': return 95;
	case 'B': return 85;
	case 'C': return 75;
	case 'D': return 65;
	case 'E': return 55;
	default: return 0;
	}

}

void ElectiveCourse::print1()
{

    cout<<getScore()<<endl;
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
