#include "ElectiveCourse.h"
#include "Course.h"
#include <iostream>
#include <cstring>
using namespace std;
ElectiveCourse::ElectiveCourse(const string &coursename,int coursehour,char coursegrade):Course(coursename,coursehour)
{
	setgrade(coursegrade);
}
void ElectiveCourse::setgrade(char coursegrade)
{
	grade=coursegrade;
}
int ElectiveCourse::getScore()
{
	if (grade=='A')
		return 95;
	else if (grade=='B')
		return 85;
	else if (grade=='C')
		return 75;
	else if (grade=='D')
		return 65;
	else if (grade=='E')
		return 55;
	else
		return 0;
		
}
