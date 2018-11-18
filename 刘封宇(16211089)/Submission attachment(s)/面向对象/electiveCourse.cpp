#include "electiveCourse.h"

ElectiveCourse::ElectiveCourse(string courseName, int credit, char g)
:Course(courseName, credit), grade(g)
{
	
}

ElectiveCourse &ElectiveCourse::setGrade(const char g)
{
	grade = g;
	return *this;
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

ElectiveCourse::~ElectiveCourse()
{
	
}
