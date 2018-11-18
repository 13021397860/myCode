#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse()
{
	grade='E';
}

void ElectiveCourse::setScore(const int s)
{
	grade='A'+(95-s)/10;
}

int ElectiveCourse::getScore() const
{
	return 95-(grade-'A')*10; 
}
