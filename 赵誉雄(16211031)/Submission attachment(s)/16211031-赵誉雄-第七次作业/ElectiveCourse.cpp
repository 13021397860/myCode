#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse()
{

}

ElectiveCourse::ElectiveCourse(const string theName,const int theCreditHour)
:Course(theName,theCreditHour)
{
	grade = 'F';
}
void ElectiveCourse::setScore(const char score)
{
	grade=score;
}

int ElectiveCourse::O_credit() const
{
	return 0;
}

int ElectiveCourse::if_E() const
{
	return 1;
}

int ElectiveCourse::getScore() const
{
	int s;
	switch(grade)
	{
		case 'A':
			s=95;
			break;
		case 'B':
			s=85;
			break;
		case 'C':
			s=75;
			break;
		case 'D':
			s=65;
			break;
		case 'E':
			s=55;
			break;
		default:
			s=-1;
			break;
	}
	return s;
}
