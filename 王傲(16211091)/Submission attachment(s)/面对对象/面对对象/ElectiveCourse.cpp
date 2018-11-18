#include "course.h"
#include "electiveCourse.h"

ElectiveCourse::ElectiveCourse(const string& _courseName,char _grade,int _creditHour)
:Course(_courseName, _creditHour)
{
	setGrade(_grade);
}

void ElectiveCourse::setGrade(char _grade)
{
	grade=_grade;
}

char ElectiveCourse::getGrade() const
{
	return grade; 
} 

int ElectiveCourse::getScore()
{
	if(grade=='A') return 95;
	if(grade=='B') return 85;
	if(grade=='C') return 75;
	if(grade=='D') return 65;
	if(grade=='E') return 55;
	else return 1;
}
