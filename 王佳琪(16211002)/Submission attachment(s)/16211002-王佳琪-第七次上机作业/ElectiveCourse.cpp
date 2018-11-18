#include "ElectiveCourse.h"

/*
ElectiveCourse::ElectiveCourse(int g)
{
	setScore(g);
}

ElectiveCourse::~ElectiveCourse(){}
*/

void ElectiveCourse::setScore(const int g)
{
	if(g>=90) grade = 'A';
	else if(g>=80) grade = 'B';
	else if(g>=70) grade = 'C';
	else if(g>=60) grade = 'D';
	else  grade = 'E';
}

int ElectiveCourse::getScore() const 
{
	switch(grade)
	{
		case 'A':
			return 95;
			break;
			
		case 'B':
			return 85;
			break;
			
		case 'C':
			return 75;
			break;
			
		case 'D':
			return 65;
			break;
			
		case 'E':
			return 55;
			break;
			
		default:break;
	}
}

