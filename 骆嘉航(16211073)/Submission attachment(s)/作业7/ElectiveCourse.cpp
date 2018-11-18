#include <iostream>
#include "ElectiveCourse.h"

using namespace std;

ElectiveCourse::ElectiveCourse():Course()
{
	grade='E';
}

ElectiveCourse::ElectiveCourse(const string &Name,const int &CH,const char &Grade):Course(Name,CH)
{
	grade=Grade;
}

ElectiveCourse::~ElectiveCourse()
{
	
}

void ElectiveCourse::setGrade(const char &Grade)
{
	grade=Grade;
}

int ElectiveCourse::getScore()const
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
}
