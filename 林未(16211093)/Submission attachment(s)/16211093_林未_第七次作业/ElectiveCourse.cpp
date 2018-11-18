#include "ElectiveCourse.h"
#include "GradeException.h"

ElectiveCourse::ElectiveCourse(string courseName, int credit, char _grade)
:Course(courseName, credit), grade(_grade)
{
	
}

ElectiveCourse &ElectiveCourse::setGrade(const char _grade)
{
	if(_grade > 'E' || _grade < 'A')
		throw GradeException();
	grade = _grade;
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
		default: return -1;
	}
}

ElectiveCourse::~ElectiveCourse()
{
	
}
