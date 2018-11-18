#include "stdafx.h"
#include "ElectiveCourse.h"


ElectiveCourse::ElectiveCourse()
{
}

void ElectiveCourse::setGrade(int a)
{
	grade = a;
}

int ElectiveCourse::getScore()
{
	switch (grade)
	{
	case 'A': {return 95; }
	case'B': {return 85; }
	case'C': {return 75; }
	case'D': {return 65; }
	case'E': {return 55; }
	default:
		break;
	}
	return 0;
}


ElectiveCourse::~ElectiveCourse()
{
}
